/*
 * TWI_interface.h
 *
 *  Created on: May 17, 2023
 *      Author: ss210
 */
#ifndef TWI_INTERFACE_H_
#define TWI_INTERFACE_H_
#include "TWI_private.h"
#include "TWI_config.h"
#include "std_types.h"
typedef enum
{
	NoError,
	StartConditionError,
	RepeatedStartError,
	SlaveAddressWithWriteError,
	SlaveAddressWithReadError,
	MasterSendDataError,
	MasterReceiveDataError,
}TWI_ErrorState;
void TWI_voidMasterInit(u8 Copy_u8SlaveAddress);
void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress);
TWI_ErrorState TWI_SendStartCondition(void);
TWI_ErrorState TWI_SendRepeatedStart(void);
TWI_ErrorState TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);
TWI_ErrorState TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrorState TWI_MasterSendData(u8 Copy_u8Data);

TWI_ErrorState TWI_MasterReceiveData(u8* Copy_pu8Data);

TWI_ErrorState TWI_MasterReceiveStr(u8* Copy_u8Str, u8 Copy_u8STRLength);

void TWI_SendStopCondition(void);

#endif /* TWI_INTERFACE_H_ */
