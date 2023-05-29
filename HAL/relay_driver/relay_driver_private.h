/*
 * relay_driver_private.h
 *
 *  Created on: Apr 1, 2023
 *      Author: ss210
 */

#ifndef HAL_RELAY_DRIVER_RELAY_DRIVER_PRIVATE_H_
#define HAL_RELAY_DRIVER_RELAY_DRIVER_PRIVATE_H_

#define RELAY1          DIO_PIN6
#define RELAY1_PRT      DIO_PORTC
#define RELAY1_OUT      DIO_OUTPUT
#define RELAY1_LOW      DIO_LOW
#define RELAY1_HIGH     DIO_HIGH
#define RELAY2          DIO_PIN7
#define RELAY2_PRT      DIO_PORTC
#define RELAY2_OUT      DIO_OUTPUT
#define RELAY2_LOW      DIO_LOW
#define RELAY2_HIGH     DIO_HIGH

typedef enum{
	clockwise=1,
	counter_clockwise=2
}motion;


#endif /* HAL_RELAY_DRIVER_RELAY_DRIVER_PRIVATE_H_ */
