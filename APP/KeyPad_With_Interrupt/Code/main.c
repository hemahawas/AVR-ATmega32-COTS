/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: HemaHawas
 */
#define F_CPU 8000000UL
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "KPD.h"
#include "EXTI.h"
#include "GIE.h"
#include "avr/io.h"
#include <util/delay.h>
#include "SVNSEG.h"

void KPD_ISR(void);

void main(void){

	EXTI_voidInt0Init();
	EXTI_voidInt0SetControl(EXTI_FALLING_EDGE);
	GIE_Enable();
	KPD_voidInit();
	SVNSEG_voidInit();

	EXTI_u8Int0SetCallBack(&KPD_ISR);
	while(1){

	}
}

void KPD_ISR(void){
	u8 key = KPD_u8GetPressedKey();
	if(key != KPD_NOT_PRESSED_KEY)
	SVN_SEG_WriteOn7Segment(key);
}
