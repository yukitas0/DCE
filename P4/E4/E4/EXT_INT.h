/*
 * EXT_INT.h
 *
 * Created: 04/03/2024 12:23:50
 *  Author: DCE
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_


#define FALLING 1

void INT0_config(int state) {
	// Configuración del trigger para INT0
	EICRA = (EICRA & ~(1<<ISC00)) | (state << ISC01);
	// Configuración del trigger para INT1, manteniéndolo en el valor predeterminado
	EICRA &= ~(1<<ISC10);
}

void INT0_enable() {
	// Habilitar la interrupción INT0
	EIMSK |= (1<<INT0);
}


//Interrucciones RX
static inline void USART0_enaInterrupt_RX() {
	// Enable USART0 RX interrupt
	//UCSR0B |= (1 << RXCIE0);
	UCSR0B |= (1 << UDRIE0);
}


static inline void USART0_disableInterrupt_RX() {
	// Disable USART0 RX interrupt
	//UCSR0B &= ~(1 << RXCIE0);
	UCSR0B &= ~(1 << UDRIE0);
}	

//Interrucciones TX
static inline void USART0_enaInterrupt_TX() {
	// Enable USART0 TX interrupt
	UCSR0B |= (1 << TXCIE0);
}


static inline void USART0_disableInterrupt_TX() {
	// Disable USART0 TX interrupt
	UCSR0B &= ~(1 << TXCIE0);
}





#endif /* EXT_INT_H_ */