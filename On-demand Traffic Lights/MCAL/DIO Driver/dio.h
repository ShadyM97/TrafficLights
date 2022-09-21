/*
 * dio.h
 *
 * Created: 8/30/2022 5:50:10 PM
 *  Author: Shady Mohamed
 */ 


#ifndef DIO_H_
#define DIO_H_
//include registers.h
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_manipulation.h"
//all internal typedefs
//all driver macros
#define PORT_A 'A'
#define PORT_B 'B'
#define PORT_C 'C'
#define PORT_D 'D'

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7
//Direction defines
#define IN 0
#define OUT 1

//Value defines
#define LOW 0
#define HIGH 1
//function prototypes
void DIO_init(uint8_t portNumber, uint8_t pinNumber, uint8_t direction); //Initialize DIO Directions

void DIO_write(uint8_t portNumber, uint8_t pinNumber, uint8_t value);//Write Data to DIO

void DIO_toggle(uint8_t portNumber, uint8_t pinNumber);// Toggle DIO

void DIO_read(uint8_t portNumber, uint8_t pinNumber,uint8_t *value);// Read DIO



#endif /* DIO_H_ */