/*
 * Proyecto 8.c
 *
 * Created: 19/02/2024 12:02:57
 * Author : DCE
 */ 

#define  F_CPU	16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#include "PORTS.h"
#include "PARAMETERS.h"
#include "MACROS.h"

bool GPIO_readButton (void){
	bool buttonPressed = !BUTTON_PRESSED;
	///---------------------------------------------
	/// 1. If the pushbutton is PRESSED
	if ((READ_PIN(GPIO01_IN,BUTTON))==BUTTON_PRESSED)
	{
		///----------------------------------------------------------------
		/// 1.1. Wait for a time to avoid the pushbutton bounce
		_delay_ms(DEBOUNCE_TIME);
		///----------------------------------------------------------------
		/// 1.2. Check if the button is NOT already PRESSED
		if (READ_PIN(GPIO01_IN,BUTTON)!=BUTTON_PRESSED)
		{
			///----------------------------------------------------------------
			/// 1.2.1. If released, do the task: change the state of the LED
			buttonPressed = BUTTON_PRESSED;
			///----------------------------------------------------------------
			/// 1.2.2 Wait for a time to avoid bouncing in pushbutton (release)
			_delay_ms(DEBOUNCE_TIME);
		}
	}
	return buttonPressed;
}

//---------  User data types definitions -------------
typedef enum {
	STATE_LED_GREEN,
	STATE_LED_RED,
	STATE_LED_OFF
} LEDStates_t;


int main(void)
{
	bool readButton = !BUTTON_PRESSED;

	//---------  Local variables (Registers) -----------------
	/// Variables to keep the state of the FSM
	LEDStates_t currentState = STATE_LED_OFF;
	LEDStates_t nextState	  = STATE_LED_OFF;
	
	// ------------ SETUP ------------------------
	GPIO_init();
	//------------ LOOP -------------------------------------
	while (1)
	{
		// -----------------------------------------------
		// 1.- Event
		// -----------------------------------------------
		readButton = GPIO_readButton();
		// -----------------------------------------------
		// 2.- Transitions
		// -----------------------------------------------
		switch(currentState){
			case STATE_LED_OFF:
			if (readButton==BUTTON_PRESSED){
				nextState=STATE_LED_GREEN;
			}
			break;
			
			case STATE_LED_GREEN:
			if (readButton==BUTTON_PRESSED){
				nextState=STATE_LED_RED;
			}
			
			break;
			
			case STATE_LED_RED:
			if (readButton==BUTTON_PRESSED){
				nextState=STATE_LED_OFF;
			}
			break;
			
			default:
			nextState=STATE_LED_OFF;
			break;
		}
		// -----------------------------------------------
		// 3. Outputs
		// -----------------------------------------------
		switch(currentState){
			case STATE_LED_GREEN:
			SETBIT(GPIO01_OUT,LED_GREEN);
			CLEARBIT(GPIO01_OUT,LED_RED);
			break;
			
			case STATE_LED_RED:
			SETBIT(GPIO01_OUT,LED_RED);
			CLEARBIT(GPIO01_OUT,LED_GREEN);
			break;
			
			case STATE_LED_OFF:
			CLEARBIT(GPIO01_OUT,LED_GREEN);
			CLEARBIT(GPIO01_OUT,LED_RED);
			break;
			
			default:
			CLEARBIT(GPIO01_OUT,LED_GREEN);
			CLEARBIT(GPIO01_OUT,LED_RED);
			break;
		}


		currentState = nextState;


	}
}


