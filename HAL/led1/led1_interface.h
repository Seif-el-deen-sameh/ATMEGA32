/*
 * led1_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_LED1_LED1_INTERFACE_H_
#define HAL_LED1_LED1_INTERFACE_H_

#include "led1_private.h"

void LED1_Initialize(void);
void LED1_ON(void);
void LED1_OFF(void);
void LED1_TGL(void);
#endif /* HAL_LED1_LED1_INTERFACE_H_ */
