/*
 * Iceman - 2015
 *
 * sonar driver source
 */

#include "sonar.h"
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"

/*-------------------------Sonar Driver Code----------------------------------*/

xSemaphoreHandle sonarSem;

int xSonarInit()
{
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R1 | SYSCTL_RCGCGPIO_R2 | SYSCTL_RCGCGPIO_R4;
	SYSCTL_RCGCTIMER_R |= SYSCTL_RCGCTIMER_R5;
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER5);

	GPIO_PORTE_AHB_DIR_R |= (1 << 5);
	GPIO_PORTE_AHB_DEN_R |= (1 << 5);

	GPIO_PORTB_AHB_DIR_R |= (1 << 3);
	GPIO_PORTB_AHB_DEN_R |= (1 << 3);

	GPIO_PORTC_AHB_DIR_R |= (0x7 << 4);
	GPIO_PORTC_AHB_DEN_R |= (0x7 << 4);

	SONAR_TRIGGER_PORT = SONAR_TRIGGER_PORT & ~SONAR_TRIGGER_PIN;

	vSemaphoreCreateBinary(sonarSem);

	/* Timer5A -> CCP Edge Time Mode
	 * Timer5B -> Oneshot Interrupt Timer */

	ROM_GPIOPinConfigure(GPIO_PB2_T5CCP0);
	ROM_GPIOPinTypeTimer(GPIO_PORTB_BASE, GPIO_PIN_2);

	TIMER5_CTL_R = 0;
	TIMER5_CFG_R = 0x4;


	TIMER5_TAPR_R = 8; //Prescale by 4
	TIMER5_TBPR_R = 4; //Prescale by 4

	TIMER5_TAMR_R = 0x07; //Set for edge time mode
	TIMER5_TBMR_R = 0x01; //Set as one-shot timer

	//TIMER5_CTL_R |= (0x0 << 2); //Set for posedge detection
	TIMER5_TBILR_R = 17100; //Interrupt after 570 us

	TIMER5_IMR_R = (1 << 8);	//Enable timeout interrupt for Timer5B
	TIMER5_ICR_R = (0x1 << 8);

	ROM_IntMasterEnable();
	ROM_IntPrioritySet(INT_TIMER5B,(6 << 5));
	NVIC_UNPEND2_R |= 0x4;
	//IntEnable(INT_TIMER5B); //Enable Timer5B Interrupt in NVIC

	return 0;
}

void vSonarTask( void *pvParameters )
{
	uint8_t sonar_order[8] = {1,0,3,2,5,4,7,6};
	int distances[8] = {0,0,0,0,0,0,0,0};
	uint32_t lastValue = 0;
	uint32_t startValue = 0;
	int dif;
	uint8_t currentSonar = 0;
	uint8_t loop;
	//NVIC_EN2_R |= 0x4;
	//TIMER5_CTL_R |= (1);

	ROM_IntEnable(INT_TIMER5B);
	xSemaphoreTake(sonarSem, 0);
	xSemaphoreTake(pollSonarSem, 0);
	for( ;; )
	{
		GPIO_PORTN_DATA_R ^= 0x04;
		xSemaphoreTake(pollSonarSem, portMAX_DELAY);
		GPIO_PORTN_DATA_R ^= 0x04;

		for (loop = 0; loop < 8; loop++)
		{
			//Clear Timers
			TIMER5_TBILR_R = 17100; //Interrupt after 570 us
		//	TIMER5_TBV_R = 0;
			TIMER5_TAV_R = 0x00000;
			TIMER5_ICR_R = (0x1 << 8);

			//Set PIN_SONAR_SEL pins for currentSonar
			if (sonar_order[currentSonar] & 1)
				(SONAR_SEL1_PORT) |= SONAR_SEL1_PIN;
			else
				(SONAR_SEL1_PORT) = ((SONAR_SEL1_PORT) & ~SONAR_SEL1_PIN);

			if (sonar_order[currentSonar] & 2)
				(SONAR_SEL2_PORT) |= SONAR_SEL2_PIN;
			else
				(SONAR_SEL2_PORT) = ((SONAR_SEL2_PORT) & ~SONAR_SEL2_PIN);

			if (sonar_order[currentSonar] & 4)
				(SONAR_SEL3_PORT) |= SONAR_SEL3_PIN;
			else
				(SONAR_SEL3_PORT) = ((SONAR_SEL3_PORT) & ~SONAR_SEL3_PIN);

		//	UARTprintf("Polling Sonar %d\n", currentSonar);

			GPIO_PORTE_AHB_DATA_R &= ~(1 << 5); //Turn off Blanking Inhibit
			taskENTER_CRITICAL(); //Start Critical Section

			SONAR_TRIGGER_PORT |= SONAR_TRIGGER_PIN; //set Trigger HIGH
			//start both Timers
			startValue = TIMER5_TAV_R;
			lastValue = TIMER5_TAR_R;
			TIMER5_CTL_R |= (1 | 1 << 8);
			taskEXIT_CRITICAL(); //Done with timing critical instructions

			xSemaphoreTake(sonarSem, 2); // Picks up to turn on BINH
			GPIO_PORTE_AHB_DATA_R |= (1 << 5);
			TIMER5_CTL_R &= ~(1 << 8);
			TIMER5_TBILR_R = 42200;
			TIMER5_CTL_R |= (1 << 8);
			xSemaphoreTake(sonarSem, 3); // Picks up after timeOut


			TIMER5_CTL_R &= ~(1 << 8);
			TIMER5_CTL_R = 0; //Stop Edge Time Timer (One-shot auto stops)

			SONAR_TRIGGER_PORT = (SONAR_TRIGGER_PORT) & (~SONAR_TRIGGER_PIN); //Clear trigger

			GPIO_PORTE_AHB_DATA_R &= ~(1 << 5); //Turn off Blanking Inhibit

			//If Edge Time Timer Captured Value
			if (TIMER5_TAR_R != lastValue)
			{
				dif = (startValue - TIMER5_TAR_R);
				lastValue = TIMER5_TAR_R;
				if (dif < 0) dif += 0x8FFFF;
				dif = (int)(dif * (17.0 / 20000));
				if (dif < 0) dif = 0;
				if (dif > 255) dif = 255;
				distances[currentSonar] = dif;//255 - (TIMER5_TAR_R&0xFFFF >> 8);
			}
			else
			{
				distances[currentSonar] = 255;
			}

			currentSonar += 5;
			currentSonar %= 8;
			vTaskDelay(1);
		}
		outputBuffer.dists[0] = distances[0];
		outputBuffer.dists[1] = distances[1];
		outputBuffer.dists[2] = distances[2];
		outputBuffer.dists[3] = distances[3];
		outputBuffer.dists[4] = distances[4];
		outputBuffer.dists[5] = distances[5];
		outputBuffer.dists[6] = distances[6];
		outputBuffer.dists[7] = distances[7];
		//UARTprintf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",distances[0],distances[1],distances[2],distances[3],distances[4],distances[5],distances[6],distances[7]);
	}
}

void vSonarTimeoutISR()
{
	portBASE_TYPE xHigherPriorityTaskWoken;
	//UARTprintf("In ISR\n");
	TIMER5_ICR_R = (0x1 << 8);
//	if (TIMER5_TBILR_R == 17100) //Interrupted after 570 us)
//	{
//		GPIO_PORTE_AHB_DATA_R |= (1 << 5);
//		TIMER5_CTL_R &= ~(1 << 8);
//		TIMER5_TBILR_R = 42900;
//		TIMER5_CTL_R |= (1 << 8);
//	}
//	else
//	{
		xHigherPriorityTaskWoken = pdFALSE;
		xSemaphoreGiveFromISR(sonarSem, &xHigherPriorityTaskWoken);
		portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
//	}
}
