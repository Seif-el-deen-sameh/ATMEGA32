/*
 * stepper_motor_private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_PRIVATE_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_PRIVATE_H_
#include "std_types.h"

#define Stepper_Motor_PIN_1          DIO_PIN0
#define Stepper_Motor_PIN_2          DIO_PIN1
#define Stepper_Motor_PIN_3          DIO_PIN2
#define Stepper_Motor_PIN_4          DIO_PIN3
#define Stepper_Motor_PRT      		 DIO_PORTD
#define Stepper_Motor_OUT      		 DIO_OUTPUT
#define Stepper_Motor_LOW      		 DIO_LOW
#define Stepper_Motor_HIGH     		 DIO_HIGH

typedef enum{
	clockwise=0,
	anti_clockwise=1
}stepper_direction;



#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_PRIVATE_H_ */
