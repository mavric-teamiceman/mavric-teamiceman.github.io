/*
 *	Iceman - 2015
 *
 *	motor driver header
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "inc/tm4c1294ncpdt.h"
#include <stdbool.h>
#include <stdint.h>
#include "driverlib/gpio.h"
#include "inc/hw_memmap.h"
#include "driverlib/interrupt.h"
#include "driverlib/rom.h"
#include "driverlib/pin_map.h"
#include "driverlib/pwm.h"

//Pin defines
#define MOTOR_L_DIR1_PORT GPIO_PORTL_DATA_R
#define MOTOR_L_DIR1_PIN 0x4 //Pin 2
#define MOTOR_L_DIR2_PORT GPIO_PORTL_DATA_R
#define MOTOR_L_DIR2_PIN 0x8 //Pin 3
#define MOTOR_L_PWM_PORT GPIO_PORTF_AHB_BASE
#define MOTOR_L_PWM_PIN 0x8 //Pin 3

#define MOTOR_R_DIR1_PORT GPIO_PORTL_DATA_R
#define MOTOR_R_DIR1_PIN 0x1 //Pin 0
#define MOTOR_R_DIR2_PORT GPIO_PORTL_DATA_R
#define MOTOR_R_DIR2_PIN 0x2 //Pin 1
#define MOTOR_R_PWM_PORT GPIO_PORTF_AHB_BASE
#define MOTOR_R_PWM_PIN 0x4 //Pin 2


//direction: 0 = forward, 1 = backward, speed from 0-255
void vSetMotorSpeed(uint8_t leftSpeed, uint8_t leftDirection, uint8_t rightSpeed, uint8_t rightDirection);
int xMotorDriverInit();
void vMotorTask();


#endif /* MOTOR_H_ */
