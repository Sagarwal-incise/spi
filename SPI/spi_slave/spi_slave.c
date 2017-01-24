/*
 * spi_slave.c
 *
 * Created: 13-Jan-17 3:24:54 PM
 *  Author: Agarwal-pc
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include<util/delay.h>

int main()
	{
		DDRB = 0x40;
		spi_init_slave();
		spi_Start_slave();
		spi_slave_read();
		return 0;
	}


