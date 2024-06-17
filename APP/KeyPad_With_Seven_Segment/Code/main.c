

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO.h"

#include "KPD.h"
#include "avr/io.h"
#include "util/delay.h"
#include "SVN_SEG.h"



void main(void){
	KPD_Init();
	SVN_SEG_Init();

	while(1){
		u8 key = KPD_GetPressedKey();
		if(key != KPD_NOT_PRESSED_KEY){
			SVN_SEG_WriteOn7Segment(key);
		}
	}
}

