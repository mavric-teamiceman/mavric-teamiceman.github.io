/*
 * Iceman - 2015
 *
 * motor driver source
 */

#include "motor.h"
#include "FreeRTOS.h"
#include "semphr.h"

uint8_t lSpeed, rSpeed, lDirection, rDirection;
xSemaphoreHandle changeSpeed;

void vSetMotorSpeed(uint8_t leftSpeed, uint8_t leftDirection, uint8_t rightSpeed, uint8_t rightDirection)
{
	lSpeed = leftSpeed;
	rSpeed = rightSpeed;
	lDirection = leftDirection;
	rDirection = rightDirection;
	xSemaphoreGive(changeSpeed);
}

int xMotorDriverInit()
{

	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R10 | SYSCTL_RCGCGPIO_R5;

	vSemaphoreCreateBinary(changeSpeed);

	ROM_GPIOPinTypePWM(MOTOR_L_PWM_PORT, MOTOR_L_PWM_PIN);
	ROM_GPIOPinConfigure(GPIO_PF2_M0PWM2);

	ROM_GPIOPinTypePWM(MOTOR_R_PWM_PORT, MOTOR_R_PWM_PIN);
	ROM_GPIOPinConfigure(GPIO_PF3_M0PWM3);

	GPIO_PORTL_DIR_R |= 0xF;
	GPIO_PORTL_DEN_R |= 0xF;

	PWM0_1_GENA_R = 0x8C;
	PWM0_1_GENB_R = 0x8C;
	ROM_PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_DOWN | PWM_GEN_MODE_GEN_NO_SYNC);
	ROM_PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, 256);
	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 25);
	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, 25);

	ROM_PWMGenEnable(PWM0_BASE, PWM_GEN_1);

	MOTOR_L_DIR1_PORT &= ~MOTOR_L_DIR1_PIN;
	MOTOR_L_DIR2_PORT |= MOTOR_L_DIR2_PIN;
	MOTOR_R_DIR1_PORT &= ~MOTOR_R_DIR1_PIN;
	MOTOR_R_DIR2_PORT |= MOTOR_R_DIR2_PIN;

	PWM0_1_CTL_R |= 0x5;
	PWM0_ENABLE_R |= 0x4 | 0x8;

	return 0;
}

/**
 * Changes the motor speed when the semaphore
 */
void vMotorTask()
{
	xSemaphoreTake(changeSpeed, 0);
	for (;;)
	{
		xSemaphoreTake(changeSpeed, portMAX_DELAY);

		if (lDirection == 0) //Going forward
		{
			MOTOR_L_DIR1_PORT &= ~MOTOR_L_DIR1_PIN;
			MOTOR_L_DIR2_PORT |= MOTOR_L_DIR2_PIN;
		}
		else //Going backward
		{
			MOTOR_L_DIR2_PORT &= ~MOTOR_L_DIR2_PIN;
			MOTOR_L_DIR1_PORT |= MOTOR_L_DIR1_PIN;
		}
		if (rDirection == 0) //Going forward
		{
			MOTOR_R_DIR1_PORT &= ~MOTOR_R_DIR1_PIN;
			MOTOR_R_DIR2_PORT |= MOTOR_R_DIR2_PIN;
		}
		else //Going backward
		{
			MOTOR_R_DIR2_PORT &= ~MOTOR_R_DIR2_PIN;
			MOTOR_R_DIR1_PORT |= MOTOR_R_DIR1_PIN;
		}

		ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, rSpeed);
		ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, lSpeed);
		//PWM write MOTOR_L_PWM_PORT |= MOTOR_L_PWM_PIN
		//PWM write MOTOR_R_PWM_PORT |= MOTOR_R_PWM_PIN
	}
}

