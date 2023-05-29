/*
 * Servo_motor_program.c
 *
 *  Created on: Apr 9, 2023
 *      Author: ss210
 */
#include "DIO_Interface.h"
#include "Timer1_interface.h"
#include "Servo_motor_private.h"
#include <util/delay.h>
#include "bit_math.h"
#include "std_types.h"

void Servo_motor_initalize(void){
	DIO_SetPin_Direction(Servo_motor_port,Servo_motor,Servo_motor_OUT);
	//set mode
	clr_bit(TCCR1A,0);
	set_bit(TCCR1A,1);
	set_bit(TCCR1B,3);
	set_bit(TCCR1B,4);
	//set interved
	clr_bit(TCCR1A,6);
	set_bit(TCCR1A,7);
	// set preload
	ICR1=20000;
	//set prescalar
	clr_bit(TCCR1B,0);
	set_bit(TCCR1B,1);
	clr_bit(TCCR1B,2);
}
void Servo_motor_set_angle(u8 angle){
	OCR1A=(angle* 10)+750;
}
void Servo_motor_sweep_range(u8 start_angle,u8 end_angle){
	for(u8 angle=start_angle;angle<=end_angle;angle++)
	{
		OCR1A=(angle* 10)+750;
		_delay_ms(5);
	}
}

