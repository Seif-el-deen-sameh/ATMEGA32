/*
 * stepper_motor_program.c
 *
 *  Created on: Apr 10, 2023
 *      Author: ss210
 */
#include "stepper_motor_configuration.h"
#include "stepper_motor_interface.h"
#include "stepper_motor_private.h"
#include "DIO_Interface.h"
#include "std_types.h"
#include <util/delay.h>

void Stepper_Motor_initalize(void){
		DIO_SetPin_Direction(Stepper_Motor_PRT,Stepper_Motor_PIN_1,Stepper_Motor_OUT);
		DIO_SetPin_Direction(Stepper_Motor_PRT,Stepper_Motor_PIN_2,Stepper_Motor_OUT);
		DIO_SetPin_Direction(Stepper_Motor_PRT,Stepper_Motor_PIN_3,Stepper_Motor_OUT);
		DIO_SetPin_Direction(Stepper_Motor_PRT,Stepper_Motor_PIN_4,Stepper_Motor_OUT);
		DIO_SetPin_Value(Stepper_Motor_PRT,Stepper_Motor_PIN_1,Stepper_Motor_LOW);
		DIO_SetPin_Value(Stepper_Motor_PRT,Stepper_Motor_PIN_2,Stepper_Motor_LOW);
		DIO_SetPin_Value(Stepper_Motor_PRT,Stepper_Motor_PIN_3,Stepper_Motor_LOW);
		DIO_SetPin_Value(Stepper_Motor_PRT,Stepper_Motor_PIN_4,Stepper_Motor_LOW);
}
void Stepper_Motor_stop(void){
	PORTD |= 0b0000;
}
void Stepper_Motor_Rotate_Step(stepper_direction direction){
	switch (direction) {
		case clockwise:
				PORTD |= 0b1001;
				_delay_ms(100);
				PORTD |= 0b1000;
				_delay_ms(100);
				PORTD |= 0b1100;
				_delay_ms(100);
				PORTD |= 0b0100;
				_delay_ms(100);
			break;
		case anti_clockwise:
				PORTD |= 0b1001;
				_delay_ms(100);
				PORTD |= 0b0011;
				_delay_ms(100);
				PORTD |= 0b0110;
				_delay_ms(100);
				PORTD |= 0b1100;
				_delay_ms(100);
			break;
	}
}
void Stepper_Motor_move_multi_Steps(u8 steps,stepper_direction direction){
	switch (direction) {
	case clockwise:
		for(int i=0;i<=steps;i++)
		{
			PORTD |= 0b1001;
			_delay_ms(100);
			PORTD |= 0b1000;
			_delay_ms(100);
			PORTD |= 0b1100;
			_delay_ms(100);
			PORTD |= 0b0100;
			_delay_ms(100);
		}
		break;
	case anti_clockwise:
		for(int i=0;i<=steps;i++)
		{
			PORTD |= 0b1001;
			_delay_ms(100);
			PORTD |= 0b0011;
			_delay_ms(100);
			PORTD |= 0b0110;
			_delay_ms(100);
			PORTD |= 0b1100;
			_delay_ms(100);
		}
		break;
}
}
