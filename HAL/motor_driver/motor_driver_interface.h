/*
 * motor_driver_interface.h
 *
 *  Created on: Apr 9, 2023
 *      Author: ss210
 */

#ifndef HAL_MOTOR_DRIVER_MOTOR_DRIVER_INTERFACE_H_
#define HAL_MOTOR_DRIVER_MOTOR_DRIVER_INTERFACE_H_

#include "motor_driver_private.h"

void Motor_driver_initalize(void);
void Motor_driver_Start(motor_direction dir);
void Motor_driver_Stop(void);

#endif /* HAL_MOTOR_DRIVER_MOTOR_DRIVER_INTERFACE_H_ */
