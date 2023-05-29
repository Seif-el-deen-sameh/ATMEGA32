/*
 * Timer0_interface.h
 *
 *  Created on: Apr 6, 2023
 *      Author: ss210
 */

#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_

#include "Timer0_private.h"

void Timer0_Set_prescalar(Prescalar value);
void Timer0_Set_preload(u8 value);
void Timer0_Set_compare(u8 value);
void Timer0_Set_mode(Mode value);
void Timer0_OC0_mode(OC0_Mode mode);
void Timer0_initalize();
void Timer0_enable_overflow_intterrupt();
void Timer0_enable_compare_intterrupt();
void Timer0_disable_overflow_intterrupt();
void Timer0_disable_compare_intterrupt();
u8 Timer0_overflow_intterrupt_Flag_Value(void);
u8 Timer0_compare_intterrup_Flag_Value(void);
void ISR_Timer0_Overflow(void(*copy_ptrtofunction)(void));
void ISR_Timer0_Compare_Match(void(*copy_ptrtofunction)(void));


#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
