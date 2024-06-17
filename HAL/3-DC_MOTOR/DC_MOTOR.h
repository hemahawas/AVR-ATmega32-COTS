#include "STD_TYPES.h"
#include "DIO.h"

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

// configuration
#define MOTOR_PORT	DIO_PORTA
#define MOTOR_ENA	DIO_PIN0
#define MOTOR_IN1	DIO_PIN1
#define MOTOR_IN2	DIO_PIN2


void MOTOR_Init(void);
void MOTOR_CWMotion(void);
void MOTOR_CCWMotion(void);
void MOTOR_StopMotion(void);


#endif /* DC_MOTOR_H_ */