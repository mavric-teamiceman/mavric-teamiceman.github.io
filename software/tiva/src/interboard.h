/*
 * Iceman - 2015
 *
 * interboard connection driver header
 */

#ifndef INTERBOARD_H_
#define INTERBOARD_H_

#include <stdint.h>
#include "FreeRTOS.h"
#include "semphr.h"


//First Byte of Command Messages from PI
#define MSG_PAUSE 0//'p'
#define MSG_MOTOR_L 1//'l'
#define MSG_MOTOR_R 2//'r'
#define MSG_FAN 3
#define MSG_OFFSET 4
#define MSG_SPEED 5
#define MSG_MODE 6//'m'


extern xSemaphoreHandle pollAccelSem;
extern xSemaphoreHandle pollBumpersSem;
extern xSemaphoreHandle pollLightSem;
extern xSemaphoreHandle pollSonarSem;
extern xSemaphoreHandle pollSoundSem;
extern xSemaphoreHandle pollTempSem;
extern xSemaphoreHandle newCommandSem;
extern xSemaphoreHandle pollBatterySem;


typedef struct SENSPACK {
	uint8_t dists[8];
	uint8_t tempL;
	uint8_t tempR;
	uint8_t lightR;
	uint8_t lightG;
	uint8_t lightB;
	uint8_t accelX;
	uint8_t accelY;
	uint8_t accelZ;
	uint8_t audioL[7];
	uint8_t audioR[7];
	uint8_t bumpRight;
	uint8_t bumpRearRight;
	uint8_t bumpRearLeft;
	uint8_t bumpLeft;
	uint8_t battery;
	//
} SensorPacket;

typedef struct COMPACK {
	uint8_t pause;
	uint8_t motorR;
	uint8_t motorL;
	uint8_t sailorSpeed;
	uint8_t sailorOffset;
	uint8_t fan;
} CommandPacket;

int xInitializeInterboard();
void vInterboardTask();
void vInterboardISR();


extern SensorPacket outputBuffer;

extern CommandPacket inputBuffer;


#endif /* INTERBOARD_H_ */
