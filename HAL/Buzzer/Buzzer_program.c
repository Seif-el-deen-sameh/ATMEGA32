/*
 * Buzzer_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#include "Buzzer_interface.h"
#include <util/delay.h>
void Buzzer_Initialize(void){
	DIO_SetPin_Direction(Buzzer_PRT,Buzzer,Buzzer_OUT);
}
void Buzzer_ON(void){
	DIO_SetPin_Value(Buzzer_PRT,Buzzer,Buzzer_HIGH);
}
void Buzzer_OFF(void){
	DIO_SetPin_Value(Buzzer_PRT,Buzzer,Buzzer_LOW);
}
void Buzzer_TGL(void){
	DIO_TogglePin_Value(Buzzer_PRT,Buzzer);
}
void Buzzer_Play_tone_software(Buzzer_Tones tone){
	DIO_SetPin_Value(Buzzer_PRT,Buzzer,Buzzer_HIGH);
	_delay_us(tone);
	DIO_SetPin_Value(Buzzer_PRT,Buzzer,Buzzer_LOW);
	_delay_us(tone);
}
