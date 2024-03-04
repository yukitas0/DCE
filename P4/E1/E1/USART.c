/*
 * USART.c
 *
 * Created: 04/03/2024 9:57:25
 *  Author: DCE
 */ 


#include <avr/io.h>
#include "USART.h"


void USART0_putchar(unsigned char data){
	//1.Polling; if UDRE0 is 0 waits
	while(!(UCSR0A & (1<<UDRE0)));
	
	//load register
	UDR0=data;
	
}

void USART0_putString(char* strPointer){
	//1.
	while(*strPointer){
		USART0_putchar(*strPointer);
		//_delay_ms(1000);
		strPointer++;
	}
}

void inline USART0_init(){
	/* Configuraci�n del USART */

	// Configuraci�n de la velocidad de transmisi�n
	UBRR0H = (unsigned char) (UBRR_VALUE >> 8);  // Configura el registro de velocidad de transmisi�n de alta
	UBRR0L = (unsigned char) UBRR_VALUE;  // Configura el registro de velocidad de transmisi�n de baja

	// Habilita la recepci�n y la transmisi�n
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);  // Habilita el receptor y el transmisor

	// Configuraci�n del formato de trama: 8 bits de datos, 1 bit de parada
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);  // Establece el tama�o de la trama en 8 bits
	//-----------------------------------
}