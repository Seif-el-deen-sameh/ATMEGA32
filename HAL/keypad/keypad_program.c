/*
 * keypad_program.c
 *
 *  Created on: Mar 31, 2023
 *      Author: ss210
 */
#include "DIO_Interface.h"
#include <util/delay.h>
#include "std_types.h"
#include "keypad_interface.h"
#include "keypad_configuration.h"
#include "keypad_private.h"


void KEYPAD_Initialize(void){

	// define rows as output where (KEYPAD_rows-KEYPAD_rows)=0 and (KEYPAD_rows-1)=3
   for(u8 i=(KEYPAD_rows-KEYPAD_rows);i<=(KEYPAD_rows-1);i++)
    {
	DIO_SetPin_Direction(KEYPAD_PRT,i,DIO_OUTPUT);
	DIO_ActivatePin_PullUp(KEYPAD_PRT,i);
    }

	// define columns as input where (KEYPAD_columns+1)=4 and (KEYPAD_columns+KEYPAD_columns)=6
    for(u8 i=(KEYPAD_columns+1);i<=(KEYPAD_columns+KEYPAD_columns);i++)
    {
	DIO_SetPin_Direction(KEYPAD_PRT,i,DIO_INPUT);
    }
}

u8 KEYPAD_GetKeyPressed()
   {
      u8 row,column,pin;
      //(KEYPAD_rows-KEYPAD_rows)
      //(KEYPAD_rows-KEYPAD_rows)
      for(row=0;row<=3;row++)
      {
    	  DIO_SetPin_Value(KEYPAD_PRT,row,DIO_LOW);
         for(column=4;column<=6;column++)
         {
        	 pin=DIO_ReadPin_Value(KEYPAD_PRT, column);
            if(pin==0)
            {
               column= column-3;
               return keypad[row][column];
            }
         }
         DIO_SetPin_Value(KEYPAD_PRT,row,DIO_HIGH);
         _delay_ms(200);
      }

      return '\0';//Indicate No key pressed
   }
