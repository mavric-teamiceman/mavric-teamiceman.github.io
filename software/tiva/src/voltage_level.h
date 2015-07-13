/*
 * Iceman - 2015
 */

#ifndef VOLTAGE_LEVEL_H_
#define VOLTAGE_LEVEL_H_

//Uses ADC module 1, sequence 3 and pin B4

#define VOLTAGE_ENABLE_PIN 0x20

int xVoltageDriverInit();

void vVoltageDriverTask();


#endif /* VOLTAGE_LEVEL_H_ */
