#ifndef				EXTI0_PRIVATE_H
#define				EXTI0_PRIVATE_H

#define			MCUCR			*((volatile u8 *)0x55)
#define			MCUCSR			*((volatile u8 *)0x54)
#define			GICR			*((volatile u8 *)0x5B)
#define			GIFR			*((volatile u8 *)0x5A)

#define			EXTI_FALLING					1
#define			EXTI_RISING						3
#define			EXTI_IOC						5
#define			EXTI_LOW						7

#endif

