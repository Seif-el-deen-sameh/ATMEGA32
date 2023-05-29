/*
 * TWI_program.c
 *
 *  Created on: May 17, 2023
 *      Author: ss210
 */
#include "std_types.h"
#include "bit_math.h"

#include "TWI_private.h"
#include "TWI_interface.h"

void TWI_voidMasterInit(u8 Copy_u8SlaveAddress)
{
	if(Copy_u8SlaveAddress != 0)
	{

		TWAR = (Copy_u8SlaveAddress<<1);
	}

	TWBR = 2;

	clr_bit(TWSR,TWSR_TWPS0);
	clr_bit(TWSR,TWSR_TWPS1);

	set_bit(TWCR,TWCR_TWEN);
}

void TWI_voidSlaveInit(u8 Copy_u8SlaveAddress)
{

	TWAR = (Copy_u8SlaveAddress<<1);

	set_bit(TWCR,TWCR_TWEA);

	set_bit(TWCR,TWCR_TWEN);
}

TWI_ErrorState TWI_SendStartCondition(void)
{
	TWI_ErrorState Local_ErrorState = NoError;

	set_bit(TWCR,TWCR_TWSTA);

	set_bit(TWCR,TWCR_TWINT);

	while(!get_bit(TWCR,TWCR_TWINT));

	if((TWSR & 0xF8) != START_ACK)
	{
		Local_ErrorState = StartConditionError;
	}
	else{}

	return Local_ErrorState;
}

TWI_ErrorState TWI_SendRepeatedStart(void)
{
	TWI_ErrorState Local_ErrorState = NoError;

	set_bit(TWCR,TWCR_TWSTA);

	set_bit(TWCR,TWCR_TWINT);

	while(!get_bit(TWCR,TWCR_TWINT));

	if((TWSR & STATUS_MASK) != REP_START_ACK)
	{
		Local_ErrorState = RepeatedStartError;
	}

	return Local_ErrorState;
}

TWI_ErrorState TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_ErrorState = NoError;

	TWDR = (Copy_u8SlaveAddress <<1);

	clr_bit(TWDR,0);

	clr_bit(TWCR,TWCR_TWSTA);

	set_bit(TWCR,TWCR_TWINT);

	while(!get_bit(TWCR,TWCR_TWINT));

	if((TWSR & STATUS_MASK) != SLAVE_ADD_AND_WR_ACK)
	{
		Local_ErrorState = SlaveAddressWithWriteError;
	}

	return Local_ErrorState;
}

TWI_ErrorState TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_ErrorState = NoError;

	TWDR = (Copy_u8SlaveAddress <<1);

	set_bit(TWDR,0);

	clr_bit(TWCR,TWCR_TWSTA);

	set_bit(TWCR,TWCR_TWINT);

	while(!get_bit(TWCR,TWCR_TWINT));

	if((TWSR & STATUS_MASK) != SLAVE_ADD_AND_RD_ACK)
	{
		Local_ErrorState = SlaveAddressWithReadError;
	}

	return Local_ErrorState;
}

TWI_ErrorState TWI_MasterSendData(u8 Copy_u8Data)
{
	TWI_ErrorState Local_ErrorState = NoError;

	TWDR = Copy_u8Data ;

	set_bit(TWCR,TWCR_TWINT);

	while(!get_bit(TWCR,TWCR_TWINT));

	if((TWSR & STATUS_MASK) != MSTR_WR_BYTE_ACK)
	{
		Local_ErrorState = MasterSendDataError;
	}

	return Local_ErrorState;
}

TWI_ErrorState TWI_MasterReceiveData(u8* Copy_pu8Data)
{
	TWI_ErrorState Local_ErrorState = NoError;

	set_bit(TWCR,TWCR_TWEA);

	set_bit(TWCR,TWCR_TWINT);

	while(!get_bit(TWCR,TWCR_TWINT));

	if((TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_ACK)
	{
		Local_ErrorState = MasterReceiveDataError;
	}
	else
	{

		* Copy_pu8Data = TWDR ;
	}

	return Local_ErrorState;
}

TWI_ErrorState TWI_MasterReceiveStr(u8* Copy_u8Str, u8 Copy_u8STRLength)
{
	TWI_ErrorState Local_ErrorState = NoError;
	u8 i;

	set_bit(TWCR,TWCR_TWEA);

	for(i=0 ; i <= Copy_u8STRLength ; i++)
	{

		set_bit(TWCR,TWCR_TWINT);

		while(!get_bit(TWCR,TWCR_TWINT));

		if((TWSR & STATUS_MASK) != MSTR_RD_BYTE_WITH_ACK)
		{
			Local_ErrorState = MasterReceiveDataError;
		}
		else
		{

			Copy_u8Str[i] = TWDR ;
		}
		if (i == (Copy_u8STRLength-1))
		{

			clr_bit(TWCR,TWCR_TWEA);
		}
	}
	Copy_u8Str[i-2]='\0';
	return Local_ErrorState;
}

void TWI_SendStopCondition(void)
{

	set_bit(TWCR,TWCR_TWSTO);

	set_bit(TWCR,TWCR_TWINT);
}
