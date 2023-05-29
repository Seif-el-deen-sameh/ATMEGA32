/*
 * relay_driver_interface.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */

#ifndef HAL_RELAY_DRIVER_RELAY_DRIVER_INTERFACE_H_
#define HAL_RELAY_DRIVER_RELAY_DRIVER_INTERFACE_H_

#include "relay_driver_private.h"

void relay_driver_initalize(void);
void relay_driver_stop(motion m1);
void relay_driver_clockwise(void);
void relay_driver_counter_clockwise(void);

#endif /* HAL_RELAY_DRIVER_RELAY_DRIVER_INTERFACE_H_ */
