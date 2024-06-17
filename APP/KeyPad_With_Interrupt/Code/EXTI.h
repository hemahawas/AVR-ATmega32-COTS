/*
 * EXTI.h
 *
 *  Created on: Aug 16, 2023
 *      Author: HemaHawas
 */

#ifndef EXTI_H_
#define EXTI_H_

//MCUCR
#define EXTI_MCUCR_ISC00		0
#define EXTI_MCUCR_ISC01		1
#define EXTI_MCUCR_ISC10		2
#define EXTI_MCUCR_ISC11		3

//MCUCSR
#define EXTI_MCUCSR_ISC2		6

//GICR
#define EXTI_GICR_INT1		7
#define EXTI_GICR_INT0		6
#define EXTI_GICR_INT2		5

//GIFR
#define EXTI_GIFR_INTF1		7
#define EXTI_GIFR_INTF0		6
#define EXTI_GIFR_INTF2		5


//External INT Pins
#define EXTI_INT0_PORT		DIO_PORTD
#define EXTI_INT0_PIN		DIO_PIN2

#define EXTI_INT1_PORT		DIO_PORTD
#define EXTI_INT1_PIN		DIO_PIN3

#define EXTI_INT2_PORT		DIO_PORTB
#define EXTI_INT2_PIN		DIO_PIN2

#define EXTI_RISING_EDGE		1
#define EXTI_FALLING_EDGE		2
#define EXTI_LOW_LEVEL			3
#define EXTI_ON_CHANGE			4


#define EXTI_ENABLE		1
#define EXTI_DISABLE	2

#define EXTI_INITIAL_STATE	EXTI_ENABLE

#define EXTI_SENSE_CTRL 	EXTI_FALLING_EDGE

#define NUL	0


void EXTI_voidInt0Init(void);
void EXTI_voidInt1Init(void);
void EXTI_voidInt2Init(void);

u8 EXTI_voidInt0SetControl(u8 senseControl);
u8 EXTI_voidInt1SetControl(u8 senseControl);
u8 EXTI_voidInt2SetControl(u8 senseControl);

// Callback function
u8 EXTI_u8Int0SetCallBack(void (*pvInt0FuncCopy) (void));
// TODO Int 1,2

#endif /* EXTI_H_ */
