/*
 * inter.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: hosen
 */

#ifndef INTER_H_
#define INTER_H_
#include "gpio.h"

void init_interrupt(char x, char pin , char rising , char masked);
void increment(char num);
void decrement(char num);



#endif /* INTER_H_ */
