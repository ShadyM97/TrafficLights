/*
 * bit_manipulation.h
 *
 * Created: 9/2/2022 2:42:11 PM
 *  Author: Shady Mohamed
 */ 


#ifndef BIT_MANIPULATION_H_
#define BIT_MANIPULATION_H_

#define SET_BIT(x,bit) (x |=(1<<bit))
#define CLEAR_BIT(x,bit) (x &=~(1<<bit))
#define TOGGLE_BIT(x,bit) (x ^=(1<<bit))



#endif /* BIT_MANIPULATION_H_ */