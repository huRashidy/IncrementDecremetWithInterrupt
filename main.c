/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/

#include "stm32f4xx.h"
#include"gpio.h"
#include "inter.h"

//void (*ptrToFunction)(void)= 0x00000058;

int main(void)
{

	// Enable clock Access to GPIOA,GPIOB

	RCC->AHB1ENR|=(1u<<0);
	RCC->AHB1ENR|=(1u<<1);

	GPIO_Initialize (GPIOB,4,0,1);
	GPIO_Initialize (GPIOB,5,0,1);

	//Set pins 0,1,2,3 port A as output
	GPIO_Initialize (GPIOA,0,1,1);
	GPIO_Initialize (GPIOA,1,1,1);
	GPIO_Initialize (GPIOA,2,1,1);
	GPIO_Initialize (GPIOA,3,1,1);


	////Set pin 0 port B into pull up mode
	GPIOB->PUPDR |=(1u<<0);

	//port A--->0
	//port B--->1
	//port C--->2
	//port D--->3
	//init_interrupt(char x, char pin , char rising , char masked);

	init_interrupt(1,4,1,0);
	init_interrupt(1,5,1,0);


	while(1)
	{

	}


}

void EXTI0_IRQHandler(void){
	char number=0;
	if(GPIO_ReadPin(GPIOB,4)==1){
		increment(number);
		}
	else if ((GPIO_ReadPin(GPIOB,5)==1) && (number!=0)){
		decrement(number);
	}
}
