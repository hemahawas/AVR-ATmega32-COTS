/*
 * DIO.h
 *
 *  Created on: Aug 10, 2023
 *      Author: HemaHawas
 */

#ifndef DIO_H_
#define DIO_H_

/*PORT Defines*/
#define DIO_PORTA	0
#define DIO_PORTB 	1
#define DIO_PORTC 	2
#define DIO_PORTD 	3

/*PIN Defines*/
#define DIO_PIN0 	0
#define DIO_PIN1 	1
#define DIO_PIN2 	2
#define DIO_PIN3 	3
#define DIO_PIN4 	4
#define DIO_PIN5 	5
#define DIO_PIN6 	6
#define DIO_PIN7 	7

/*PIN Directions*/
#define DIO_INPUT	0
#define DIO_OUTPUT	1

/*PORT Directions*/
#define DIO_INPUT_BYTE 0
#define DIO_OUTPUT_BYTE 0xFF


/*PIN Value Options*/
#define DIO_LOW		0
#define DIO_HIGH	1

/*PORT value Options*/
#define DIO_LOW_BYTE 0
#define DIO_HIGH_BYTE 0xFF

/*Prototypes of Function IO Pins*/
/*IO Pins*/
void 	DIO_SetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinValCopy);

void 	DIO_SetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy, u8 u8PinDirCopy);

u8 		DIO_GetPinValue(u8 u8PortIdCopy, u8 u8PinIdCopy);

u8		DIO_GetPinDirection(u8 u8PortIdCopy, u8 u8PinIdCopy);


/*IO Ports*/
void 	DIO_SetPortValue(u8 u8PortIdCopy, u8 u8PinValCopy);

void 	DIO_SetPortDirection(u8 u8PortIdCopy, u8 u8PinDirCopy);

u8 		DIO_GetPortValue(u8 u8PortIdCopy);

#endif /* DIO_H_ */
