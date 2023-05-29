/*
 * relay_driver_program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */
#include "relay_driver_private.h"
#include "relay_driver_interface.h"
#include "DIO_Interface.h"
void relay_driver_initalize(void){
	DIO_SetPin_Direction(RELAY1_PRT,RELAY1,RELAY1_OUT);
	DIO_SetPin_Direction(RELAY2_PRT,RELAY2,RELAY2_OUT);
}
void relay_driver_stop(motion m1){
	switch(m1){
	case clockwise:
		DIO_SetPin_Value(RELAY2_PRT,RELAY2,RELAY2_LOW);
	break;
	case counter_clockwise:
		DIO_SetPin_Value(RELAY2_PRT,RELAY2,RELAY2_HIGH);
		_delay_ms(50);
		DIO_SetPin_Value(RELAY1_PRT,RELAY1,RELAY1_LOW);
		DIO_SetPin_Value(RELAY2_PRT,RELAY2,RELAY2_LOW);
	break;
	}


}
void relay_driver_clockwise(void){
	DIO_SetPin_Value(RELAY1_PRT,RELAY1,RELAY1_LOW);
	DIO_SetPin_Value(RELAY2_PRT,RELAY2,RELAY2_HIGH);
}
void relay_driver_counter_clockwise(void){
	DIO_SetPin_Value(RELAY1_PRT,RELAY1,RELAY1_HIGH);
	DIO_SetPin_Value(RELAY2_PRT,RELAY2,RELAY2_LOW);
}
