/*
 * Servo_notor_interface..h
 *
 *  Created on: Apr 24, 2023
 *      Author: ss210
 */

#ifndef HAL_SERVO_MOTOR_SERVO_NOTOR_INTERFACE__H_
#define HAL_SERVO_MOTOR_SERVO_NOTOR_INTERFACE__H_

void Servo_motor_initalize(void);
void Servo_motor_set_angle(u8 angle);
void Servo_motor_sweep_range(u8 start_angle,u8 end_angle);
#endif /* HAL_SERVO_MOTOR_SERVO_NOTOR_INTERFACE__H_ */
