/*
 * main.c
 *
 *  Created on: Aug 13, 2023
 *      Author: HemaHawas
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "CLCD.h"
#include <stdio.h>
#include "avr/io.h"
#include <util/delay.h>

void printShow(char*);

void main(void){
	// 1. Initialize the data port to output
	DIO_SetPortDirection(CLCD_DATA_PORT, 0xff);
	DIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(CLCD_CTRL_PORT, CLCD_E_PIN, DIO_OUTPUT);

	// 2. Initialize the LCD
	CLCD_voidInit();
	printShow("HEMA");

	while(1){

	}
}

void printShow(u8* s){
	int n = 4;
	int i,j;
	while(1){

		for(i = 0; i < n; i++){
			CLCD_voidSendData(s[i]);
			_delay_ms(500);
		}

		CLCD_voidSendCommand(0x01);

		j = 1;
		while(j <= n){
			for(i = 0; i < n-j; i++){
				CLCD_voidSendData(s[i]);
			}
			_delay_ms(500);
			CLCD_voidSendCommand(0x01);
			j++;
		}
	}
}
