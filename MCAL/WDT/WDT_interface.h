
#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_
#include "bit_math.h"
#include "std_types.h"

/*This function shall enable Watch Dog Timer*/
void WDT_voidEnable(void);
/*This function shall run the WDT with specific sleep time*/
void WDT_voidSetSleepTime(u8 Copy_u8SleepTime);
/*This function shall disable Watch Dog Timer*/
void WDT_voidDisable(void);

#endif /* WDT_INTERFACE_H_ */
