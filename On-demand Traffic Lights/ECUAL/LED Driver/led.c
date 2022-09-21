/*
 * led.c
 *
 * Created: 9/2/2022 1:40:59 PM
 *  Author: Shady Mohamed
 */ 
#include "led.h"

uint8_t extintblink=0; //Flag for external interrupt of blink

void LED_init(uint8_t ledPort, uint8_t ledPin) //output device
{
	DIO_init(ledPort,ledPin,OUT);
}
void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort,ledPin,LOW);
}
void LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle(ledPort,ledPin);
}

//Function that makes Car LED blink for the amount of delay given
void LED_blinkCar_5s(uint8_t ledPort, uint8_t ledPin,uint16_t delay,uint16_t blinkfrequency) 
{
	uint8_t i=0;
	uint16_t blink_counter=delay/1000;
	while(i<blink_counter && extintblink==0)
	{
		LED_on(ledPort,ledPin);
		timer0_delay_ms(blinkfrequency); // To get half the amount of delay
		LED_off(ledPort,ledPin);
		timer0_delay_ms(blinkfrequency);
		i++;
	}	
	extintblink=0;
	
	
}

//Function that makes Car and Pedestrian LED blink for the amount of delay given and the blinkfrequency in seconds
void LED_blinkYellow_5s(uint8_t ledPort0, uint8_t ledPin0,uint8_t ledPort1, uint8_t ledPin1,uint16_t delay,uint16_t blinkfrequency) 
{
	uint8_t i=0;
	uint16_t blink_counter=delay/1000;
	while(i<blink_counter)
	{
		LED_on(ledPort0,ledPin0);
		LED_on(ledPort1,ledPin1);
		timer0_delay_ms(blinkfrequency); // To get half the amount of delay
		LED_off(ledPort0,ledPin0);
		LED_off(ledPort1,ledPin1);
		timer0_delay_ms(blinkfrequency);
		i++;
		
	}
}