/*
 * Buzzer_private.h
 *
 *  Created on: Mar 28, 2023
 *      Author: ss210
 */

#ifndef HAL_Buzzer_Buzzer_PRIVATE_H_
#define HAL_Buzzer_Buzzer_PRIVATE_H_

#include "DIO_Private.h"

#define Buzzer          DIO_PIN0
#define Buzzer_PRT      DIO_PORTC
#define Buzzer_OUT      DIO_OUTPUT
#define Buzzer_LOW      DIO_LOW
#define Buzzer_HIGH     DIO_HIGH
typedef enum{
key_c=262,
key_d=294,
key_e=330,
key_f=349,
key_g=392,
key_a=440,
key_b=494,
key_C=523
}Buzzer_Tones;
#endif /* HAL_Buzzer_Buzzer_PRIVATE_H_ */
