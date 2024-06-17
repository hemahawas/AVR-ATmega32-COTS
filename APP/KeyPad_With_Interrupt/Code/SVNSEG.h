/*
 * SVNSEG.h
 *
 *  Created on: Aug 17, 2023
 *      Author: HemaHawas
 */

#ifndef SVNSEG_H_
#define SVNSEG_H_


#define SVNSEG_0	0b00111111
#define SVNSEG_1	0b00000110
#define SVNSEG_2	0b01011011
#define SVNSEG_3	0b01001111
#define SVNSEG_4	0b01100110
#define SVNSEG_5	0b01101101
#define SVNSEG_6	0b01111101
#define SVNSEG_7	0b00000111
#define SVNSEG_8	0b01111111
#define SVNSEG_9	0b01101111

void SVNSEG_voidInit(void);
void SVN_SEG_WriteOn7Segment(u8 u8LcdValCopy);
#endif /* SVNSEG_H_ */
