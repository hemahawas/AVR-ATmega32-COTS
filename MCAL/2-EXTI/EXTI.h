#ifndef EXTI_H_
#define EXTI_H_

//MCUCR register
#define MCUCR_ISC00    0
#define MCUCR_ISC01    1
#define MCUCR_ISC10    2
#define MCUCR_ISC11    3

//MCUCSR Register
#define MCUCSR_ISC2    6

//GICR register
#define GICR_INT1      7
#define GICR_INT0      6
#define GICR_INT2      5

//GIFR Register
#define GIFR_INTF1      7
#define GIFR_INTF0      6
#define GIFR_INTF2      5

//External Interrupt Pins INT0 , INT1 , INT2
#define EXTI0_PORT     DIO_PORTD
#define EXTI0_PIN      DIO_PIN2


#define EXTI1_PORT     DIO_PORTD
#define EXTI1_PIN      DIO_PIN3


#define EXTI2_PORT     DIO_PORTB
#define EXTI2_PIN      DIO_PIN2


//Sense Control Options
#define EXTI_RISING_EDGE   0
#define EXTI_FALLING_EDGE  1
#define EXTI_LOW_LEVEL     2
#define EXTI_HIGH_LEVEl    3

/*typedef enum{
	FAILING_EDGE = 0 ,
	RISING_EDGE      ,
	LOW_LEVEL        ,
	ON_CHANGE
}SenseControl_t ;*/

#define EXTI_SENSE_CONTROL EXTI_FALLING_EDGE

void    EXTI_void_Int0Init(void);
void    EXTI_void_Int1Init(void);
void    EXTI_void_Int2Init(void);



#endif /* EXTI_H_ */
