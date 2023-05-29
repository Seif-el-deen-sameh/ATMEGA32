/*
 * motor_driver_program.c
 *
 *  Created on: Apr 9, 2023
 *      Author: ss210
 */
#include "motor_driver_configuration.h"
#include "motor_driver_interface.h"
#include "motor_driver_private.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "std_types.h"
#include "bit_math.h"

void Motor_driver_initalize(){
	DIO_SetPin_Direction(Motor_driver_PRT,Motor_driver_PIN_1,Motor_driver_OUT);
	DIO_SetPin_Direction(Motor_driver_PRT,Motor_driver_PIN_2,Motor_driver_OUT);
	DIO_SetPin_Direction(Motor_driver_PRT,Motor_driver_PIN_3,Motor_driver_OUT);
	DIO_SetPin_Direction(Motor_driver_PRT,Motor_driver_PIN_4,Motor_driver_OUT);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_1,Motor_driver_LOW);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_2,Motor_driver_LOW);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_3,Motor_driver_LOW);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_4,Motor_driver_LOW);
}
void Motor_driver_Start(motor_direction dir){

	switch (dir)
	{
	case Clockwise:
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_1,Motor_driver_LOW);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_2,Motor_driver_LOW);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_3,Motor_driver_LOW);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_4,Motor_driver_LOW);
		_delay_ms(100);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_1,Motor_driver_HIGH);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_3,Motor_driver_HIGH);
	break;
	case Anti_Clockwise:
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_1,Motor_driver_LOW);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_2,Motor_driver_LOW);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_3,Motor_driver_LOW);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_4,Motor_driver_LOW);
		_delay_ms(100);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_2,Motor_driver_HIGH);
		DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_4,Motor_driver_HIGH);
	break;
	}

}
void Motor_driver_Stop(void){
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_1,Motor_driver_LOW);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_2,Motor_driver_LOW);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_3,Motor_driver_LOW);
	DIO_SetPin_Value(Motor_driver_PRT,Motor_driver_PIN_4,Motor_driver_LOW);
}
