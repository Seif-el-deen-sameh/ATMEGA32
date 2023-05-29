/*
 * LCD_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */
#include "LCD_interface.h"
#include "LCD_configuration.h"
#include "DIO_Interface.h"
#include <util/delay.h>
#include "std_types.h"
void LCD_init(void){
#if   (mode == _8_bit)
	DIO_SetPort_Direction(DIO_PORTA,DIO_PORT_HIGH);
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	_delay_ms(20);
	LCD_command (0x38);	/* Initialization of 16X2 LCD in 8bit mode */
	LCD_command (0x0C);	/* Display ON Cursor OFF */
	LCD_command (0x06);	/* Auto Increment cursor */
	LCD_command (0x80);	/* cursor at home position */
#elif (mode == _4_bit)
	DIO_SetPort_Direction(DIO_PORTA,DIO_PORT_HIGH);
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN1,DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN2,DIO_OUTPUT);
	DIO_SetPin_Direction(DIO_PORTB,DIO_PIN3,DIO_OUTPUT);
	_delay_ms(20);
	LCD_command(0x33);
	LCD_command(0x32);	/* Send for 4 bit initialization of LCD  */
	LCD_command(0x28);	/* 2 line, 5*7 matrix in 4-bit mode */
	LCD_command(0x0c);	/* Display on cursor off */
	LCD_command(0x06);	/* Increment cursor (shift cursor to right) */
#endif
}

void LCD_command(u8 c){
#if   (mode == _8_bit)
	DIO_SetPort_Value(DIO_PORTA,c);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN1,DIO_LOW); //pin1 rs
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN2,DIO_LOW); //pin2 rw
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_HIGH);//pin3 e
	_delay_us(100);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_LOW);
#elif (mode == _4_bit)
	PORTA = (PORTA & 0x0F) | (c & 0xF0);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN1,DIO_LOW); //pin1 rs
	//DIO_SetPin_Value(DIO_PORTB,DIO_PIN2,DIO_LOW); //pin2 rw
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_HIGH);//pin3 e
	_delay_us(100);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_LOW);
	_delay_us(100);
	PORTA  = (PORTA  & 0x0F) | (c << 4);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN1,DIO_LOW); //pin1 rs
	//DIO_SetPin_Value(DIO_PORTB,DIO_PIN2,DIO_LOW); //pin2 rw
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_HIGH);//pin3 e
	_delay_us(100);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_LOW);
#endif
}



void LCD_Char(u8 c){
#if   (mode == _8_bit)
	DIO_SetPort_Value(DIO_PORTA,c);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN1,DIO_HIGH);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN2,DIO_LOW);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_HIGH);
	_delay_us(100);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_LOW);
#elif (mode == _4_bit)
	PORTA = (PORTA & 0x0F) | (c & 0xF0);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN1,DIO_HIGH); //pin1 rs
	//DIO_SetPin_Value(DIO_PORTB,DIO_PIN2,DIO_LOW); //pin2 rw
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_HIGH);//pin3 e
	_delay_us(100);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_LOW);
	_delay_us(100);
	PORTA  = (PORTA  & 0x0F) | (c << 4);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN1,DIO_HIGH); //pin1 rs
	//DIO_SetPin_Value(DIO_PORTB,DIO_PIN2,DIO_LOW); //pin2 rw
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_HIGH);//pin3 e
	_delay_us(100);
	DIO_SetPin_Value(DIO_PORTB,DIO_PIN3,DIO_LOW);
#endif
}


void LCD_send_string(u8 arr[]){
	u8 i=0;
	while(arr[i]!='\0'){
		LCD_Char(arr[i]);
		i++;
	}

}

void LCD_clr(void){
	LCD_command (0x01);	// clear display 8 bit mode
}
void LCD_Char_new (u8 location, u8 *new_char)
{
	u8 i;
	if(location<8)
	{
		LCD_command (0x40 + (location*8));	// Command 0x40 and onwards forces the device to point CGRAM address
		for(i=0;i<8;i++)	            // Write 8 byte for generation of 1 character
		LCD_Char(new_char[i]);
	}
}
void LCD_newln(void){
	LCD_command(0xc0);
}
void LCD_cusor_home(void){
	LCD_command(0x80);
}
