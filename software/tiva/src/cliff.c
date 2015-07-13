/*
 * Iceman - 2015
 *
 * cliff driver source
 */

#include "motor.h"
#include "interboard.h"
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_memmap.h"
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"


/**
 * Should be called to enable the Cliff detection interrupt.
 */
int xInitializeCliffDriver()
{
	ROM_GPIOPinTypeGPIOInput(GPIO_PORTA_BASE, GPIO_INT_PIN_6);
	ROM_GPIOIntEnable(GPIO_PORTA_BASE, GPIO_INT_PIN_6);
	ROM_GPIOIntTypeSet(GPIO_PORTA_BASE, GPIO_INT_PIN_6, GPIO_HIGH_LEVEL);
	ROM_IntPendClear(INT_GPIOA);
	ROM_IntPrioritySet(INT_GPIOA,(6 << 5));
	ROM_IntEnable(INT_GPIOA);
	return 0;
}

/**
 * Designed to prevent an unfortunate accident. Briefly drives the robot
 * in reverse when the cliff sensor pin goes HIGH. Must be contained in
 * the startup file's Interrupt Vector Table
 */
void vCliffISR()
{
	int r = ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_2);
	int l = ROM_PWMPulseWidthGet(PWM0_BASE, PWM_OUT_3);

	int l_port1_save = MOTOR_L_DIR1_PORT & MOTOR_L_DIR1_PIN;
	int l_port2_save = MOTOR_L_DIR2_PORT & MOTOR_L_DIR2_PIN;
	int r_port1_save = MOTOR_R_DIR1_PORT & MOTOR_R_DIR1_PIN;
	int r_port2_save = MOTOR_R_DIR2_PORT & MOTOR_R_DIR2_PIN;

	MOTOR_L_DIR2_PORT &= ~MOTOR_L_DIR2_PIN;
	MOTOR_L_DIR1_PORT |= MOTOR_L_DIR1_PIN;
	MOTOR_R_DIR2_PORT &= ~MOTOR_R_DIR2_PIN;
	MOTOR_R_DIR1_PORT |= MOTOR_R_DIR1_PIN;

	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, 0x6F);
	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, 0x6F);

	ROM_SysCtlDelay(4000000); //~100 ms, I think

	PWM0_ENABLE_R &= ~(0x4 | 0x8);

	ROM_GPIOIntClear(GPIO_PORTA_BASE, GPIO_INT_PIN_6);
	ROM_IntPendClear(INT_GPIOA);
	while (GPIO_PORTA_AHB_DATA_R & 0x40);
	PWM0_ENABLE_R |= 0x4 | 0x8;

	MOTOR_L_DIR1_PORT |= l_port1_save;
	MOTOR_L_DIR2_PORT |= l_port2_save;
	MOTOR_R_DIR1_PORT |= l_port1_save;
	MOTOR_R_DIR2_PORT |= r_port2_save;

	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2, r);
	ROM_PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3, l);
}

