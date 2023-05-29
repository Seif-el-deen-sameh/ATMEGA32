/*
 * UART_program.c
 *
 *  Created on: May 10, 2023
 *      Author: ss210
 */
#include "bit_math.h"
#include "global_interrupt.h"
#include "std_types.h"
#include "UART_config.h"
#include "UART_interface.h"
#include "UART_private.h"
void(*Receive)(void);
void(*Transmit)(void);
void(*Empty)(void);
void USART_Init(void){
	/*Setting Register Select to UCSRC Register*/
	set_bit(UCSRC,UCSRC_URSEL);
	/*Setting USART Mode*/
	#if USART_MODE_SELECT == USART_ASYNCHORONOUS
		clr_bit(UCSRC,UCSRC_UMSEL);
	#elif 	USART_MODE_SELECT == USART_SYNCHORONOUS
		set_bit(UCSRC,UCSRC_UMSEL);
	#endif
	/*Setting Parity Mode*/
	#if USART_PARITY_MODE == USART_NO_PARITY
		clr_bit(UCSRC,UCSRC_UPM1);
		clr_bit(UCSRC,UCSRC_UPM0);
	#elif USART_PARITY_MODE == USART_EVEN_PARITY
		set_bit(UCSRC,UCSRC_UPM1);
		clr_bit(UCSRC,UCSRC_UPM0);
	#elif USART_PARITY_MODE == USART_ODD_PARITY
		set_bit(UCSRC,UCSRC_UPM1);
		set_bit(UCSRC,UCSRC_UPM0);
	#endif
	/*Setting USART Mode*/
	#if USART_STOP_BIT == USART_1_STOP
		clr_bit(UCSRC,UCSRC_USBS);
	#elif USART_STOP_BIT == USART_2_STOP
		set_bit(UCSRC,UCSRC_USBS);
	#endif
	/*Setting Character Size*/
	#if USART_CHARACTER_SIZE == USART_8_BIT
		set_bit(UCSRC,UCSRC_UCSZ1);
		set_bit(UCSRC,UCSRC_UCSZ0);
	#elif USART_CHARACTER_SIZE == USART_7_BIT
		set_bit(UCSRC,UCSRC_UCSZ1);
		clr_bit(UCSRC,UCSRC_UCSZ0);
	#elif USART_CHARACTER_SIZE == USART_6_BIT
		clr_bit(UCSRC,UCSRC_UCSZ1);
		set_bit(UCSRC,UCSRC_UCSZ0);
	#elif USART_CHARACTER_SIZE == USART_5_BIT
		clr_bit(UCSRC,UCSRC_UCSZ1);
		clr_bit(UCSRC,UCSRC_UCSZ0);
	#endif
}
void USART_Transmit_Data(u8 Data){
	/*Make Sure UDR is Empty*/
		while(get_bit(UCSRA,UCSRA_UDRE)==0);
		/*Assign the value to get transmitted*/
		UDR = Data;
#if 	USART_MODE_SELECT == USART_SYNCHORONOUS
		/*Polling till the end of transmission*/
		while(get_bit(UCSRA,UCSRA_TXC)==0);
		/*Clear Transmission Flag*/
		set_bit(UCSRA,UCSRA_TXC);
	#endif
}
u8 USART_Receive_Data(void){
#if 	USART_MODE_SELECT == USART_SYNCHORONOUS
	/*Polling till the end of Receive Data*/
	while(get_bit(USART_UCSRA,UCSRA_RXC)==0);
#endif
	/*Get the received Data*/
	return UDR;
}
void USART_Mode_Select(operation_mode mode){
	switch (mode)
	{
		case Synchronus:
			set_bit(UCSRC,UCSRC_UMSEL);
		break;
		case Asynchronus:
			clr_bit(UCSRC,UCSRC_UMSEL);
		break;
	}
}
void USART_Stop_Select(stop_bits bits){
	switch (bits)
	{
		case _1:
			clr_bit(UCSRC,UCSRC_USBS);
		break;
		case _2:
			set_bit(UCSRC,UCSRC_USBS);
		break;
	}
}
void USART_Parity_Select(parity_mode mode){
	switch (mode)
	{
		case Odd:
			set_bit(UCSRC,UCSRC_UPM1);
			set_bit(UCSRC,UCSRC_UPM0);
		break;
		case Even:
			set_bit(UCSRC,UCSRC_UPM1);
			clr_bit(UCSRC,UCSRC_UPM0);
		break;
		case None:
			clr_bit(UCSRC,UCSRC_UPM1);
			clr_bit(UCSRC,UCSRC_UPM0);
		break;
	}
}
void USART_Bit_Size_Select(data_size size){
	switch (size)
	{
		case _8_:
			set_bit(UCSRC,UCSRC_UCSZ1);
			set_bit(UCSRC,UCSRC_UCSZ0);
		break;
		case _7_:
			set_bit(UCSRC,UCSRC_UCSZ1);
			clr_bit(UCSRC,UCSRC_UCSZ0);
		break;
		case _6_:
			clr_bit(UCSRC,UCSRC_UCSZ1);
			set_bit(UCSRC,UCSRC_UCSZ0);
		break;
		case _5_:
			clr_bit(UCSRC,UCSRC_UCSZ1);
			clr_bit(UCSRC,UCSRC_UCSZ0);
		break;
	}
}
void USART_Transmit_String(u8 Arr[]){
#if 	USART_MODE_SELECT == USART_SYNCHORONOUS
	u8 i=0;
	while(Copy_u8Arr[i] != '\0')
	{
		USART_Transmit_Data(Arr[i]);
		i++;
	}
#endif

}
void USART_Receive_String(u8 *Arr){
#if 	USART_MODE_SELECT == USART_SYNCHORONOUS
	u8 i=0;

	Arr[i]=USART_Receive_Data();

	while(Copy_u8Arr[i] != '#')
	{
		i++;
		Arr[i]=USART_Receive_Data();
	}
	Arr[i] = '\0';
#endif
}
void USART_Enable_Send_Interrupt(void){
	set_bit(UCSRB,UCSRB_TXCIE);
}
void USART_Disable_Send_Interrupt(void){
	clr_bit(UCSRB,UCSRB_TXCIE);
}
void USART_Enable_Receive_Interrupt(void){
	set_bit(UCSRB,UCSRB_RXCIE);
}
void USART_Disable_Receive_Interrupt(void){
	clr_bit(UCSRB,UCSRB_RXCIE);
}
void USART_Set_Baud_rate(u8 Baud_rate){
	UBRRL=Baud_rate;
}
void USART_Enable_Transmitter(void){
	set_bit(UCSRB,UCSRB_TXEN);
}
void USART_Disable_Transmitter(void){
	clr_bit(UCSRB,UCSRB_TXEN);
}
void USART_Enable_Receiver(void){
	set_bit(UCSRB,UCSRB_RXEN);
}
void USART_Disable_Receiver(void){
	clr_bit(UCSRB,UCSRB_RXEN);
}
void ISR_USART_Receive_Complete(void(*copy_ptrtofunction)(void))
{
	Receive=copy_ptrtofunction;
}
void ISR_USART_Transmit_Complete(void(*copy_ptrtofunction)(void))
{
	Transmit=copy_ptrtofunction;
}
void ISR_USART_Data_Empty(void(*copy_ptrtofunction)(void))
{
	Empty=copy_ptrtofunction;
}
void __vector_13(void)  __attribute__((signal));
void __vector_13(void){
	Receive();
}
void __vector_14(void)  __attribute__((signal));
void __vector_14(void){
	Empty();
}
void __vector_15(void)  __attribute__((signal));
void __vector_15(void){
	Transmit();
}
