/*
 * button.h
 *
 * Created: 9/2/2022 3:02:32 PM
 *  Author: Shady Mohamed
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"
#define EXTERNAL_INT_BUTTON_PORT PORT_D
#define EXTERNAL_INT_BUTTON_PIN PIN2
// Button State Macros
#define LOW 0
#define HIGH 1

//initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);

//button read
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value);


#endif /* BUTTON_H_ */