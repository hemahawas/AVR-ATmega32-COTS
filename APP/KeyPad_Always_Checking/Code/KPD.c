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
#include "util/delay.h"
#include "KPD.h"


void KPD_Init(void){
	//step 1 : configure Rows Direction -> internal pull up -> input ,value -> high
	DIO_SetPinDirection(KPD_R0_PORT,KPD_R0_Pin,DIO_INPUT);
	DIO_SetPinDirection(KPD_R1_PORT,KPD_R1_Pin,DIO_INPUT);
	DIO_SetPinDirection(KPD_R2_PORT,KPD_R2_Pin,DIO_INPUT);
	DIO_SetPinDirection(KPD_R3_PORT,KPD_R3_Pin,DIO_INPUT);

	DIO_SetPinValue(KPD_R0_PORT,KPD_R0_Pin,DIO_HIGH);
	DIO_SetPinValue(KPD_R1_PORT,KPD_R1_Pin,DIO_HIGH);
	DIO_SetPinValue(KPD_R2_PORT,KPD_R2_Pin,DIO_HIGH);
	DIO_SetPinValue(KPD_R3_PORT,KPD_R3_Pin,DIO_HIGH);

	//step 1 : configure Colums Direction  -> output ,value -> high
	DIO_SetPinDirection(KPD_C0_PORT,KPD_C0_Pin,DIO_OUTPUT);
	DIO_SetPinDirection(KPD_C1_PORT,KPD_C1_Pin,DIO_OUTPUT);
	DIO_SetPinDirection(KPD_C2_PORT,KPD_C2_Pin,DIO_OUTPUT);
	DIO_SetPinDirection(KPD_C3_PORT,KPD_C3_Pin,DIO_OUTPUT);

	DIO_SetPinValue(KPD_C0_PORT,KPD_C0_Pin,DIO_HIGH);
	DIO_SetPinValue(KPD_C1_PORT,KPD_C1_Pin,DIO_HIGH);
	DIO_SetPinValue(KPD_C2_PORT,KPD_C2_Pin,DIO_HIGH);
	DIO_SetPinValue(KPD_C3_PORT,KPD_C3_Pin,DIO_HIGH);


}
u8   KPD_GetPressedKey(void){

	u8 u8RowLocal=0;
	u8 u8ColLocal=0;

	u8 KPD_u8RowPortArr[ROW_NUMBER] = { KPD_R0_PORT , KPD_R1_PORT , KPD_R2_PORT , KPD_R3_PORT };
	u8 KPD_u8RowPinArr [ROW_NUMBER] = { KPD_R0_Pin  , KPD_R1_Pin ,  KPD_R2_Pin ,  KPD_R3_Pin } ;


	u8 KPD_u8ColPortArr[COLUMN_NUMBER] = { KPD_C0_PORT , KPD_C1_PORT , KPD_C2_PORT , KPD_C3_PORT };
	u8 KPD_u8ColPinArr [COLUMN_NUMBER] = { KPD_C0_Pin  , KPD_C1_Pin , KPD_C2_Pin , KPD_C3_Pin } ;

	for(u8ColLocal=0 ; u8ColLocal < COLUMN_NUMBER ; u8ColLocal ++ )
	{
		//active one columne at time ---> low
		DIO_SetPinValue( KPD_u8ColPortArr[u8ColLocal] , KPD_u8ColPinArr[u8ColLocal] , DIO_LOW);

		//scan R0 to R3
		for(u8RowLocal = 0 ; u8RowLocal < ROW_NUMBER ; u8RowLocal++ ){
			u8 u8PinValueLocal = DIO_GetPinValue(KPD_u8RowPortArr[u8RowLocal] , KPD_u8RowPinArr[u8RowLocal] );
			if( u8PinValueLocal == KPD_PRESSED_KEY )
			{ //delay to avoid bouncing
				_delay_ms(50);
				//reread switch pin
				u8PinValueLocal = DIO_GetPinValue(KPD_u8RowPortArr[u8RowLocal] , KPD_u8RowPinArr[u8RowLocal] );
				if( u8PinValueLocal == KPD_PRESSED_KEY )
				{
					//hold
					u8PinValueLocal = DIO_GetPinValue(KPD_u8RowPortArr[u8RowLocal] , KPD_u8RowPinArr[u8RowLocal] );
					while( u8PinValueLocal == KPD_PRESSED_KEY  ){
						u8PinValueLocal = DIO_GetPinValue(KPD_u8RowPortArr[u8RowLocal] , KPD_u8RowPinArr[u8RowLocal] );
					}
					u8 KPD_u8Value[ROW_NUMBER][COLUMN_NUMBER]= KPD_VALUES;
					return KPD_u8Value[u8RowLocal][u8ColLocal] ;
				}

			}

		}
		//deactivate column
			DIO_SetPinValue(KPD_u8ColPortArr[u8ColLocal],KPD_u8ColPinArr[u8ColLocal],DIO_HIGH);


	}

return KPD_NOT_PRESSED_KEY ;
}



