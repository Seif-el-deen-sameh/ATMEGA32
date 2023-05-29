/*
 * S_seg_private.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_S_SEG_S_SEG_PRIVATE_H_
#define HAL_S_SEG_S_SEG_PRIVATE_H_
#include "DIO_Private.h"
#define S_seg         DIO_PORTC
#define dot 			7
typedef enum{
	zero  =0b1000000,
	one   =0b1111001,
	two	  =0b0100100,
	three =0b0110000,
	four  =0b0011001,
	five  =0b0010010,
	six   =0b0000010,
	seven =0b1111000,
	eight =0b0000000,
	nine  =0b0010000
}S_seg_num;
typedef enum{
	cathode,
	anode
}S_seg_mode;

#endif /* HAL_S_SEG_S_SEG_PRIVATE_H_ */
