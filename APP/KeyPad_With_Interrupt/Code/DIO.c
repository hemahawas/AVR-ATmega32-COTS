/**************************************************/
/***********	Author : Ibraheem rizk	***********/
/***********	Layer  : MCAL			***********/
/***********	Component : DIO			***********/
/***********	Version : 1.00			***********/
/***********	Date : 13-8/2023		***********/
/**************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"

#include <util/delay.h>

#include "DIO.h"

void 	DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValCopy){
	// Check range
	if(u8PortIdCopy <= DIO_PORTD && u8PinIdCopy <= DIO_PIN7){
		if(u8PinValCopy == DIO_HIGH){
			// Set Pin to high
			switch(u8PortIdCopy){
				case 	DIO_PORTA: SET_BIT(PORTA, u8PinIdCopy); break;
				case 	DIO_PORTB: SET_BIT(PORTB, u8PinIdCopy); break;
				case 	DIO_PORTC: SET_BIT(PORTC, u8PinIdCopy); break;
				case 	DIO_PORTD: SET_BIT(PORTD, u8PinIdCopy); break;
			}
		}
		else if(u8PinValCopy == DIO_LOW){
			// Set Pin to low
			switch(u8PortIdCopy){
				case	DIO_PORTA: CLR_BIT(PORTA, u8PinIdCopy); break;
				case 	DIO_PORTB: CLR_BIT(PORTB, u8PinIdCopy); break;
				case 	DIO_PORTC: CLR_BIT(PORTC, u8PinIdCopy); break;
				case 	DIO_PORTD: CLR_BIT(PORTD, u8PinIdCopy); break;
			}
		}
		else{//not entered low or high
			}
	}
	else{
		// out of range
	}
}


void 	DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy){
	// Check range
	if(u8PortIdCopy <= DIO_PORTD && u8PinIdCopy <= DIO_PIN7){
		if(u8PinDirCopy == DIO_OUTPUT){
			// Set Pin to output
			switch(u8PortIdCopy){
				case 	DIO_PORTA: SET_BIT(DDRA, u8PinIdCopy); break;
				case 	DIO_PORTB: SET_BIT(DDRB, u8PinIdCopy); break;
				case 	DIO_PORTC: SET_BIT(DDRC, u8PinIdCopy); break;
				case 	DIO_PORTD: SET_BIT(DDRD, u8PinIdCopy); break;
			}
		}
		else if(u8PinDirCopy == DIO_INPUT){
			// Set Pin to input
			switch(u8PortIdCopy){
				case 	DIO_PORTA: CLR_BIT(DDRA, u8PinIdCopy); break;
				case	DIO_PORTB: CLR_BIT(DDRB, u8PinIdCopy); break;
				case 	DIO_PORTC: CLR_BIT(DDRC, u8PinIdCopy); break;
				case 	DIO_PORTD: CLR_BIT(DDRD, u8PinIdCopy); break;
			}
		}
		else{//not entered input or output
			}
	}
	else{
		// out of range
	}
}


u8 		DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy){
	u8 u8ResultLocal;
	// Check range
		if(u8PortIdCopy <= DIO_PORTD && u8PinIdCopy <= DIO_PIN7){
			switch(u8PortIdCopy){
				case 	DIO_PORTA: u8ResultLocal = GET_BIT(PINA, u8PinIdCopy); break;
				case 	DIO_PORTB: u8ResultLocal = GET_BIT(PINB, u8PinIdCopy); break;
				case 	DIO_PORTC: u8ResultLocal = GET_BIT(PINC, u8PinIdCopy); break;
				case 	DIO_PORTD: u8ResultLocal = GET_BIT(PIND, u8PinIdCopy); break;
			}
		}
		else{
			u8ResultLocal = 0xff;
		}
		return u8ResultLocal;
}


void 	DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PinValCopy){
	if(u8PortIdCopy <= DIO_PORTD){
		switch(u8PortIdCopy){
			case 	DIO_PORTA: PORTA = u8PinValCopy; break;
			case 	DIO_PORTB: PORTB = u8PinValCopy; break;
			case 	DIO_PORTC: PORTC = u8PinValCopy; break;
			case 	DIO_PORTD: PORTD = u8PinValCopy; break;
		}
	}
	else{}
}

void 	DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PinDirCopy){
	if(u8PortIdCopy <= DIO_PORTD){
		switch(u8PortIdCopy){
			case 	DIO_PORTA: DDRA = u8PinDirCopy; break;
			case 	DIO_PORTB: DDRB = u8PinDirCopy; break;
			case 	DIO_PORTC: DDRC = u8PinDirCopy; break;
			case 	DIO_PORTD: DDRD = u8PinDirCopy; break;
		}
	}else{}
}
