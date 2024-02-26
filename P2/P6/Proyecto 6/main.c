/*
 * Proyecto 6.c
 *
 * Created: 19/02/2024 9:29:14
 * Author : DCE
 */ 

//Headers
#include <avr/io.h>
#include <util/delay.h>
#include "PORTS.h"
#include "MACROS.h"

//Defines
#define BLINK_TIME 1000

int main(void)
{
	//INIT 
	GPIO_init();
    /* Replace with your application code */
    while (1) 
    {
			/// 1) LED OFF by clearing the pin PB5
			/*PORTB &=~(1<<PORTB5);
			GPIO01 &=~(1<<LED);*/
			CLEARBIT(GPIO01_OUT,LED);
			/// 2) Delay of TIME milli-seconds
			_delay_ms(BLINK_TIME);
			/// 3) LED ON by setting the pin PB5
			/*PORTB |=(1<<PORTB5);*/
			SETBIT(GPIO01_OUT,LED);
			/// 4) Delay of TIME milli-seconds
			_delay_ms(BLINK_TIME);
    }
}

