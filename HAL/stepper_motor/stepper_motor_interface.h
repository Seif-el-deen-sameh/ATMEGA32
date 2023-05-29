/*
 * stepper_motor_interface.h
 *
 *  Created on: Apr 10, 2023
 *      Author: ss210
 */

#ifndef HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_
#define HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_
#include "stepper_motor_private.h"

void Stepper_Motor_initalize(void);
void Stepper_Motor_stop(void);
void Stepper_Motor_Rotate_Step(stepper_direction direction);
void Stepper_Motor_move_multi_Steps(u8 steps,stepper_direction direction);

#endif /* HAL_STEPPER_MOTOR_STEPPER_MOTOR_INTERFACE_H_ */
