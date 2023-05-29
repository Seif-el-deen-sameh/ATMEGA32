/*
 * UART_private.h
 *
 *  Created on: Apr 10, 2023
 *      Author: ss210
 */

#ifndef MCAL_UART_UART_PRIVATE_H_
#define MCAL_UART_UART_PRIVATE_H_

#include "std_types.h"

#define UDR   ( *(volatile u8*) 0x2C)
#define UCSRA ( *(volatile u8*) 0x2B)
#define UCSRB ( *(volatile u8*) 0x2A)
#define UBRRL ( *(volatile u8*) 0x29)
#define UCSRC ( *(volatile u8*) 0x40)

typedef enum{
  UCSRA_RXC=7,
  UCSRA_TXC=6,
  UCSRA_UDRE=5,
  UCSRA_FE=4,
  UCSRA_DOR=3,
  UCSRA_PE=2,
  UCSRA_U2X=1,
  UCSRA_MPCM=0
}UCSRA_BIT;
typedef enum{
  UCSRB_RXCIE=7,
  UCSRB_TXCIE=6,
  UCSRB_UDRIE=5,
  UCSRB_RXEN=4,
  UCSRB_TXEN=3,
  UCSRB_UCSZ2=2,
  UCSRB_RXB8=1,
  UCSRB_TXB8=0
}UCSRB_BIT;
typedef enum{
  UCSRC_URSEL=7,
  UCSRC_UMSEL=6,
  UCSRC_UPM1=5,
  UCSRC_UPM0=4,
  UCSRC_USBS =3,
  UCSRC_UCSZ1=2,
  UCSRC_UCSZ0=1,
  UCSRC_UCPOL=0
}UCSRC_BIT;
typedef enum{
	_8_=8,
	_7_=7,
	_6_=6,
	_5_=5
}data_size;
typedef enum{
	Synchronus=0,
	Asynchronus=1
}operation_mode;
typedef enum{
	_1=1,
	_2=2
}stop_bits;
typedef enum{
	Odd=1,
	Even=2,
	None=0
}parity_mode;

/*USART Modes*/
#define USART_ASYNCHORONOUS 0
#define USART_SYNCHORONOUS  1

/*Parity Selections*/
#define USART_NO_PARITY   0
#define USART_EVEN_PARITY 1
#define USART_ODD_PARITY  2

/*STOP bit Mode*/
#define USART_1_STOP 0
#define USART_2_STOP 1

/*Character Size Selections*/
#define USART_8_BIT 0
#define USART_7_BIT 1
#define USART_6_BIT 2
#define USART_5_BIT 3
#endif /* MCAL_UART_UART_PRIVATE_H_ */
