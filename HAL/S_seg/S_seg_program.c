/*
 * S_seg_program.c
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */
#include "S_seg_interface.h"

void S_seg_Initialize(S_seg_mode mode){
	switch(mode)
				{
					case anode:
						DIO_SetPort_Direction(S_seg,DIO_PORT_HIGH);
						DIO_SetPort_Value(S_seg,DIO_PORT_LOW);
					break;
					case cathode:
						DIO_SetPort_Direction(S_seg,DIO_PORT_HIGH);
						DIO_SetPort_Value(S_seg,DIO_PORT_HIGH);
					break;
				}
}
void S_seg_Num(S_seg_num num,S_seg_mode mode){
	switch(mode)
			{
				case cathode:
				DIO_SetPort_Value(S_seg,num);
				break;
				case anode:
				DIO_SetPort_Value(S_seg,(~num));
				break;
			}
}
void S_seg_clear(S_seg_mode mode){
	switch(mode)
					{
						case cathode:
							DIO_SetPort_Value(S_seg,DIO_PORT_LOW);
						break;
						case anode:
							DIO_SetPort_Value(S_seg,DIO_PORT_HIGH);
						break;
					}
}
void S_seg_enable_dot(S_seg_mode mode){
	switch(mode)
				{
					case cathode:
						DIO_SetPin_Value(S_seg,dot,DIO_HIGH);
					break;
					case anode:
						DIO_SetPin_Value(S_seg,dot,DIO_LOW);
					break;
				}

	}

void S_seg_disable_dot(S_seg_mode mode){
	switch(mode)
				{
					case cathode:
						DIO_SetPin_Value(S_seg,dot,DIO_LOW);
					break;
					case anode:
						DIO_SetPin_Value(S_seg,dot,DIO_HIGH);
					break;
				}

	}
