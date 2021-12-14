#include "Std_Types.h"
#include "Bit_Math.h"

#include "EXTI0_interfcae.h"

#ifndef		NULL
#define		NULL		(void *)0
#endif

static void (*EXTI0_CallBack) (void) = NULL ;

void	EXTI0_voidInit(void)
{
	/*		Sense Mode			*/
	#if			EXTI0_SENSE_MODE 	==		EXTI_FALLING	
				CLR_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
	#elif		EXTI0_SENSE_MODE 	==		EXTI_RISING
				SET_BIT(MCUCR,0);
				SET_BIT(MCUCR,1);
	#elif		EXTI0_SENSE_MODE 	==		EXTI_IOC
				SET_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
	#elif		EXTI0_SENSE_MODE 	==		EXTI_LOW
				CLR_BIT(MCUCR,0);
				CLR_BIT(MCUCR,1);
	#else
			#erorr "Wrong Choice of EXTI0 Sense Mode"
	#endif
}
void	EXTI0_voidEnable(void)
{
	SET_BIT(GICR,6);
}
void	EXTI0_voidDisable(void)
{
	CLR_BIT(GICR,6);
}

void	EXTI0_voidSetCallBack(void (*ptr) (void))
{
	/*		ptr ----> Ahmed	<----- EXTI0_CallBack		*/
	EXTI0_CallBack = ptr ;
}

void	__vetor_1 (void)  __attribute__((signal,used))
{
	EXTI0_CallBack();
}