#ifndef KPD_H
#define KPD_H
/* ROWS */
#define KPD_R0_PORT    DIO_PORTB
#define KPD_R0_Pin     DIO_PIN0

#define KPD_R1_PORT    DIO_PORTB
#define KPD_R1_Pin     DIO_PIN1

#define KPD_R2_PORT    DIO_PORTB
#define KPD_R2_Pin     DIO_PIN2

#define KPD_R3_PORT    DIO_PORTB
#define KPD_R3_Pin     DIO_PIN3

/* COLUMNS */
#define KPD_C0_PORT    DIO_PORTB
#define KPD_C0_Pin     DIO_PIN4

#define KPD_C1_PORT    DIO_PORTB
#define KPD_C1_Pin     DIO_PIN5

#define KPD_C2_PORT    DIO_PORTB
#define KPD_C2_Pin     DIO_PIN6

#define KPD_C3_PORT    DIO_PORTB
#define KPD_C3_Pin     DIO_PIN7

#define KPD_PRESSED_KEY         DIO_LOW
#define KPD_NOT_PRESSED_KEY     0xff

//To avoid magic numbers in KPD.c
#define ROW_NUMBER      4
#define COLUMN_NUMBER   4

//Define KPD values
#define KPD_VALUES    {{'7','8','9','/'},\
                       {'4','5','6','*'},\
					   {'1','2','3','-'},\
                       {'c','0','=','+'}}



void KPD_Init(void);
u8   KPD_GetPressedKey(void);





#endif
