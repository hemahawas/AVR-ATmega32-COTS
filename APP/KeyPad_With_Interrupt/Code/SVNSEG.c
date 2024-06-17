/*
 * SVNSEG.c
 *
 *  Created on: Aug 21, 2023
 *      Author: HemaHawas
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "SVNSEG.h"

void SVNSEG_voidInit(void){
	DIO_SetPortDirection(DIO_PORTA, 0xff);
}

void SVN_SEG_WriteOn7Segment(u8 u8LcdValCopy){
	switch(u8LcdValCopy){
	case '0': DIO_SetPortValue(DIO_PORTA,SVNSEG_0); break;
	case '1': DIO_SetPortValue(DIO_PORTA,SVNSEG_1); break;
	case '2': DIO_SetPortValue(DIO_PORTA,SVNSEG_2); break;
	case '3': DIO_SetPortValue(DIO_PORTA,SVNSEG_3); break;
	case '4': DIO_SetPortValue(DIO_PORTA,SVNSEG_4); break;
	case '5': DIO_SetPortValue(DIO_PORTA,SVNSEG_5); break;
	case '6': DIO_SetPortValue(DIO_PORTA,SVNSEG_6); break;
	case '7': DIO_SetPortValue(DIO_PORTA,SVNSEG_7); break;
	case '8': DIO_SetPortValue(DIO_PORTA,SVNSEG_8); break;
	case '9': DIO_SetPortValue(DIO_PORTA,SVNSEG_9); break;
	default : DIO_SetPortValue(DIO_PORTA,SVNSEG_0); break;
	}
}
