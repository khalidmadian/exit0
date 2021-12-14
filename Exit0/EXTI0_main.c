#include "Std_Types.h"
#include "Bit_Math.h"

#include "Dio_interfcae.h"
#include "EXTI0_interface.h"
#include "GIE_interface.h"

void Ahmed(void)
{
	DIO_voidSetPinValue(PORTC,PIN7,HIGH);
	_delay_ms(1000);
	DIO_voidSetPinValue(PORTC,PIN7,LOW);
	_delay_ms(1000);	
}

//void (*PF)(void) = Ahmed ;

int main(void)
{
	EXTI0_voidSetCallBack(Ahmed);
	/*		Direction											*/
	/*		D2 is Input (EXTI0 pin) and C7 is OutPut (LED) 		*/
	DIO_voidSetPinDirection(PORTD , PIN2 , INPUT);
	DIO_voidSetPinDirection(PORTC , PIN7 , OUTPUT);
	DIO_voidSetPinDirection(PORTC , PIN2 , OUTPUT);
	
	EXTI0_voidInit(); 		// Sense mode "Rising"
	EXTI0_voidEnable(); 	// PIE ===> EXTI0
	GIE_voidEnable();		//GIE ===> all interrupts
	
	while(1)
	{
		DIO_voidSetPinValue(PORTC,PIN2,HIGH);
		_delay_ms(1000);
		DIO_voidSetPinValue(PORTC,PIN2,LOW);
		_delay_ms(1000);
	}
	return 0;
}