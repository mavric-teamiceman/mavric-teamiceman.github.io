/*
 * Iceman - 2015
 */

#include "inertial.h"
#include "interboard.h"
#include "freeRTOS.h"
#include "task.h"
#include <stdint.h>
#include <stdbool.h>

#include "utils/uartstdio.h"

#include "driverlib/rom.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"


int xInitializeInertialDriver()
{

	//Disable to set
	ROM_ADCSequenceDisable(ADC0_BASE, 2);

	//Use Sequence 2, a 4-value sequence
	ROM_ADCSequenceConfigure(ADC0_BASE, 2, ADC_TRIGGER_PROCESSOR, 0);

	//Pin configures
	ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_0);
	ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_1);
	ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_2);
	GPIO_PORTE_AHB_DEN_R = GPIO_PORTE_AHB_DEN_R & (~0x7);
	GPIO_PORTE_AHB_AMSEL_R |= 0x7;

	//Channels correspond with accelerometer pins
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 0, ADC_CTL_CH3);
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 1, ADC_CTL_CH2 );
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 2, 2, ADC_CTL_CH1 | ADC_CTL_IE | ADC_CTL_END);

	ROM_ADCSequenceEnable(ADC0_BASE, 2);
	ROM_ADCIntClear(ADC0_BASE, 2);

	return 0;
}

void vInertialDriverTask()
{
	uint32_t readings[4];

	xSemaphoreTake(pollAccelSem, 0);
	for (;;)
	{
		xSemaphoreTake(pollAccelSem, portMAX_DELAY);

		// Trigger the ADC conversion.
		ROM_ADCProcessorTrigger(ADC0_BASE, 2);

		// Wait for conversion to be completed.
		while(!ROM_ADCIntStatus(ADC0_BASE, 2, false)) {} //Could swap out for real interrupt

		// Clear the ADC interrupt flag.
		ROM_ADCIntClear(ADC0_BASE, 2);

		// Read ADC Value.
		ROM_ADCSequenceDataGet(ADC0_BASE, 2, readings);

		outputBuffer.accelX = readings[0] / 16;
		outputBuffer.accelY = readings[1] / 16;
		outputBuffer.accelZ = readings[2] / 16;
	}
}
