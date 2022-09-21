/*
 * dio.c
 *
 * Created: 8/30/2022 5:50:02 PM
 *  Author: Shady Mohamed
 */ 

//include .h
#include "dio.h"
//global variables
//function definitions
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction)
{
	switch(portNumber)
	{
		case PORT_A:
			if (direction==IN)
			{
				//DDRA &=~(1<<pinNumber);
				CLEAR_BIT(DDRA,pinNumber);//Input
			}
			else if (direction==OUT)
			{
				//DDRA |=(1<<pinNumber);
				SET_BIT(DDRA,pinNumber);//Output
			}
			else
			{
				//Error handling
			}
		break;
		case PORT_B:
			if (direction==IN)
			{
				CLEAR_BIT(DDRB,pinNumber);//Input
			}
			else if (direction==OUT)
			{
				SET_BIT(DDRB,pinNumber);//Output
			}
			else
			{
				//Error handling
			}
		break;
		case PORT_C:
			if (direction==IN)
			{
				CLEAR_BIT(DDRC,pinNumber);//Input
			}
			else if (direction==OUT)
			{
				SET_BIT(DDRC,pinNumber);//Output
			}
			else
			{
				//Error handling
			}
		break;
		case PORT_D:
			if (direction==IN)
			{
				CLEAR_BIT(DDRD,pinNumber);//Input
			}
			else if (direction==OUT)
			{
				SET_BIT(DDRD,pinNumber); //Output
			}
			else
			{
				//Error handling
			}
			break;
	}
}

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value)
{
	switch(portNumber)
	{
		case PORT_A:
		if (value==LOW)
		{
			CLEAR_BIT(PORTA,pinNumber);//write 0
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTA,pinNumber);//write 1
		}
		else
		{
			//Error handling
		}
		break;
		case PORT_B:
		if (value==LOW)
		{
			CLEAR_BIT(PORTB,pinNumber);//write 0
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTB,pinNumber);//write 1
		}
		else
		{
			//Error handling
		}
		break;
		case PORT_C:
		if (value==LOW)
		{
			CLEAR_BIT(PORTC,pinNumber);//write 0
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTC,pinNumber);//write 1
		}
		else
		{
			//Error handling
		}
		break;
		case PORT_D:
		if (value==LOW)
		{
			CLEAR_BIT(PORTD,pinNumber);//write 0
		}
		else if (value==HIGH)
		{
			SET_BIT(PORTD,pinNumber);//write 1
		}
		else
		{
			//Error handling
		}
		break;
	}
}

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber)// Toggle DIO
{
	switch(portNumber)
	{
		case PORT_A:
		{
			TOGGLE_BIT(PORTA,pinNumber);
		}
		break;
		case PORT_B:
		{
			TOGGLE_BIT(PORTB,pinNumber);
		}
		break;
		case PORT_C:
		{
			TOGGLE_BIT(PORTC,pinNumber);
		}
		break;
		case PORT_D:
		{
			TOGGLE_BIT(PORTD,pinNumber);
		}
		break;
		default:
		{
			//Error Handling
		}
		break;
	}
}

