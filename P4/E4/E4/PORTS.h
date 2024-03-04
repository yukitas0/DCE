/*
 * PORTS.h
 *
 * Created: 19/02/2024 10:16:24
 *  Author: DCE
 */ 


#ifndef PORTS_H_
#define PORTS_H_

/*DEFINIMOS LOS PUERTOS QUE VAMOS A USAR*/

//Proyecto 6

//MCU port where the led is connected. mode conf register
#define GPIO01_MODE DDRD

//Pin of port where the led is connected config as output
#define LED_RED_MODE	DDD3
#define LED_GREEN_MODE	DDD4

//MCU port where the led is connected
#define GPIO01_OUT PORTD

//pull-up
#define PULL_UP PORTD2

//Proyecto 7

#define LED_GREEN PORTD4
#define LED_RED PORTD3

#define GPIO01_IN PIND
#define BUTTON PIND2

#define BIT0 DDD4
#define BIT1 DDD5
#define BIT2 DDD6
#define BIT3 DDD7


static inline void GPIO_init(){
		//1.- Set output pins
		//GPIO01_MODE |=(1<<LED_RED_MODE )|(1<<LED_GREEN_MODE );
		 GPIO01_OUT |= (1<<PULL_UP);
		 GPIO01_MODE |= (1 << BIT0) | (1 << BIT1) | (1 << BIT2) | (1 << BIT3); // Set PD3, PD4, PD5, PD6 as output pins
	
}




#endif /* PORTS_H_ */