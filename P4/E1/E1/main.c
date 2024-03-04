/*
 * E1.c
 *
 * Created: 04/03/2024 9:25:28
 * Author : DCE
 */ 


// main.c

#include <avr/io.h>
#include <util/delay.h>
#include "USART.h"

int main(void)
{
	USART0_init(); // Inicializa el USART

	while (1)
	{
		USART0_putString("Hello World \n\r");
		//_delay_ms(1000);
	}
}


