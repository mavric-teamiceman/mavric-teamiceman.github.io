/*
 * Iceman - 2015
 *
 * autonomous and remote control source
 */

#include "motor.h"
#include "interboard.h"
#include "control.h"
#include "freeRTOS.h"
#include "task.h"

int runningMode;

extern void vSetFanSpeed(uint8_t speed);

/**
 * Controls the periodic assignment of values to the motors and fan. For demonstration, additional
 * simple autonomous code is included.
 */
void vControlTask()
{
	runningMode = RUN_STATE_TIVA;
	for (;;)
	{
		int k;
		if (inputBuffer.pause == 1)
		{
			vSetMotorSpeed(0x1, 0, 0x1, 0);
			vTaskDelay(25);
			continue;
		}
		switch (runningMode)
		{
		case RUN_STATE_TIVA:
			vSetMotorSpeed(0x3F, 0, 0x3F, 0);
			for (k = 0; k < 4; k++)
			{
				if (outputBuffer.dists[k] < 255)
				{
					vSetMotorSpeed(0x3F, 0, 0x3F, 1);
					break;
				}
				if (outputBuffer.dists[k+4] < 255)
				{
					vSetMotorSpeed(0x3F, 1, 0x3F, 0);
					break;
				}
			}
			xSemaphoreTake(newCommandSem, 400);
			break;
		case RUN_STATE_PI_DIRECT:
			vSetMotorSpeed(inputBuffer.motorL<<1, inputBuffer.motorL>>7, inputBuffer.motorR<<1, inputBuffer.motorR>>7);
			vSetFanSpeed(inputBuffer.fan);
			xSemaphoreTake(newCommandSem, 1000);

			break;
		case RUN_STATE_PI_SAILOR:
			//Wandery stuff
			break;
		default:
			//This is bad...
			break;
		}
		vTaskDelay(50);
	}
}

