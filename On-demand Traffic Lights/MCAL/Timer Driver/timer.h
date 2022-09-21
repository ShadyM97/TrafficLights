/*
 * timer.h
 *
 * Created: 9/10/2022 6:41:01 PM
 *  Author: Shady Mohamed
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
#include "../../Utilities/types.h"

#define  CPU_CLOCK 1 //CPU frequency Clock = 1MHz 

extern uint8_t extinterrupt;

void timer_init(void);
void timer0_delay_ms(uint16_t delay);



#endif /* TIMER_H_ */