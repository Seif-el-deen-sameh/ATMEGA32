/*
 * button_program.c
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */


#include "DIO_Interface.h"
#include "button_private.h"
#include "External_interrupt_interface.h"
#include <util/delay.h>
void BTN0_Initialize(void)
{
	DIO_SetPin_Direction(BTN0_PRT, BTN0, BTN0_IN);
	DIO_ActivatePin_PullUp(BTN0_PRT, BTN0);
	set_bit(MCUCR,MCUCR_ISC00);
	set_bit(MCUCR,MCUCR_ISC01);
	set_bit(GICR,GICR_INT0);
	set_bit(SREG,7);
}
void BTN0_Enable_pullup(void){
	//DIO_ActivatePin_PullUp(BTN0_PRT, BTN0);
}
u8 BTN0_Read(void)
{
	u8 Val = 0;
	_delay_ms(10);
	Val = DIO_ReadPin_Value(BTN0_PRT, BTN0);
	return Val;
}
