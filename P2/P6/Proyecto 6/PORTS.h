/*
 * PORTS.h
 *
 * Created: 19/02/2024 9:30:35
 *  Author: DCE
 */ 


#ifndef PORTS_H_
#define PORTS_H_

/*DEFINIMOS LOS PUERTOS QUE VAMOS A USAR*/

//MCU port where the led is connected. mode conf register
#define GPIO01_MODE DDRB

//Pin of port where the led is connected config as output
#define LED_MODE DDB5

//MCU port where the led is connected
#define GPIO01_OUT PORTB

//Pin where the led is connected
#define LED  PORTB5


static inline void GPIO_init(){
	//1.- Set output pins 
	GPIO01_MODE |=(1<<LED_MODE);
}

#endif /* PORTS_H_ */