/*
 * Iceman - 2015
 */

#include "voltage_level.h"
#include "interboard.h"
#include "freeRTOS.h"
#include "task.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>

#include "driverlib/rom.h"
#include "driverlib/adc.h"
#include "driverlib/gpio.h"
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"

//Macro relating ADC input from voltage sensor to battery level output
#define convert_scale(x) (x & 0xFF)

int xVoltageDriverInit()
{
	ROM_GPIOPinTypeADC(GPIO_PORTB_BASE, GPIO_PIN_4);

	GPIO_PORTB_AHB_DIR_R |= VOLTAGE_ENABLE_PIN;
	GPIO_PORTB_AHB_DEN_R |= VOLTAGE_ENABLE_PIN;

	ROM_ADCSequenceConfigure(ADC1_BASE, 3, ADC_TRIGGER_PROCESSOR, 0);
	//analog input channel 10 = Pin B4
	ROM_ADCSequenceStepConfigure(ADC1_BASE, 3, 0, ADC_CTL_CH10 | ADC_CTL_IE |
			ADC_CTL_END);
	ROM_ADCSequenceEnable(ADC1_BASE, 3);
	ROM_ADCIntClear(ADC1_BASE, 3);
	return 0;
}


/**
 * Polls and stores the scaled voltage value whenever it receives its polling Semaphore.
 */
void vVoltageDriverTask()
{
	uint32_t measurement[1];

	for(;;)
	{
		xSemaphoreTake(pollBatterySem, portMAX_DELAY);

		GPIO_PORTB_AHB_DATA_R |= VOLTAGE_ENABLE_PIN;

		ROM_ADCProcessorTrigger(ADC1_BASE, 3);

		// Wait for conversion to be completed.
		while(!ROM_ADCIntStatus(ADC1_BASE, 3, false)) {}

		// Clear the ADC interrupt flag.
		ROM_ADCIntClear(ADC1_BASE, 3);

		// Read ADC Value.
		ROM_ADCSequenceDataGet(ADC1_BASE, 3, measurement);

		outputBuffer.battery = convert_scale(measurement[0]);

		GPIO_PORTB_AHB_DEN_R &= ~VOLTAGE_ENABLE_PIN;
	}
}

