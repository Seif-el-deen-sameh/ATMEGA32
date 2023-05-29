/*
 * led1_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#include "led1_interface.h"

void LED1_Initialize(void){
	DIO_SetPin_Direction(LED1_PRT,LED1,LED1_OUT);
}
void LED1_ON(void){
	DIO_SetPin_Value(LED1_PRT,LED1,LED1_HIGH);
}
void LED1_OFF(void){
	DIO_SetPin_Value(LED1_PRT,LED1,LED1_LOW);
}
void LED1_TGL(void){
	DIO_TogglePin_Value(LED1_PRT,LED1);
}
