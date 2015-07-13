/*
 * Iceman - 2015
 */

#ifndef INERTIAL_H_
#define INERTIAL_H_


//Uses pins E0, E1, E2 as ADCs
#define X_ADC_PIN ADC_CTL_CH3 //E0
#define Y_ADC_PIN ADC_CTL_CH2 //E1
#define Z_ADC_PIN ADC_CTL_CH1 //E2

int xInitializeInertialDriver();
void vInertialDriverTask();

#endif /* INERTIAL_H_ */
