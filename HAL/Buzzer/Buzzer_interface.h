/*
 * Buzzer_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_Buzzer_Buzzer_INTERFACE_H_
#define HAL_Buzzer_Buzzer_INTERFACE_H_

#include "Buzzer_private.h"

void Buzzer_Initialize(void);
void Buzzer_ON(void);
void Buzzer_OFF(void);
void Buzzer_TGL(void);
void Buzzer_Play_tone_software(Buzzer_Tones tone);
#endif /* HAL_Buzzer_Buzzer_INTERFACE_H_ */
