#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO.h"
#include "avr/io.h"
#include "USART.h"

void UART_Init(void)
{
	// Set Baud Rate 9600
	UBRRL=51;
	UBRRH = 0;

	// Set Frame Format -> 8 data, 1 stop, No Parity
	//  Word Size [8 bits], By default = 8 bits
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
	CLR_BIT(UCSRB,UCSZ2);

	//Disable Parity
	CLR_BIT(UCSRC,UPM0);
	CLR_BIT(UCSRC,UPM1);

	//Stop bit --> 1 bit
	CLR_BIT(UCSRC,USBS);

	/*	u8 u8UCSRCValue_Local = 0;
	SET_BIT( u8UCSRCValue_Local , 7);
	SET_BIT( u8UCSRCValue_Local , UCSZ1);
	SET_BIT( u8UCSRCValue_Local , UCSZ0);
    UCSRC =  u8UCSRCValue_Local ; */

	//Enable TX ,RX
	SET_BIT( UCSRB,TXEN);
	SET_BIT( UCSRB,RXEN);

}


void USART_SendData(u8 u8data_Copy)
{
	// step 1 : wait flag UDRFE to finish
	// Wait until transmission Register Empty
	while(GET_BIT(UCSRA , UDRE) == 0);

	// step 2 : send Data
	UDR = u8data_Copy; //UDR is buffer register
}


u8   USART_ReceiveData(void)
{
	// step 1 : wait flag RXC to finish
	while(GET_BIT(UCSRA,RXC)==0) ;
	// step 2 : Receive Data
	return UDR ;
}
