/*
 * P7.c
 *
 * Created: 19/02/2024 10:09:43
 * Author : DCE
 */ 

//Headers
#include <avr/io.h>
#include <avr/delay.h>
//#include "PORTS.h"
//#include "MACROS.h"
#include "PARAMETERS.h"
//Defines

int main(void)
{
 /** ------------ SETUP ------------------------*/
 ///	1. Set pin as output for the LED
 DDRD	|= (1<<DDD3);
 ///---------------------------------------------
 /// 2. Enable pull-up for the PUSHBUTTON
 PORTD	|= (1<<PORTD2);
 /** ------------ LOOP ----------------------------------------*/
 while (1)
 {
	 ///---------------------------------------------
	 /// 1. If the pushbutton is PRESSED
	 if (!(PIND & (1 << PIND2)))
	 {
		 ///----------------------------------------------------------------
		 /// 1.1. Wait for a time to avoid the pushbutton bounce
		 _delay_ms(DEBOUNCE_TIME);
		 ///----------------------------------------------------------------
		 /// 1.2. Check if the button is NOT already PRESSED
		 if ((PIND & (1 << PIND2)))
		 {
			 ///----------------------------------------------------------------
			 /// 1.2.1. If released, do the task: change the state of the LED
			 PORTD ^= (1<< PORTD3);
			 ///----------------------------------------------------------------
			 /// 1.2.2 Wait for a time to avoid bouncing in pushbutton (release)
			 _delay_ms(DEBOUNCE_TIME);
		 }
	 }
 }
 }

