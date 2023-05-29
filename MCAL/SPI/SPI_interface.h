/*
 * SPI_interface.h
 *
 *  Created on: Apr 11, 2023
 *      Author: ss210
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_
#include "SPI_private.h"

void SPI_initalize(spi_mode mode);
u8 SPI_transceive(u8 datacarrier);
void ISR_SPI(void(*copy_ptrtofunction)(void));

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
