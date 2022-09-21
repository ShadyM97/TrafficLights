/*
 * led.h
 *
 * Created: 9/2/2022 1:41:12 PM
 *  Author: Shady Mohamed
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"
#include "../../MCAL/Timer Driver/timer.h"

// Car Green LED Define
#define LED_CG_PORT PORT_A
#define LED_CG_PIN PIN0
// Car Yellow LED Define
#define LED_CY_PORT PORT_A
#define LED_CY_PIN PIN1
// Car Red LED Define
#define LED_CR_PORT PORT_A
#define LED_CR_PIN PIN2
//Pedestrian Green LED Define
#define LED_PG_PORT PORT_B
#define LED_PG_PIN PIN0
//Pedestrian Yellow LED Define
#define LED_PY_PORT PORT_B
#define LED_PY_PIN PIN1
//Pedestrian Red LED Define
#define LED_PR_PORT PORT_B
#define LED_PR_PIN PIN2

extern uint8_t extintblink;

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);
void LED_blinkCar_5s(uint8_t ledPort, uint8_t ledPin,uint16_t delay,uint16_t blinkfrequency);
void LED_blinkYellow_5s(uint8_t ledPort0, uint8_t ledPin0,uint8_t ledPort1, uint8_t ledPin1,uint16_t delay,uint16_t blinkfrequency);

#endif /* LED_H_ */