

#ifndef SVN_SEG_H_
#define SVN_SEG_H_

#define SVN_SEG_PORT            DIO_PORTA

#define SVN_SEG_NUMBER_0        0b00111111
#define SVN_SEG_NUMBER_1        0b00000110
#define SVN_SEG_NUMBER_2        0b01011011
#define SVN_SEG_NUMBER_3        0b01001111
#define SVN_SEG_NUMBER_4        0b01100110
#define SVN_SEG_NUMBER_5        0b01101101
#define SVN_SEG_NUMBER_6        0b01111101
#define SVN_SEG_NUMBER_7        0b00000111
#define SVN_SEG_NUMBER_8        0b01111111
#define SVN_SEG_NUMBER_9        0b01101111
#define SVN_SEG_TURN_OFF        0x00
void SVN_SEG_WriteOn7Segment(u8 u8LcdValCopy);

void SVN_SEG_Init();

#endif /* SVN_SEG_H_ */
