/*
 * USART.h
 *
 * Created: 04/03/2024 9:54:23
 *  Author: DCE
 */ 


// USART.h

#ifndef USART_H_
#define USART_H_

#include <avr/io.h>

#define F_CPU 16000000UL
#define BAUD  9600
#define UBRR_VALUE ((F_CPU/(16UL*BAUD))-1)

void USART0_putchar(unsigned char);
void USART0_putString(char*);
void USART0_init(uint16_t);
unsigned char USART0_getchar();

#endif /* USART_H_ */


