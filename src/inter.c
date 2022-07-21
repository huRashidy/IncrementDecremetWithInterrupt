/*
 * inter.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: hosen
 */


/*
 * inter.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: hosen
 */
#include "inter.h"
#include "stm32f4xx.h"
void init_interrupt(char port, char pin , char falling , char masked){
	//port A--->0
	//port B--->1
	//port C--->2
	//port D--->3


	// Enable clock access to sysconf
		RCC->APB2ENR|=(1u<<14);

		// Set Selection lines of EXTI0 port B pin 4
		if(pin<4){
			SYSCFG->EXTICR[1] |=(pin*4<<port);
		}
		else if(pin<8){
			SYSCFG->EXTICR[2] |=((pin-4)*4<<port);
		}
		else if (pin<12){
			SYSCFG->EXTICR[3] |=((pin-8)*4<<port);
		}
		else if(pin<16){
			SYSCFG->EXTICR[3] |=((pin-12)*4<<port);
		}

		// Configure the mask bit of exitpin
		if (masked==1){
		EXTI->IMR &=~(1u<<pin);
		}
		else EXTI->IMR |=(1u<<pin);

		// Configure the Trigger  as falling trigger
		if (falling == 1){
		EXTI->FTSR |=(1u<<pin);
		}
		else if (falling ==0){
		EXTI->FTSR &=~(1u<<pin);
		}
		// enable EXTIPIN interrupt from NVIC
		NVIC->ISER[port]|=(1u<<pin+6);
		//NVIC->ICER[0]|=(1u<<6);
}
void increment(char num){
	num++;
	GPIO_Write(GPIOA,0,(num&(1<<0))  >>0 );
	GPIO_Write(GPIOA,1,(num&(1<<1))  >>1 );
	GPIO_Write(GPIOA,2,(num&(1<<2))   >>2  );
	GPIO_Write(GPIOA,3,(num&(1<<3))   >>3  );
}
void decrement(char num){
	num--;
	GPIO_Write( GPIOA,0,(num&(1<<0))  >>0 );
	GPIO_Write(GPIOA,1,(num&(1<<1))  >>1 );
	GPIO_Write(GPIOA,2,(num&(1<<2))   >>2  );
	GPIO_Write(GPIOA,3,(num&(1<<3))   >>3  );
}

