
#ifndef KPD_H_
#define KPD_H_

// KEYPAD Port
#define KPD_PORT		DIO_PORTB

// Rows
#define KPD_R0_PIN		DIO_PIN0
#define KPD_R1_PIN		DIO_PIN1
#define KPD_R2_PIN		DIO_PIN2
#define KPD_R3_PIN		DIO_PIN3

// Columns
#define KPD_C0_PIN		DIO_PIN4
#define KPD_C1_PIN		DIO_PIN5
#define KPD_C2_PIN		DIO_PIN6
#define KPD_C3_PIN		DIO_PIN7

// Pressed or not
#define KPD_PRESSED_KEY			DIO_LOW
#define KPD_NOT_PRESSED_KEY		0xff

//Rows and Columns number
#define KPD_ROWS_NUM	4
#define KPD_COLS_NUM	4


// Define KPD values
#define KPD_VALUES	{{'7', '8', '9', '/'},\
					 {'4', '5', '6', '*'},\
					 {'1', '2', '3', '-'},\
					 {'c', '0', '=', '+'}}


void KPD_voidInit(void);

u8 KPD_u8GetPressedKey(void);

#endif /* KPD_H_ */
