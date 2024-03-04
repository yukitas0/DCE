/*
 * E4.c
 *
 * Created: 04/03/2024 11:11:31
 * Author : DCE
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "USART.h"
#include "PORTS.h"
#include "MACROS.h"
#include "PARAMETERS.h"
#include "EXT_INT.h"

ISR(INT0_vect) {	//si ha entrado aqui es que el botton se ha pulsado
	_delay_ms (10);
	
	static char datum=0x21;
	
	//if(is_tx_AVALIABLE){}
	if(UCSR0A & (1<<UDRE0)){
			UDR0=datum;
	}
	
	/*
	#if 0
		USART0_putchar(datum);
	#endif
	*/
	
		
	//USART0_putchar(datum);
		
	if(datum >= 0x7F ){
		datum = 0x21; //Like module
		USART0_putString("/f");
	}
	
		
	else
		datum++;	//increment if else 
	
}

ISR(USART_RX_vect){
	GPIO01_OUT=(GPIO01_OUT&0b00001111)|((UDR0 & 0x0F)<<BIT0);
}

int main(void)
{
		
		GPIO_init();
		
		//INT0
		// Configurar INT0 con trigger en falling edge
		INT0_config(FALLING);
		// Habilitar INT0
		INT0_enable();
		
		//USART SETUP
		USART0_init(UBRR_VALUE);
		USART0_enaInterrupt_RX();
		
		sei(); //enable global interrumps
		
		
		uint8_t counter =0;
		while (1) 
		{
		
		}
}


/*
ISR(USART_UDRE_vect){
	static char* strPointer="Hello World\n\r;"
	
	if(*strPointer!=0){
		UDR0=*strPointer;
		strPointer++;
	}
	else{
		
		USART0_disableInterrupt_TX();
		strPointer="HelloWorld\n\r";
	}
}
*/


