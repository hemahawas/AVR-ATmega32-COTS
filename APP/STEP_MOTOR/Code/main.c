/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: HemaHawas
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#define F_CPU 8000000UL
#include "avr/io.h"
#include "util/delay.h"


void main(void){
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN2, DIO_OUTPUT);
	DIO_SetPinDirection(DIO_PORTC, DIO_PIN3, DIO_OUTPUT);

	while(1){
		// First
		DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_HIGH);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_LOW);

		_delay_ms(120);

		// Second
		DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_HIGH);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_LOW);

		_delay_ms(120);

		// Third
		DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_HIGH);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_LOW);

		_delay_ms(120);

		// Forth
		DIO_SetPinValue(DIO_PORTC, DIO_PIN0, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN1, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN2, DIO_LOW);
		DIO_SetPinValue(DIO_PORTC, DIO_PIN3, DIO_HIGH);

		_delay_ms(120);
	}
}
