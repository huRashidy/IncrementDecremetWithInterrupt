/*
 * gpio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: hosen
 */

#ifndef GPIO_H_
#define GPIO_H_

void GPIO_Initialize (GPIO_TypeDef * GPIOx,char pin,char dir,char enable_pin);
char GPIO_WritePin(GPIO_TypeDef * GPIOx,char pin,char state);
char GPIO_ReadPin(GPIO_TypeDef * GPIOx,char pin);

#endif /* GPIO_H_ */
