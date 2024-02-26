/*
 * E2.c
 *
 * Created: 26/02/2024 10:13:42
 * Author : DCE
 */ 

#include <avr/io.h>
#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PORTS.h"
#include "MACROS.h"
#include "PARAMETERS.h"
#include "PORTS.h"

uint8_t volatile counter = 0;
ISR(INT0_vect) {	//si ha entrado aqui es que el botton se ha pulsado
	_delay_ms (10);
	counter++;
	counter=counter % 15;
	
}
int main(void)
{
    GPIO_init();
	
	EICRA = (1<<ISC01) |(0<<ISC00) | // INT0 is triggered by a falling edge
			(0<<ISC11) |(0<<ISC10); // INT1 is set as default value (0)
	EIMSK |= (1<<INT0); // Enable the ISR of INT0;	
	sei(); //enable global interrumps

    while (1) 
    {
		//aqui debemos de mostrar con los led el numero counter
		PORTD= (0b00000100) | ((counter << 3));	//MASK 0b 0000 0111
		_delay_ms (1000);
    }
}

