#ifndef SPI_H_
#define SPI_H_

/* SPI */

/* SPI Control Register SPCR */
#define    SPIE         7
#define    SPE          6
#define    DORD         5
#define    MSTR         4
#define    CPOL         3
#define    CPHA         2
#define    SPR1         1
#define    SPR0         0


/* SPI Status Register SPSR  */
#define    SPIF         7
#define    WCOL         6
#define    SPI2X        0


/* SPI I/O Data Register SPDR */

//ProtoTypes :
void SPI_InitMaster(void);
void SPI_InitSlave(void);
u8   SPI_transceive(u8 u8Data_copy);


#endif /* SPI_H_ */
