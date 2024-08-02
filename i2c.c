
#include <xc.h>
#include "main.h"


void init_i2c(void)
{
	/* Set SCL and SDA pins as inputs */
	TRISC3 = 1;
	TRISC4 = 1;
	/* Set I2C master mode */
	SSPCON1 = 0x28;             //con1 register

	SSPADD = 0x31;              //address register
	/* Use I2C levels, worked also with '0' */
	CKE = 0;
	/* Disable slew rate control  worked also with '0' */
	SMP = 1;
	/* Clear SSPIF interrupt flag */
	SSPIF = 0;
	/* Clear bus collision flag */
	BCLIF = 0;
}

void i2c_idle(void)
{
	while (!SSPIF);             //checking interrupt flag 
	SSPIF = 0;                  //making it as 0
}

void i2c_ack(void)
{
	if (ACKSTAT)                //acknowledge status
	{
		/* Do debug print here if required */
	}
}

void i2c_start(void)            
{
	SEN = 1;                    //making slave enable bit as 1
	i2c_idle();
}

void i2c_stop(void)
{
	PEN = 1;                    //
	i2c_idle();
}

void i2c_rep_start(void)
{
	RSEN = 1;
	i2c_idle();
}

void i2c_write(unsigned char data)
{
	SSPBUF = data;                  //setting data to buffer register 
	i2c_idle();
}

void i2c_rx_mode(void)
{
	RCEN = 1;                       
	i2c_idle();
}

void i2c_no_ack(void)
{
	ACKDT = 1;                      //setting 1 as no acknowledge will receive
	ACKEN = 1;                      //setting acknowledge enable bit as 1
}

unsigned char i2c_read(void)
{
	i2c_rx_mode();                  //setting that 
	i2c_no_ack();                   //setting that acknowledge receive

	return SSPBUF;                  //return buffer register
}