/**************************************************/
/***********	Author : Ibraheem rizk	***********/
/***********	Layer  : MCAL			***********/
/***********	Component : GIE			***********/
/***********	Version : 1.00			***********/
/***********	Date : 16-8/2023		***********/
/**************************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include "GIE.h"

void GIE_Enable(void){
	// Set 7 in SREG
	SET_BIT(SREG, GIE_SREG_I);
}

void GIE_Disable(void){
	CLR_BIT(SREG, GIE_SREG_I);
}

