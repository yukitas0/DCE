/*
 * MACROS.h
 *
 * Created: 19/02/2024 10:16:42
 *  Author: DCE
 */ 


#ifndef MACROS_H_
#define MACROS_H_

//P2-Project 6
#define SETBIT(ADDRESS,BIT)		(ADDRESS |= (1<<BIT))
#define CLEARBIT(ADDRESS,BIT)	(ADDRESS &= ~(1<<BIT))
#define TOGGLEBIT(ADDRESS,BIT)	(ADDRESS ^= (1<<BIT))

//P2-Project 7

#define READ_PIN(ADDRESS,BIT)	(ADDRESS & (1<<BIT))	//Lee el estado del botón
#define BUTTON_PRESSED			0						//Cual es el estado del falso
	





#endif /* MACROS_H_ */