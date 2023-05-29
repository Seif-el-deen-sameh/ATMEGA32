/*
 * SPI_private.h
 *
 *  Created on: Apr 11, 2023
 *      Author: ss210
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_
#include "std_types.h"
#define SPSR  ( *(volatile u8*) 0x2E)
#define SPCR  ( *(volatile u8*) 0x2D)
#define SPDR  ( *(volatile u8*) 0x2F)

typedef enum{
	master,
	slave
}spi_mode;

#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
