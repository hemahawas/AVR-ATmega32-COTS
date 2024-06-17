/**************************************************/
/***********	Author : Ibraheem rizk	***********/
/***********	Layer  : HAL			***********/
/***********	Component : SVN_SEG		***********/
/***********	Version : 1.00			***********/
/***********	Date : 16-8/2023		***********/
/**************************************************/

#include "STD_TYPES.h"
#include "DIO.h"
#include "SVN_SEG.h"

void SVN_SEG_WriteOn7Segment(u8 u8LcdValCopy){
	switch(u8LcdValCopy){
	case '0': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_0); break;
	case '1': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_1); break;
	case '2': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_2); break;
	case '3': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_3); break;
	case '4': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_4); break;
	case '5': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_5); break;
	case '6': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_6); break;
	case '7': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_7); break;
	case '8': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_8); break;
	case '9': DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_NUMBER_9); break;
	default : DIO_SetPortValue(SVN_SEG_PORT,SVN_SEG_TURN_OFF); break;
	}
}

void SVN_SEG_Init(){
	DIO_SetPortDirection(SVN_SEG_PORT,0xff);
}
