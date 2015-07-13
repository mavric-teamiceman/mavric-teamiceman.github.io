/*
 * Iceman - 2015
 *
 * sonar driver header
 */

#ifndef SONAR_H_
#define SONAR_H_

#include "inc/tm4c1294ncpdt.h"
#include <stdint.h>
#include <stdbool.h>
#include "driverlib/interrupt.h"

#include "interboard.h"


//For S3 S2 S1 bit order
#define SONAR_SEL1_PIN 0x10
#define SONAR_SEL1_PORT GPIO_PORTC_AHB_DATA_R
#define SONAR_SEL2_PIN 0x20
#define SONAR_SEL2_PORT GPIO_PORTC_AHB_DATA_R
#define SONAR_SEL3_PIN 0x40
#define SONAR_SEL3_PORT GPIO_PORTC_AHB_DATA_R
#define SONAR_TRIGGER_PIN 0x8
#define SONAR_TRIGGER_PORT GPIO_PORTB_AHB_DATA_R
#define SONAR_ECHO_PIN 0x4
#define SONAR_ECHO_PORT GPIO_PORTB_AHB_DATA_R

#define TIMEOUTINTERRUPT INT_TIMER5B

//0 is awesome, 1 is FAIL!!!
int xSonarInit();

void vSonarTask( void *pvParameters );

void vSonarTimeoutISR();

#endif /* SONAR_H_ */
