/*
 * button.c
 *
 * Created: 9/2/2022 3:02:21 PM
 *  Author: Shady Mohamed
 */ 

#include "button.h"



//Initialize
void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	DIO_init(buttonPort,buttonPin,IN);
}

//button read
void BUTTON_read(uint8_t buttonPort, uint8_t buttonPin, uint8_t *value)
{	
	DIO_read(buttonPort,buttonPin,value);
}
