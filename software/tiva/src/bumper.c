/*
 * Iceman - 2015
 */


#include "bumper.h"
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


int xInitializeBumperDriver()
{

	//Disable to set
	ROM_ADCSequenceDisable(ADC0_BASE, 0);

	//Use Sequence 2, a 4-value sequence
	ROM_ADCSequenceConfigure(ADC0_BASE, 0, ADC_TRIGGER_PROCESSOR, 0);

	//Pin configures
	ROM_GPIOPinTypeADC(GPIO_PORTK_BASE, GPIO_PIN_0);
	ROM_GPIOPinTypeADC(GPIO_PORTK_BASE, GPIO_PIN_1);
	ROM_GPIOPinTypeADC(GPIO_PORTK_BASE, GPIO_PIN_2);
	ROM_GPIOPinTypeADC(GPIO_PORTK_BASE, GPIO_PIN_3);

	//Channels correspond with accelerometer pins
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 0, 0, ADC_CTL_CH16); //K0
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 0, 1, ADC_CTL_CH17); //K1
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 0, 2, ADC_CTL_CH18); //K2
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 0, 3, ADC_CTL_CH19 | ADC_CTL_IE | ADC_CTL_END); //K3

	ROM_ADCSequenceEnable(ADC0_BASE, 0);
	ROM_ADCIntClear(ADC0_BASE, 0);

	return 0;
}

void vBumperDriverTask()
{
	uint32_t readings[4];
	xSemaphoreTake(pollBumpersSem, 0);
	for (;;)
	{
		xSemaphoreTake(pollBumpersSem, portMAX_DELAY);

		// Trigger the ADC conversion.
		ROM_ADCProcessorTrigger(ADC0_BASE, 0);

		// Wait for conversion to be completed.
		while(!ROM_ADCIntStatus(ADC0_BASE, 0, false)) {} //Could swap out for real interrupt

		// Clear the ADC interrupt flag.
		ROM_ADCIntClear(ADC0_BASE, 0);

		// Read ADC Value.
		ROM_ADCSequenceDataGet(ADC0_BASE, 0, readings);

		outputBuffer.bumpLeft = (readings[0] >> 4);
		outputBuffer.bumpRearLeft = (readings[1] >> 4);
		outputBuffer.bumpRearRight = (readings[2] >> 4);
		outputBuffer.bumpRight = (readings[3] >> 4);
	}
}
