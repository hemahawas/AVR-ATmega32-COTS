#include "BIT_MATH.h"
#include "avr/io.h"
#include "EXTI.h"




void    EXTI_void_Int0Init(void){
	// Set Sense control for INT0  to falling edge
	  SET_BIT(MCUCR , MCUCR_ISC01);
	  CLR_BIT(MCUCR , MCUCR_ISC00);

	// PIE --> Enable forINT0
	  SET_BIT(GICR , GICR_INT0);


}
void    EXTI_void_Int1Init(void){
//TODO
}
void    EXTI_void_Int2Init(void){
//TODO

}



