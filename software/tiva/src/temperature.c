/*
 * Iceman - 2015
 */

#include "interboard.h"
#include "freeRTOS.h"
#include "task.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

//#include "utils/uartstdio.h"

#include "driverlib/rom.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"



void vTempDriverTask() //Code Credit to Tivaware Example temperature_sensor.c
{
	uint32_t measurement[1];

	uint32_t ui32TempValueC;

	ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_0);
	ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_1);

	ROM_ADCSequenceConfigure(ADC0_BASE, 3, ADC_TRIGGER_PROCESSOR, 0); //D0
	ROM_ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH15 | ADC_CTL_IE |
			ADC_CTL_END);
	ROM_ADCSequenceEnable(ADC0_BASE, 3);
	ROM_ADCIntClear(ADC0_BASE, 3);

	for(;;)
	{

		xSemaphoreTake(pollTempSem, portMAX_DELAY);

		ROM_ADCProcessorTrigger(ADC0_BASE, 3);

		// Wait for conversion to be completed.
		while(!ROM_ADCIntStatus(ADC0_BASE, 3, false)) {}

		// Clear the ADC interrupt flag.
		ROM_ADCIntClear(ADC0_BASE, 3);

		// Read ADC Value.
		ROM_ADCSequenceDataGet(ADC0_BASE, 3, measurement);

		ui32TempValueC = (uint32_t)(log(40960/(29.0*measurement[0]) - 10.0/29) * -1/0.041);

		outputBuffer.tempR = ui32TempValueC;

		//Switch to other Thermistor
		ROM_ADCSequenceDisable(ADC0_BASE, 3);
		ROM_ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH14 | ADC_CTL_IE | //D1
				ADC_CTL_END);
		ROM_ADCSequenceEnable(ADC0_BASE, 3);

		//Begin ADC poll
		ROM_ADCProcessorTrigger(ADC0_BASE, 3);

		// Wait for conversion to be completed.
		while(!ROM_ADCIntStatus(ADC0_BASE, 3, false)) {}

		// Clear the ADC interrupt flag.
		ROM_ADCIntClear(ADC0_BASE, 3);

		// Read ADC Value.
		ROM_ADCSequenceDataGet(ADC0_BASE, 3, measurement);

		ui32TempValueC = (uint32_t)(log(40960/(29.0*measurement[0]) - 10.0/29) * -1/0.041);

		outputBuffer.tempL = ui32TempValueC;

		ROM_ADCSequenceDisable(ADC0_BASE, 3);
		ROM_ADCSequenceStepConfigure(ADC0_BASE, 3, 0, ADC_CTL_CH15 | ADC_CTL_IE |
				ADC_CTL_END);
		ROM_ADCSequenceEnable(ADC0_BASE, 3);
	}

}


