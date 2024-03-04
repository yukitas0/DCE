/*
 * E3.c
 *
 * Created: 04/03/2024 10:47:09
 * Author : DCE
 */ 

#include <avr/io.h>
#include "USART.h"

void MainMenu();
int main(void)
{
	USART0_init(UBRR_VALUE);
	
	
    /* Replace with your application code */
    while (1) 
    {
		MainMenu();
		unsigned char opcion = USART0_getchar();
		switch (opcion)
		{
		case 'a':
			USART0_putString("Presionaste a\n\r");
			break;
		case 'b':
			USART0_putString("Presionaste b\n\r");
			break;
		case 'z':
			MainMenu();
			break;
		default:
			USART0_putString("Error :(\n\r");	
		}
    }
}

inline void MainMenu(){
	USART0_putString(
	"\n\rEsto es el menu principal, selecciona una:\n\r"
	"----------------------------------------------\n\r"
	"a.\n\r"
	"b.\n\r"
	"------------------------------------\n\r"
	"Z.Vuelve a mostrar el menu\n\r"
	"Opcion:"
	);
	
}

