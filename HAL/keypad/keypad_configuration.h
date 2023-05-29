/*
 * keypad_configuration.h
 *
 *  Created on: Mar 31, 2023
 *      Author: ss210
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIGURATION_H_
#define HAL_KEYPAD_KEYPAD_CONFIGURATION_H_

#define KEYPAD_rows		4
#define KEYPAD_columns	3

unsigned char keypad[4][3] ={
							  {'1','2','3'},
							  {'4','5','6'},
							  {'7','8','9'},
							  {'*','0','='}
											};

#endif /* HAL_KEYPAD_KEYPAD_CONFIGURATION_H_ */
