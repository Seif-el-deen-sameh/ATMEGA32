/*
 * Timer0_program.c
 *
 *  Created on: Apr 6, 2023
 *      Author: ss210
 */

#include "std_types.h"
#include "bit_math.h"
#include "Timer0_configuration.h"
#include "Timer0_interface.h"
#include "Timer0_private.h"
void(*ptrt0)(void);
void(*ptrt0_1)(void);
void Timer0_Set_prescalar(Prescalar value){
	switch (value)
	{
	case _none:
	clr_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS02);
	break;
	case _no_prescalar:
	set_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS02);
	break;
	case _8:
	set_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS02);
	break;
	case _64:
	set_bit(TCCR0,TCCR0_CS00);
	set_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS02);
	break;
	case _256:
	set_bit(TCCR0,TCCR0_CS02);
	clr_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS01);
	break;
	case _1024:
	set_bit(TCCR0,TCCR0_CS00);
	clr_bit(TCCR0,TCCR0_CS01);
	set_bit(TCCR0,TCCR0_CS02);
	break;
	case _external_fall:
	set_bit(TCCR0,TCCR0_CS00);
	set_bit(TCCR0,TCCR0_CS01);
	clr_bit(TCCR0,TCCR0_CS02);
	break;
	case _external_rise:
	set_bit(TCCR0,TCCR0_CS00);
	set_bit(TCCR0,TCCR0_CS01);
	set_bit(TCCR0,TCCR0_CS02);
	break;
	}
}
void Timer0_Set_preload(u8 value){
	TCNT0=value;
}
void Timer0_Set_compare(u8 value){
	OCR0=value;
}
void Timer0_Set_mode(Mode value){
	switch (value)
	{
		case CTC:
		clr_bit(TCCR0,TCCR0_WGM00);
		clr_bit(TCCR0,TCCR0_WGM01);
		break;
		case PWM:
		set_bit(TCCR0,TCCR0_WGM00);
		clr_bit(TCCR0,TCCR0_WGM01);
		break;
		case Fast_PWM:
		clr_bit(TCCR0,TCCR0_WGM00);
		set_bit(TCCR0,TCCR0_WGM01);
		break;
		case Timer:
		set_bit(TCCR0,TCCR0_WGM00);
		set_bit(TCCR0,TCCR0_WGM01);
		break;
	}
}
void Timer0_OC0_mode(OC0_Mode mode){
switch (mode)
{
	case Disconnected:
	clr_bit(TCCR0,TCCR0_COM00);
	clr_bit(TCCR0,TCCR0_COM01);
	break;
	case Toggle:
	set_bit(TCCR0,TCCR0_COM00);
	clr_bit(TCCR0,TCCR0_COM01);
	break;
	case Clear:
	clr_bit(TCCR0,TCCR0_COM01);
	set_bit(TCCR0,TCCR0_COM00);
	break;
	case Set:
	set_bit(TCCR0,TCCR0_COM00);
	set_bit(TCCR0,TCCR0_COM01);
	break;
}
}
void Timer0_initalize(){
	clr_bit(TCCR0,TCCR0_WGM00);
	set_bit(TCCR0,TCCR0_WGM01);
	set_bit(Sreg,7);
	Timer0_enable_compare_intterrupt();
	// OCR0|=77;
	// TCCR0|=69;
	OCR0|=780;
	TCCR0|=69;
}
void Timer0_enable_overflow_intterrupt(){
	set_bit(TIMSK,TIMSK_TOIE0);
}
void Timer0_enable_compare_intterrupt(){
	set_bit(TIMSK,TIMSK_OCIE0);
}
void Timer0_disable_overflow_intterrupt(){
	clr_bit(TIMSK,TIMSK_TOIE0);
}
void Timer0_disable_compare_intterrupt(){
	clr_bit(TIMSK,TIMSK_OCIE0);
}
u8 Timer0_overflow_intterrupt_Flag_Value(void){
	u8 bit = 0;
	bit = get_bit(TIFR, TIFR_TOV0);
	return bit;
}
u8 Timer0_compare_intterrup_Flag_Value(void){
	u8 value = 0;
	value = get_bit(TIFR, TIFR_OCF0);
	return value;
}
void ISR_Timer0_Overflow(void(*copy_ptrtofunction)(void))
{

	ptrt0=copy_ptrtofunction;
}
void ISR_Timer0_Compare_Match(void(*copy_ptrtofunction)(void))
{

	ptrt0_1=copy_ptrtofunction;
}
void __vector_11(void)  __attribute__((signal));
void __vector_11(void){
	ptrt0();
}
void __vector_10(void)  __attribute__((signal));
void __vector_10(void){
	ptrt0_1();
}
