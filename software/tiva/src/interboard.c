/*
 * Iceman - 2015
 *
 * interboard connection driver source
 */

#include <stdint.h>
#include <stdbool.h>
#include "interboard.h"
#include "task.h"
#include "control.h"
#include "utils/uartstdio.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "driverlib/rom_map.h"
#include "driverlib/uart.h"
#include "driverlib/gpio.h"


//EventGroupHandle_t pollingFlags;
xSemaphoreHandle pollSonarSem;
xSemaphoreHandle pollTempSem;
xSemaphoreHandle pollLightSem;
xSemaphoreHandle pollBumpersSem;
xSemaphoreHandle pollAccelSem;
xSemaphoreHandle pollSoundSem;
xSemaphoreHandle pollBatterySem;
xSemaphoreHandle newCommandSem;

char data[8];
int index;

SensorPacket outputBuffer;

CommandPacket inputBuffer;


void vInterboardISR()
{
	portBASE_TYPE xHigherPriorityTaskWoken;
	int ui32Status = ROM_UARTIntStatus(UART0_BASE, true);
	ROM_UARTIntClear(UART0_BASE, ui32Status);

	// Loop while there are characters in the receive FIFO
	while(ROM_UARTCharsAvail(UART0_BASE))
	{
		// Read the next character from the UART and store it.
		data[index] = ROM_UARTCharGetNonBlocking(UART0_BASE);
		index++;
	}

	int i;
	for (i = 0; i < index; i+=2)
	{
		switch (data[i])
		{
		case MSG_PAUSE:
			//inputBuffer.pause = (inputBuffer.pause ? 0 : 1);
			if (data[i+1] < 2)
				inputBuffer.pause = data[i+1];
		break;
		case MSG_MOTOR_L:
			//if (runningMode == RUN_STATE_TIVA) break;
			//runningMode = RUN_STATE_PI_DIRECT;
			//inputBuffer.motorL = (data[i+1] - '0') * 10;
			inputBuffer.motorL = data[i+1];
		break;
		case MSG_MOTOR_R:
			//if (runningMode == RUN_STATE_TIVA) break;
			//runningMode = RUN_STATE_PI_DIRECT;
			//inputBuffer.motorR = (data[i+1] - '0') * 10;
			inputBuffer.motorR = data[i+1];
		break;
		case MSG_FAN:
			inputBuffer.fan = data[i+1];
		break;
		case MSG_OFFSET:
			runningMode = RUN_STATE_PI_SAILOR;
			inputBuffer.sailorOffset = data[i+1];
		break;
		case MSG_SPEED:
			runningMode = RUN_STATE_PI_SAILOR;
			inputBuffer.sailorSpeed = data[i+1];
		break;
		case MSG_MODE:
			//if (data[i+1] == '1') runningMode = RUN_STATE_TIVA;
			//else runningMode = RUN_STATE_PI_DIRECT;
			if (data[i+1] < 3)
				runningMode = data[i + 1];
		break;
		default:
		break;
		}
	}
	data[index] = '\0';

	if (index % 2)
	{
		data[0] = data[index - 1];
		index = 1;
	}
	else
		index = 0;

	xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(newCommandSem, &xHigherPriorityTaskWoken);
	portEND_SWITCHING_ISR(xHigherPriorityTaskWoken);
}

int xInitializeInterboard()
{
	vSemaphoreCreateBinary(pollAccelSem);
	vSemaphoreCreateBinary(pollBumpersSem);
	vSemaphoreCreateBinary(pollLightSem);
	vSemaphoreCreateBinary(pollSonarSem);
	vSemaphoreCreateBinary(pollSoundSem);
	vSemaphoreCreateBinary(pollTempSem);
	vSemaphoreCreateBinary(pollBatterySem);
	vSemaphoreCreateBinary(newCommandSem);

	// Enable the peripherals used by this example.
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
	ROM_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

	//Initialize input buffer values
	inputBuffer.pause = 1;
	inputBuffer.motorR = 1;
	inputBuffer.motorL = 1;
	inputBuffer.sailorSpeed = 0;
	inputBuffer.sailorOffset = 0;
	inputBuffer.fan = 1;


	//
	// Configure GPIO Pins for UART mode.
	//
	ROM_GPIOPinConfigure(GPIO_PA0_U0RX);
	ROM_GPIOPinConfigure(GPIO_PA1_U0TX);
	ROM_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

	//
	// Initialize UART0 for console I/O.
	//
	UARTStdioConfig(0, 9600, MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
			SYSCTL_OSC_MAIN | SYSCTL_USE_PLL |
			SYSCTL_CFG_VCO_480), 120000000));

	// Enable processor interrupts.
	ROM_IntMasterEnable();

	//
	// Enable the UART interrupt.
	//
	ROM_UARTFIFOLevelSet(UART0_BASE, UART_FIFO_TX6_8, UART_FIFO_RX1_8);
//	ROM_IntPrioritySet(INT_UART0, (7 << 5));
	ROM_IntEnable(INT_UART0);
	ROM_UARTIntEnable(UART0_BASE, UART_INT_RX);

	return 0;
}

void vInterboardTask()
{
	int j;
	for (;;)
	{
		if (inputBuffer.pause) {vTaskDelay(15);continue;}

		for (j = 0; j < 10; j++)
		{
			xSemaphoreGive(pollSonarSem);
			vTaskDelay(100);
		}

			xSemaphoreGive(pollLightSem);
			xSemaphoreGive(pollTempSem);
			xSemaphoreGive(pollSoundSem);
			xSemaphoreGive(pollAccelSem);
			xSemaphoreGive(pollBumpersSem);
		xSemaphoreGive(pollBatterySem);

		UARTprintf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",
				outputBuffer.dists[0], outputBuffer.dists[1], outputBuffer.dists[2],
				outputBuffer.dists[3], outputBuffer.dists[4], outputBuffer.dists[5],
				outputBuffer.dists[6], outputBuffer.dists[7],

				outputBuffer.tempL, outputBuffer.tempR,
				outputBuffer.lightR, outputBuffer.lightG, outputBuffer.lightB,
				outputBuffer.accelX, outputBuffer.accelY, outputBuffer.accelZ,

				outputBuffer.audioL[0],outputBuffer.audioL[1],outputBuffer.audioL[2],
				outputBuffer.audioL[3],outputBuffer.audioL[4],outputBuffer.audioL[5],
				outputBuffer.audioL[6],
				outputBuffer.audioR[0],outputBuffer.audioR[1],outputBuffer.audioR[2],
				outputBuffer.audioR[3],outputBuffer.audioR[4],outputBuffer.audioR[5],
				outputBuffer.audioR[6],

				outputBuffer.bumpLeft, outputBuffer.bumpRearLeft, outputBuffer.bumpRearRight, outputBuffer.bumpRight,
				outputBuffer.battery);


//		UARTprintf("Sonars: %03d\t%03d\t%03d\t%03d\t%03d\t%03d\t%03d\t%03d\n",
//				outputBuffer.dists[0], outputBuffer.dists[1], outputBuffer.dists[2],
//				outputBuffer.dists[3], outputBuffer.dists[4], outputBuffer.dists[5],
//				outputBuffer.dists[6], outputBuffer.dists[7]);
//		UARTprintf("Sounds (L,R): (%03d,%03d)\t(%03d,%03d)\t(%03d,%03d)\t(%03d,%03d)\t(%03d,%03d)\t(%03d,%03d)\t(%03d,%03d)\n",
//				outputBuffer.audioL[0],outputBuffer.audioR[0],outputBuffer.audioL[1],outputBuffer.audioR[1],
//				outputBuffer.audioL[2],outputBuffer.audioR[2],outputBuffer.audioL[3],outputBuffer.audioR[3],
//				outputBuffer.audioL[4],outputBuffer.audioR[4],outputBuffer.audioL[5],outputBuffer.audioR[5],
//				outputBuffer.audioL[6],outputBuffer.audioR[6]);
//		UARTprintf("Colors: %03d\t%03d\t%03d\tAccels: %03d\t%03d\t%03d\tTemp: (%03d,%03d)\tBumpers: (%03d)\n", outputBuffer.lightR,
//				outputBuffer.lightG, outputBuffer.lightB, outputBuffer.accelX, outputBuffer.accelY, outputBuffer.accelZ,
//				outputBuffer.tempL, outputBuffer.tempR, outputBuffer.bumpLeft);
		//vTaskDelay(25);

	}
}
