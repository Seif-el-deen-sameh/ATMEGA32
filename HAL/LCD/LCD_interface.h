/*
 * LCD_interface.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_LCD_LCD_INTERFACE_H_
#define HAL_LCD_LCD_INTERFACE_H_
#include "std_types.h"
void LCD_init(void);
void LCD_command(u8 c);
void LCD_Char(u8 e);
void LCD_send_string(u8 arr[]);
void LCD_Char_new (u8 location, u8 *new_char);
void LCD_string(u8 *str);
void LCD_clr(void);
void LCD_newln(void);
void LCD_cusor_home(void);

#endif /* HAL_LCD_LCD_INTERFACE_H_ */
