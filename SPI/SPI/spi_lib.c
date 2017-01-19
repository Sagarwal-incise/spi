/*
 * SPI.c
 *
 * Created: 13-Jan-17 3:03:30 PM
 *  Author: Agarwal-pc
 */ 


#include <avr/io.h>
#include<util/delay.h>

/************************************************************************/
/*     spi_init Initialize the SPI                                                                */
/************************************************************************/

void spi_init()
{
	PORTB = SCL<<0 | MOSI<<1 | MISO<<2 | SS<<3;
	_delay_ms(500);
	PORTD = 0x01;
	SPI_CR = 0b00000001;
	SPI_ST = 0b00000001;
}
/************************************************************************/
/*     clock toggling the clock                                                                */
/************************************************************************/

void clock (int x)
{
	SCL = x;
	PORTB = SCL<<0 ;
	_delay_ms(1000);
}
/************************************************************************/
/*     spi_Start Start the SPI                                                                 */
/************************************************************************/
void i2c_Start(void)
{
	clock(0);
	SS = 0;
	clock(1);
	PORTB = MOSI<<1 | MISO<<2 | SS<<3;				
	_delay_ms(1000);
	PORTD = 0x02;		
	SPI_CR = 0b00000010;
	SPI_ST = 0b00000010;

}
/************************************************************************/
/*     spi_write Write the SPI                                                                 */
/************************************************************************/

void spi_Write(unsigned char data)
{
	SPI_DR = data;
	if ((SPI_ST == 0x02) && (SPI_CR == 0x02))
	for (unsigned char c=1; c<=8; c++)
	{
		clock(1);
		MOSI = (SPI_DR >> 7);
		PORTB = MOSI<<1 | SCL<<0;									
		SPI_DR = SPI_DR << 1;				
		_delay_ms(500);					
		clock(0);							
	}
}