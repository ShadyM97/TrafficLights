/*
 * timer.c
 *
 * Created: 9/10/2022 6:40:51 PM
 *  Author: Shady Mohamed
 */ 
#include "timer.h"

uint8_t extinterrupt=0;

void timer_init(void)
{
	//Choose Timer Mode
	TCCR0=0x00; //Normal Mode
	//Timer set initial value
	TCNT0=0x00;
}

void timer0_delay_ms(uint16_t delay)
{

		uint16_t prescaler=1; // Assume No Prescaler
	
	float T_tick,T_maxdelay;
	float overflowcounter=0.0,num_overflows;
	uint8_t initialValue=0;
	//Calculate T_tick
	T_tick=prescaler/(CPU_CLOCK*1e3); //Result in ms
	//Calculate T_maxdelay
	T_maxdelay=T_tick*256; // Calculate Maximum Delay
	//Calculate number of overflows
	num_overflows=(delay)/(T_maxdelay); // Calculate number of overflows
	//Calculate initial Value
	initialValue=256-(delay/T_tick)/num_overflows; //Calculate Timer Initial Value
	TCNT0=(int)initialValue; // Set Initial Value
	//Timer start -> set prescaler
	TCCR0|=(1<<0);
	
	//While loop to cycle through the delay as long as the ISR is not called
	while(overflowcounter<num_overflows && extinterrupt==0)
	{
		//wait until the overflow flag to be set
	while((TIFR &(1<<0)) == 0);
	
	//Clear the overflow flag
	SET_BIT(TIFR,0);
	
	overflowcounter++;
	}
	extinterrupt=0;
	overflowcounter=0;
	
	
	//Timer Stop
	TCCR0=0x00;
}