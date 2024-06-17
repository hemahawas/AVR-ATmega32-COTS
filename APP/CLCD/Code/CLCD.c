/**************************************************/
/***********	Author : Ibraheem rizk	***********/
/***********	Layer  : HAL			***********/
/***********	Component : CLCD		***********/
/***********	Version : 1.00			***********/
/***********	Date : 14-8/2023		***********/
/**************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include <util/delay.h>

void CLCD_voidSendData(u8 u8DataCopy){
	// 1. Set RS &  reset RW (for Data/Command & Read/Write)
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_HIGH);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_LOW);

	// 2. Send data into data port
	DIO_SetPortValue(CLCD_DATA_PORT, u8DataCopy);

	// 3. Set enable for more than 1ms then reset it
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_LOW);

}

void CLCD_voidSendCommand(u8 u8CommandCopy){
	// 1. Reset RS & RW (for Data/Command & Read/Write)
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_LOW);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_LOW);

	// 2. Send command into data port
	DIO_SetPortValue(CLCD_DATA_PORT, u8CommandCopy);

	// 3. Set enable for more than 1ms then reset it
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_HIGH);
	_delay_ms(2);
	DIO_SetPinValue(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_LOW);
}


void CLCD_voidInit(void){
	// 1. Wait for more than 30ms
	_delay_ms(40);

	/* 2. Send command to function set
	*	N: number of lines 1: 2 lines, 0: 1 line
	*	F: character font 1: 5*11, 0: 5*8
	*
	*/
	u8 localCoammand = 0b00111000;
	CLCD_voidSendCommand(localCoammand);

	// 2. Wait for more than 39us -> already waited in send command function

	/* 3. Display on/off
		*	D: Display screen
		*	C: show Cursor
		*	B: Cursor blink
		*/
	localCoammand = 0b00001100;
	CLCD_voidSendCommand(localCoammand);

	// 4. Display clear
	CLCD_voidSendCommand(0x01);

}
