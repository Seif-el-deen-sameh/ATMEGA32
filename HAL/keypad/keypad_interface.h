/*
 * keypad_interface.h
 *
 *  Created on: Mar 31, 2023
 *      Author: ss210
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_
#include "keypad_private.h"
void KEYPAD_Initialize(void);
u8 KEYPAD_GetKeyPressed(void);

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
