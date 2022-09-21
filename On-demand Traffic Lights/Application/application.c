/*
 * application.c
 *
 * Created: 9/10/2022 6:19:37 PM
 *  Author: Shady Mohamed
 */

#include "application.h"

uint8_t mode=0; // Flag for pedestrian state
uint8_t carRed=0,carYellow=0,carGreen=0; // Flags for car state
uint8_t extintpress=0; //Flag for external interrupt press


void APP_init(void)
{
	//Initialize External Interrupt Button
	
	BUTTON_init(EXTERNAL_INT_BUTTON_PORT,EXTERNAL_INT_BUTTON_PIN);
	
	//Initialize CAR LEDS
	
	LED_init(LED_CG_PORT,LED_CG_PIN);
	LED_init(LED_CY_PORT,LED_CY_PIN);
	LED_init(LED_CR_PORT,LED_CR_PIN);
	
	//Initialize PEDESTRIAN LEDS
	
	LED_init(LED_PG_PORT,LED_PG_PIN);
	LED_init(LED_PY_PORT,LED_PY_PIN);
	LED_init(LED_PR_PORT,LED_PR_PIN);
	
	//Initialize Timer
	
	timer_init();
	
	//Initialize External Interrupt
	/*Enable Global Interrupt*/
	
	sei();
	
	/*Set INT0 to sense Rising Edge*/
	
	MCUCR|=(1<<0)|(1<<1);
	
	/* Enable External Interrupt 0 - INT0*/
	
	GICR|=(1<<6);
	
}


void APP_start(void)
{
	while(1)
	{
		switch(mode)
		{
			case 0: //Normal Mode
			extintpress=0;
			extintblink=0;
			carGreen=1;
			LED_on(LED_CG_PORT,LED_CG_PIN); //Turn on Car Green LED
			timer0_delay_ms(5000);
			LED_off(LED_CG_PORT,LED_CG_PIN); //Turn off Car Green LED
		if(mode==1)
		break;	
			carGreen=0;
			carYellow=1;
			LED_blinkCar_5s(LED_CY_PORT,LED_CY_PIN,5000,500); //Blink Car Yellow LED
		if(mode==1)
		break;
			carYellow=0;
			carRed=1;
			LED_on(LED_CR_PORT,LED_CR_PIN); //Turn on Car Red LED
			timer0_delay_ms(5000);
		if(mode==1)
		break;
			carRed=0;
			LED_off(LED_CR_PORT,LED_CR_PIN); //Turn off Car Red LED
			carYellow=1;
			LED_blinkCar_5s(LED_CY_PORT,LED_CY_PIN,5000,500); //Blink Car Yellow LED
		if(mode==1)
		break;
		carYellow=0;
		break;
			case 1: //Pedestrian Mode 
			/*1 if Car Green LED is on*/
			extinterrupt=0;
			if (carGreen==1)
			{
				LED_on(LED_CG_PORT,LED_CG_PIN); //Turn on Car Green LED
				LED_on(LED_PR_PORT,LED_PR_PIN); //Turn on Pedestrian Red LED
				timer0_delay_ms(5000);
				LED_off(LED_CG_PORT,LED_CG_PIN); //Turn on Car Green LED
				LED_off(LED_PR_PORT,LED_PR_PIN); //Turn on Pedestrian Red LED				
				LED_blinkYellow_5s(LED_CY_PORT,LED_CY_PIN,LED_PY_PORT,LED_PY_PIN,5000,500); //Blink Car and Pedestrian Yellow LED
				LED_on(LED_CR_PORT,LED_CR_PIN); //Turn on Car Red LED
				LED_on(LED_PG_PORT,LED_PG_PIN); //Turn on Pedestrian Green LED
				timer0_delay_ms(5000);
				LED_off(LED_CR_PORT,LED_CR_PIN);//Turn off Car Red LED
				LED_off(LED_PG_PORT,LED_PG_PIN);//Turn off Pedestrian Green LED
				LED_blinkYellow_5s(LED_CY_PORT,LED_CY_PIN,LED_PY_PORT,LED_PY_PIN,5000,500); //Blink Car and Pedestrian Yellow LED
				carGreen=0;
				mode=0;
			}
			/*if Car Yellow LED is on*/
			else if (carYellow==1)
			{
				LED_blinkYellow_5s(LED_CY_PORT,LED_CY_PIN,LED_PY_PORT,LED_PY_PIN,5000,500); //Blink Car and Pedestrian Yellow LED
				LED_on(LED_CR_PORT,LED_CR_PIN); //Turn on Car Red LED
				LED_on(LED_PG_PORT,LED_PG_PIN); //Turn on Pedestrian Green LED
				timer0_delay_ms(5000);
				LED_off(LED_CR_PORT,LED_CR_PIN); //Turn off Car Red LED
				LED_off(LED_PG_PORT,LED_PG_PIN); //Turn off Pedestrian Green LED
				LED_blinkYellow_5s(LED_CY_PORT,LED_CY_PIN,LED_PY_PORT,LED_PY_PIN,5000,500);
				carYellow=0;
				mode=0;
			}
			else if (carRed==1)
			{
				LED_on(LED_CR_PORT,LED_CR_PIN);//Turn on Car Red LED
				LED_on(LED_PG_PORT,LED_PG_PIN); //Turn on Pedestrian Green LED
				timer0_delay_ms(5000);
				LED_off(LED_CR_PORT,LED_CR_PIN);//Turn off Car Red LED
				LED_off(LED_PG_PORT,LED_PG_PIN); //Turn off Pedestrian Green LED
				LED_blinkYellow_5s(LED_CY_PORT,LED_CY_PIN,LED_PY_PORT,LED_PY_PIN,5000,500); //Blink Car and Pedestrian Yellow LED
				carRed=0;
				mode=0;
			}
			else
			{
				
			}
			break;
			
			default:
			
			break;
		}
	}
}

ISR(EXT_INT_0)
{
	if (extintpress==0)
	{	
		extinterrupt=1;//Flag used to stop timer
		mode=1;//Flag to go to pedestrian mode
		extintpress=1;//Flag used to accept only one press until the code goes back to normal mode
		extintblink=1;//Flag used to stop blinking Car Yellow in normal mode
	}
	else
	{
		
	}

}

