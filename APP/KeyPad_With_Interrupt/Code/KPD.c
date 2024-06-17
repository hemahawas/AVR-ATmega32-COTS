/**************************************************/
/***********	Author : Ibraheem rizk	***********/
/***********	Layer  : HAL			***********/
/***********	Component : KEYPAD		***********/
/***********	Version : 1.00			***********/
/***********	Date : 15-8/2023		***********/
/**************************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"

#include "avr/io.h"
#include <util/delay.h>
#include "KPD.h"

void KPD_voidInit(void){
	// 1. Rows: Input & pull up (high)
	DIO_SetPinDirection(KPD_PORT, KPD_R0_PIN, DIO_INPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_R1_PIN, DIO_INPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_R2_PIN, DIO_INPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_R3_PIN, DIO_INPUT);

	DIO_SetPinValue(KPD_PORT, KPD_R0_PIN, DIO_HIGH);
	DIO_SetPinValue(KPD_PORT, KPD_R1_PIN, DIO_HIGH);
	DIO_SetPinValue(KPD_PORT, KPD_R2_PIN, DIO_HIGH);
	DIO_SetPinValue(KPD_PORT, KPD_R3_PIN, DIO_HIGH);

	// 2. Columns: Output & pull up (high)Ù�Ù�
	DIO_SetPinDirection(KPD_PORT, KPD_C0_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_C1_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_C2_PIN, DIO_OUTPUT);
	DIO_SetPinDirection(KPD_PORT, KPD_C3_PIN, DIO_OUTPUT);

	DIO_SetPinValue(KPD_PORT, KPD_C0_PIN, DIO_LOW);
	DIO_SetPinValue(KPD_PORT, KPD_C1_PIN, DIO_LOW);
	DIO_SetPinValue(KPD_PORT, KPD_C2_PIN, DIO_LOW);
	DIO_SetPinValue(KPD_PORT, KPD_C3_PIN, DIO_LOW);



}

u8 KPD_u8GetPressedKey(void){
	DIO_SetPinValue(KPD_PORT, KPD_C0_PIN, DIO_HIGH);
	DIO_SetPinValue(KPD_PORT, KPD_C1_PIN, DIO_HIGH);
	DIO_SetPinValue(KPD_PORT, KPD_C2_PIN, DIO_HIGH);
	DIO_SetPinValue(KPD_PORT, KPD_C3_PIN, DIO_HIGH);
	u8 u8RowLocal=0;
	u8 u8ColLocal=0;
	u8 key_pressed;

	for(u8ColLocal=0 ; u8ColLocal < KPD_COLS_NUM ; u8ColLocal++ )
	{
		//active one column at time ---> low
		DIO_SetPinValue( KPD_PORT , KPD_C0_PIN + u8ColLocal , DIO_LOW);

		//scan R0 to R3
		for(u8RowLocal = 0 ; u8RowLocal < KPD_ROWS_NUM ; u8RowLocal++ ){
			u8 u8PinValueLocal = DIO_GetPinValue(KPD_PORT , KPD_R0_PIN + u8RowLocal );
			if( u8PinValueLocal == KPD_PRESSED_KEY )
			{
				//delay to avoid bouncing
				_delay_ms(50);
				//reread switch pin
				u8PinValueLocal = DIO_GetPinValue(KPD_PORT , KPD_R0_PIN + u8RowLocal );
				if( u8PinValueLocal == KPD_PRESSED_KEY )
				{
					//hold
					u8PinValueLocal = DIO_GetPinValue(KPD_PORT , KPD_R0_PIN + u8RowLocal );
					while( u8PinValueLocal == KPD_PRESSED_KEY  ){
						u8PinValueLocal = DIO_GetPinValue(KPD_PORT , KPD_R0_PIN + u8RowLocal );
					}
					u8 KPD_u8Value[KPD_ROWS_NUM][KPD_COLS_NUM]= KPD_VALUES;
					key_pressed = KPD_u8Value[u8RowLocal][u8ColLocal];
				}
			}
		}

		//deactivate column
		DIO_SetPinValue(KPD_PORT, KPD_C0_PIN + u8ColLocal, DIO_HIGH);
	}
	DIO_SetPinValue(KPD_PORT, KPD_C0_PIN, DIO_LOW);
	DIO_SetPinValue(KPD_PORT, KPD_C1_PIN, DIO_LOW);
	DIO_SetPinValue(KPD_PORT, KPD_C2_PIN, DIO_LOW);
	DIO_SetPinValue(KPD_PORT, KPD_C3_PIN, DIO_LOW);
	return key_pressed;
}
