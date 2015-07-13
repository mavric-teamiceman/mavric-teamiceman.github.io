/*
 * Iceman - 2015
 */

#include "sound.h"
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



int xSoundDriverInit()
{
	//Enable Right Reset
	GPIO_PORTE_AHB_DIR_R |= 0x10;
	GPIO_PORTE_AHB_DEN_R |= 0x10;

	//Enable Left Strobe
	GPIO_PORTC_AHB_DIR_R |= 0x80;
	GPIO_PORTC_AHB_DEN_R |= 0x80;

	//Enable Left Reset & Right Strobe
	GPIO_PORTM_DIR_R |= 0x30;
	GPIO_PORTM_DEN_R |= 0x30;

	ROM_ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
	ROM_GPIOPinTypeADC(GPIO_PORTE_BASE, GPIO_PIN_3);
	ROM_GPIOPinTypeADC(GPIO_PORTD_BASE, GPIO_PIN_3);
	return 0;
}

void vSoundDriverTask(void* pvArgs)
{
	int i;
	uint32_t values[2];

	xSemaphoreTake(pollSoundSem, 0);
	for (;;)
	{
		xSemaphoreTake(pollSoundSem, portMAX_DELAY);

		//Use ADC Sequence 1 - Has 4 Steps
		ROM_ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH0); //E3 - Left Value
		ROM_ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_CH12 | ADC_CTL_IE | //D3 - Right Value
				ADC_CTL_END);
		ROM_ADCSequenceEnable(ADC0_BASE, 1);
		ROM_ADCIntClear(ADC0_BASE, 1);

		//Reset
		GPIO_PORTM_DATA_R |= 0x20;
		GPIO_PORTE_AHB_DATA_R |= 0x10;
		vTaskDelay(1); //Leave High Briefly
		GPIO_PORTM_DATA_R &= ~0x20;
		GPIO_PORTE_AHB_DATA_R &= ~0x10;
		vTaskDelay(1);

		for (i = 0; i < 7; i++) //For all 7 channels
		{
			//Strobe
			GPIO_PORTM_DATA_R |= 0x10;
			GPIO_PORTC_AHB_DATA_R |= 0x80;
			vTaskDelay(1); //Leave High Briefly
			GPIO_PORTM_DATA_R &= ~0x10;
			GPIO_PORTC_AHB_DATA_R &= ~0x80;
			vTaskDelay(1); //Let Signal Settle

			//Begin ADC reading
			ROM_ADCProcessorTrigger(ADC0_BASE, 1);

			// Wait for conversion to be completed.
			while(!ROM_ADCIntStatus(ADC0_BASE, 1, false)) {}

			// Clear the ADC interrupt flag.
			ROM_ADCIntClear(ADC0_BASE, 1);

			// Read ADC Value.
			ROM_ADCSequenceDataGet(ADC0_BASE, 1, values);
			//ROM_ADCSequenceDisable(ADC0_BASE, 3);
			outputBuffer.audioL[i] = values[0]/16;
			outputBuffer.audioR[i] = values[1]/16;
			//UARTprintf("%d: %u  %u\t", i+1, values[0], values[1]);
			vTaskDelay(1);
		}
		//UARTprintf("\n");
	}
}
