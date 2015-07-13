/*
 * Iceman - 2015
 *
 * autonomous and remote control header
 */

#ifndef CONTROL_H_
#define CONTROL_H_
#include "freeRTOS.h"
#include "task.h"


#define RUN_STATE_TIVA 1
#define RUN_STATE_PI_DIRECT 2
#define RUN_STATE_PI_SAILOR 3


extern int runningMode;

void vControlTask();

#endif /* CONTROL_H_ */
