/*
 * Iceman - 2015
 *
 * audio input driver header
 */

#ifndef SOUND_H_
#define SOUND_H_

//Strobe Pin Left M4
//Strobe Pin Right C7
//Reset Pin Left M5
//Reset Pin Right E4
//Data Pin Left E3
//Data Pin Right D3

int xSoundDriverInit();
void vSoundDriverTask(void* pvArgs);


#endif /* SOUND_H_ */
