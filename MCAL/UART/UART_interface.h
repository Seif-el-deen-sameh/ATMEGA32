/*
 * UART_interface.h
 *
 *  Created on: May 10, 2023
 *      Author: ss210
 */

#ifndef MCAL_UART_UART_INTERFACE_H_
#define MCAL_UART_UART_INTERFACE_H_
#include "UART_private.h"
void USART_Init(void);
void USART_Transmit_Data(u8 Data);
u8 USART_Receive_Data(void);
void USART_Mode_Select(operation_mode mode);
void USART_Stop_Select(stop_bits bits);
void USART_Parity_Select(parity_mode mode);
void USART_Bit_Size_Select(data_size size);
void USART_Set_Baud_rate(u8 Baud_rate);
void USART_Transmit_String(u8 Arr[]);
void USART_Receive_String(u8 *Arr);
void USART_Enable_Transmit_Interrupt(void);
void USART_Disable_Transmit_Interrupt(void);
void USART_Enable_Receive_Interrupt(void);
void USART_Disable_Receive_Interrupt(void);
void USART_Enable_Transmitter(void);
void USART_Disable_Transmitter(void);
void USART_Enable_Receiver(void);
void USART_Disable_Receiver(void);
void ISR_USART_Receive_Complete(void(*copy_ptrtofunction)(void));
void ISR_USART_Transmit_Complete(void(*copy_ptrtofunction)(void));
void ISR_USART_Data_Empty(void(*copy_ptrtofunction)(void));
#endif /* MCAL_UART_UART_INTERFACE_H_ */
