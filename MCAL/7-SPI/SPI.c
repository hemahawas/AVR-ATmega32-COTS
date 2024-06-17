#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "avr/io.h"
#include "SPI.h"






void SPI_InitMaster(void){
	/* Master initlization */
	SET_BIT(SPCR , MSTR );

	/* CLK prescaler : divide by 16 */
	SET_BIT(SPCR , SPR0);
	CLR_BIT(SPCR , SPR1);
	CLR_BIT(SPSR , SPI2X);

	/* SPI Enable*/
	SET_BIT(SPCR , SPE);

}
void SPI_InitSlave(void){
	/* Slave initlization */
	CLR_BIT(SPCR , MSTR );

	/* SPI Enable*/
	SET_BIT(SPCR , SPE);

}
u8   SPI_transceive(u8 u8Data_copy){

	/*  send the data  */
	SPDR = u8Data_copy;

	/*  Wait (busy wait ) until transfer complete */
	while((GET_BIT(SPSR , SPIF)) == 0 );

	/*  Get  the exchange  data   */
	return SPDR;


}
