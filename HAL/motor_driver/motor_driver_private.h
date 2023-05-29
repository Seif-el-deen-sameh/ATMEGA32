/*
 * motor_driver_private.h
 *
 *  Created on: Apr 9, 2023
 *      Author: ss210
 */

#ifndef HAL_MOTOR_DRIVER_MOTOR_DRIVER_PRIVATE_H_
#define HAL_MOTOR_DRIVER_MOTOR_DRIVER_PRIVATE_H_

#include "DIO_Private.h"

#define Motor_driver_PIN_1          DIO_PIN3
#define Motor_driver_PIN_2          DIO_PIN4
#define Motor_driver_PIN_3          DIO_PIN5
#define Motor_driver_PIN_4          DIO_PIN6
#define Motor_driver_PRT      		DIO_PORTC
#define Motor_driver_OUT      		DIO_OUTPUT
#define Motor_driver_LOW      		DIO_LOW
#define Motor_driver_HIGH     		DIO_HIGH

typedef enum{
	Clockwise=0,
	Anti_Clockwise=1
}motor_direction;

#endif /* HAL_MOTOR_DRIVER_MOTOR_DRIVER_PRIVATE_H_ */
