#include "Std_Types.h"
#include "Bit_Math.h"

#include "GIE_interfcae.h"



void	GIE_voidEnable(void)
{
	SET_BIT(SREG,7);
}
void	GIE_voidDisable(void)
{
	CLR_BIT(SREG,7);
}