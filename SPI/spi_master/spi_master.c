/*
 * spi_master.c
 *
 * Created: 13-Jan-17 3:24:30 PM
 *  Author: Agarwal-pc
 */ 


#include <avr/io.h>
#define F_CPU 16000000UL
#include<util/delay.h>
//#include <stdio.h>




int main(void)
{
	DDRB = 0x0B;
	DDRD = 0xff;
	spi_init();
	spi_Start();
	spi_Master_Write(0xaa);
	return 0;
}
