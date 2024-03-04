/*
 * E2.c
 *
 * Created: 04/03/2024 10:29:21
 * Author : DCE
 */ 

#include <avr/io.h>
#include "USART.h"

int main(void)
{
	
	USART0_init(UBRR_VALUE);
    /* Replace with your application code */
    while (1) 
    {
        unsigned char received_char = USART0_getchar();
        // Echo the character back to the sender
        USART0_putchar(received_char);
    }
}

