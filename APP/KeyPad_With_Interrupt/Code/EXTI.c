/**************************************************/
/***********	Author : Ibraheem rizk	***********/
/***********	Layer  : MCAL			***********/
/***********	Component : EXTI		***********/
/***********	Version : 1.00			***********/
/***********	Date : 16-8/2023		***********/
/**************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include "EXTI.h"


void (*EXTI_pvCallBackFunc) (void)=NUL;

/*
void EXTI_voidInt0Init(void){
	// Set sense control for INT0 to falling edge
	SET_BIT(MCUCR, EXTI_MCUCR_ISC00);
	CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);

	// PIE --> Enable
	SET_BIT(GICR, EXTI_GICR_INT0);
}

void EXTI_voidInt1Init(void){
	// Set sense control for INT0 to falling edge
		SET_BIT(MCUCR, EXTI_MCUCR_ISC10);
		CLR_BIT(MCUCR, EXTI_MCUCR_ISC11);

		// PIE --> Enable
		SET_BIT(GICR, EXTI_GICR_INT1);
}

void EXTI_voidInt2Init(void){

}*/

// Prebuild method
void EXTI_voidInt0Init(void){
	// check sense control
#if 	EXTI_SENSE_CTRL	== EXTI_LOW_LEVEL
	CLR_BIT(MCUCR, EXTI_MCUCR_ISC00);
	CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);
#elif	EXTI_SENSE_CTRL	== EXTI_ON_CHANGE
	SET_BIT(MCUCR, EXTI_MCUCR_ISC00);
	CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);
#elif 	EXTI_SENSE_CTRL	== EXTI_FALLING_EDGE
	CLR_BIT(MCUCR, EXTI_MCUCR_ISC00);
	SET_BIT(MCUCR, EXTI_MCUCR_ISC01);
#elif	EXTI_SENSE_CTRL	== EXTI_RISING_EDGE
	SET_BIT(MCUCR, EXTI_MCUCR_ISC00);
	SET_BIT(MCUCR, EXTI_MCUCR_ISC01);
#else

#error "WARning"

#endif

	// PIE
#if		EXTI_INITIAL_STATE == EXTI_ENABLE
	SET_BIT(GICR, EXTI_GICR_INT0);
#elif	EXTI_INITIAL_STATE == EXTI_DISABLE
		CLR_BIT(GICR, EXTI_GICR_INT0);
#else
#error "WARning"
#endif
}

void EXTI_voidInt1Init(void){

}

void EXTI_voidInt2Init(void){

}

u8 EXTI_voidInt0SetControl(u8 senseControl){
	u8 u8ErrorState_Local = OK;
	switch(senseControl){
	case EXTI_LOW_LEVEL:
		CLR_BIT(MCUCR, EXTI_MCUCR_ISC00);
		CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);
		break;
	case EXTI_ON_CHANGE:
		SET_BIT(MCUCR, EXTI_MCUCR_ISC00);
		CLR_BIT(MCUCR, EXTI_MCUCR_ISC01);
		break;
	case EXTI_FALLING_EDGE:
		CLR_BIT(MCUCR, EXTI_MCUCR_ISC00);
		SET_BIT(MCUCR, EXTI_MCUCR_ISC01);
		break;
	case EXTI_RISING_EDGE:
		SET_BIT(MCUCR, EXTI_MCUCR_ISC00);
		SET_BIT(MCUCR, EXTI_MCUCR_ISC01);
		break;
	default:
		u8ErrorState_Local = NOK;
	}
	return u8ErrorState_Local ;
}

u8 EXTI_u8Int0SetCallBack(void (*pvInt0FuncCopy) (void)){
	u8 u8ErrorStatusLocal = OK;
	if(pvInt0FuncCopy != NUL){
		// global ptr = local ptr
		EXTI_pvCallBackFunc = pvInt0FuncCopy;
	}
	else{
		u8ErrorStatusLocal = NUL_PTR;
	}
	return u8ErrorStatusLocal;
}

void __vector_1 (void)__attribute__((signal));
void __vector_1 (void){
	if(EXTI_pvCallBackFunc != NUL){
		EXTI_pvCallBackFunc();
	}
}
