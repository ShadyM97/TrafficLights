/*
 * application.h
 *
 * Created: 9/10/2022 6:19:51 PM
 *  Author: Shady Mohamed
 */ 


#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "../ECUAL/LED Driver/led.h"
#include "../ECUAL/Button Driver/button.h"
#include "../MCAL/Timer Driver/timer.h"
#include "../MCAL/Interrupt Library/interrupts.h"

void APP_init(void);
void APP_start(void);



#endif /* APPLICATION_H_ */