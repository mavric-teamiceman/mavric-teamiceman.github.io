/*
 * Iceman - 2015
 */

#include "smell.h"
#include "interboard.h"
#include "freeRTOS.h"
#include "task.h"
#include <math.h>
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"
#include "utils/uartstdio.h"
#include "driverlib/gpio.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom.h"
#include "driverlib/sysctl.h"

#define min(a,b) (a < b ? a : b)
#define max(a,b) (a > b ? a : b)

#define freqToVal(a) max(((int)(32*log(120000000 / a) - 230)), 0)

int xInitializeSmellDriver()
{
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R11 | SYSCTL_RCGCGPIO_R0;

	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER2);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER3);

	//Enable CCP pins
	ROM_GPIOPinConfigure(GPIO_PA2_T1CCP0);
	ROM_GPIOPinConfigure(GPIO_PA3_T1CCP1);
	ROM_GPIOPinConfigure(GPIO_PM0_T2CCP0);
	ROM_GPIOPinConfigure(GPIO_PM1_T2CCP1);
	ROM_GPIOPinConfigure(GPIO_PM2_T3CCP0);
	ROM_GPIOPinConfigure(GPIO_PA7_T3CCP1);

	ROM_GPIOPinTypeTimer(GPIO_PORTA_BASE, GPIO_PIN_2);
	ROM_GPIOPinTypeTimer(GPIO_PORTA_BASE, GPIO_PIN_3);
	ROM_GPIOPinTypeTimer(GPIO_PORTM_BASE, GPIO_PIN_0);
	ROM_GPIOPinTypeTimer(GPIO_PORTM_BASE, GPIO_PIN_1);
	ROM_GPIOPinTypeTimer(GPIO_PORTM_BASE, GPIO_PIN_2);
	ROM_GPIOPinTypeTimer(GPIO_PORTA_BASE, GPIO_PIN_7);

	TIMER1_CFG_R = 0x04;	//Set as two 16-bit counters
	TIMER2_CFG_R = 0x04;
	TIMER3_CFG_R = 0x04;

	TIMER1_TAMR_R = 0x07;	//Set subTimer A for Edge Time mode
	TIMER1_TBMR_R = 0x07;	//Set subTimer B for Edge Time mode
	TIMER2_TAMR_R = 0x07;
	TIMER2_TBMR_R = 0x07;
	TIMER3_TAMR_R = 0x07;
	TIMER3_TBMR_R = 0x07;

	TIMER1_TAPR_R = 0xFF; //Set prescalers
	TIMER1_TBPR_R = 0xFF;
	TIMER2_TAPR_R = 0xFF;
	TIMER2_TBPR_R = 0xFF;
	TIMER3_TAPR_R = 0xFF;
	TIMER3_TBPR_R = 0xFF;

	TIMER1_TAV_R = 0x0;
	TIMER1_TBV_R = 0x0;
	TIMER2_TAV_R = 0x0;
	TIMER2_TBV_R = 0x0;
	TIMER3_TAV_R = 0x0;
	TIMER3_TBV_R = 0x0;

	TIMER1_CTL_R |= (0x1 << 10); //Configure subTimer B to set on falling edge
	TIMER2_CTL_R |= (0x1 << 10);
	TIMER3_CTL_R |= (0x1 << 10);

	TIMER1_CTL_R |= (1 | 1 << 8); //Enable timers a & b
	TIMER2_CTL_R |= (1 | 1 << 8);
	TIMER3_CTL_R |= (1 | 1 << 8);

	return 0;
}

void vSmellDriverTask()
{
	int a1, a2, a3, b1, b2, b3;
	xSemaphoreTake(pollLightSem, 0);
	for (;;)
	{

		xSemaphoreTake(pollLightSem, portMAX_DELAY);

		taskENTER_CRITICAL(); //Start Critical Section
		a1 = TIMER1_TAR_R;
		b1 = TIMER1_TBR_R;
		a2 = TIMER2_TAR_R;
		b2 = TIMER2_TBR_R;
		a3 = TIMER3_TAR_R;
		b3 = TIMER3_TBR_R;
		taskEXIT_CRITICAL(); //Start Critical Section
		int deltaCycles = abs(a1 - b1);
		//If the difference is too great, assume that the counter reset between measurements
		if (deltaCycles > 0x7FFFFF) deltaCycles = 0xFFFFFF - deltaCycles;
		//UARTprintf("R: %d\t",deltaCycles);
		outputBuffer.lightR = min(freqToVal(deltaCycles),255);

		deltaCycles = abs(a2 - b2);
		//If the difference is too great, assume that the counter reset between measurements
		if (deltaCycles > 0x7FFFFF) deltaCycles = 0xFFFFFF - deltaCycles;
		outputBuffer.lightG = min(freqToVal(deltaCycles),255);
		//UARTprintf("G: %d\t",deltaCycles);

		deltaCycles = abs(a3 - b3);
		//If the difference is too great, assume that the counter reset between measurements
		if (deltaCycles > 0x7FFFFF) deltaCycles = 0xFFFFFF - deltaCycles;
		outputBuffer.lightB = min(freqToVal(deltaCycles),255);//(120000000 / deltaCycles);
		//UARTprintf("B: %d\n",deltaCycles);


		//UARTprintf("R: %d\tG: %d\tB: %d\t\n", freqR, freqG, freqB);
	}
}

