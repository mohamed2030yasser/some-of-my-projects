/*
 * CFile1.c
 *
 * Created: 7/10/2022 5:17:22 PM
 *  Author: Diefco
 */ 

#include <C:/Users/Diefco/Desktop/XC8Application1/XC8Application1/DIO/DIO.h>
#include <C:/Users/Diefco/Desktop/XC8Application1/XC8Application1/DIO/std_macros.h>

void seven_SEG_initialize(unsigned char port){
	DIO_set_dir(port,0xff);
}

void seven_SEG_write(unsigned char port ,unsigned char num, unsigned char is_com_anod){
	if (is_com_anod==0)
	{
		if (num==0)
		{
			DIO_write_port(port,0b0111111);
		}else if (num==1)
		{
			DIO_write_port(port,0b0000110);
		}else if (num==2)
		{
			DIO_write_port(port,0b1011011);
		}else if (num==3)
		{
			DIO_write_port(port,0b1001111);
		}else if (num==4)
		{
			DIO_write_port(port,0b1100110);
		}else if (num==5)
		{
			DIO_write_port(port,0b1101101);
		}else if (num==6)
		{
			DIO_write_port(port,0b1111101);
		}else if (num==7)
		{
			DIO_write_port(port,0b0000111);
		}else if (num==8)
		{
			DIO_write_port(port,0b1111111);
		}else if (num==9)
		{
			DIO_write_port(port,0b1101111);
		}
	}else if (is_com_anod)
	{
		if (num==0)
		{
			DIO_write_port(port,0b1000000);
		}else if (num==1)
		{
			DIO_write_port(port,0b1111001);
		}else if (num==2)
		{
			DIO_write_port(port,0b0100100);
		}else if (num==3)
		{
			DIO_write_port(port,0b0110000);
		}else if (num==4)
		{
			DIO_write_port(port,0b0011001);
		}else if (num==5)
		{
			DIO_write_port(port,0b0010010);
		}else if (num==6)
		{
			DIO_write_port(port,0b0000010);
		}else if (num==7)
		{
			DIO_write_port(port,0b1111000);
		}else if (num==8)
		{
			DIO_write_port(port,0b0000000);
		}else if (num==9)
		{
			DIO_write_port(port,0b0010000);
		}
	}
}


void seven_SEG_off(unsigned char port,unsigned char is_com_anod){
	if (is_com_anod)
	{
		DIO_write_port(port,0XFF);
	}else DIO_write_port(port,0X00);
}

void BCD_seven_SEG_write_least(unsigned char port ,unsigned char num){
	DIO_write_bit(port,0,read_bit(num,0));
	DIO_write_bit(port,1,read_bit(num,1));
	DIO_write_bit(port,2,read_bit(num,2));
	DIO_write_bit(port,3,read_bit(num,3));
}

void BCD_seven_SEG_write_off_least(unsigned char port){
	DIO_write_bit(port,0,1);
	DIO_write_bit(port,1,1);
	DIO_write_bit(port,2,1);
	DIO_write_bit(port,3,1);
}

void BCD_seven_SEG_write_most(unsigned char port ,unsigned char num){
	DIO_write_bit(port,4,read_bit(num,0));
	DIO_write_bit(port,5,read_bit(num,1));
	DIO_write_bit(port,6,read_bit(num,2));
	DIO_write_bit(port,7,read_bit(num,3));
}


void BCD_seven_SEG_write_off_most(unsigned char port){
	DIO_write_bit(port,4,1);
	DIO_write_bit(port,5,1);
	DIO_write_bit(port,6,1);
	DIO_write_bit(port,7,1);
}