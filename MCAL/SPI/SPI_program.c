/*
 * SPI_program.c
 *
 *  Created on: Apr 11, 2023
 *      Author: ss210
 */
#include "SPI_interface.h"
#include "SPI_configuration.h"
#include "SPI_private.h"
#include "bit_math.h"
#include "std_types.h"

void(*ptr3)(void);
void SPI_initalize(spi_mode mode){
	switch(mode){
	case master:
		clr_bit(SPCR,7);
		set_bit(SPCR,6);
		set_bit(SPCR,5);
		set_bit(SPCR,4);
		clr_bit(SPCR,3);
		clr_bit(SPCR,2);
		clr_bit(SPCR,1);
		set_bit(SPCR,0);
	break;
	case slave:
		clr_bit(SPCR,4);
		clr_bit(SPCR,7);
		set_bit(SPCR,6);
		set_bit(SPCR,5);
		clr_bit(SPCR,3);
		clr_bit(SPCR,2);
	break;
	}
}
u8 SPI_transceive(u8 datacarrier){
	SPDR=datacarrier;
	while((get_bit(SPSR,7))==0);
	return SPDR;
}

void ISR_SPI(void(*copy_ptrtofunction)(void))
{

	ptr3=copy_ptrtofunction;
}
void __vector_12(void)  __attribute__((signal));
void __vector_12(void){
	ptr3();
}
