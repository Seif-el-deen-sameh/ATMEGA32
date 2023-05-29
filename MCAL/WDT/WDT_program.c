#include "bit_math.h"
#include "std_types.h"

#include "WDT_interface.h"
#include "WDT_private.h"
#include "WDT_config.h"


void WDT_voidEnable(void){
set_bit(WDCTR,4);
set_bit(WDCTR,3);
}

void WDT_voidSetSleepTime(u8 Copy_u8SleepTime){
	set_bit(WDCTR,1);
	set_bit(WDCTR,2);
	clr_bit(WDCTR,0);
}

void WDT_voidDisable(void){

}
