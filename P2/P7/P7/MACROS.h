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
//(PIND & (1 << PIND2))
#define READ_PIN(ADDRESS,BIT)	(ADDRESS & (1<<BIT))
#define BUTTON_PRESSED			(0)
	
//READ_PIN(ADDRESS,BIT) ?? ? For reading a PIN in a register
//BUTTON_PRESSED ?? ? To define a pressed button is ‘0’ (false)





#endif /* MACROS_H_ */