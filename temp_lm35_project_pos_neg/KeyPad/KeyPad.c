/*
 * CFile1.c
 *
 * Created: 7/26/2022 2:42:31 PM
 *  Author: Diefco
 */ 

#include "../DIO/DIO.h"
#include "KeyPad.h"

void KeyPad_intialize(unsigned char port){
	// row>> out in lest
	DIO_set_bit_dir(port,0,1);
	DIO_set_bit_dir(port,1,1);
	DIO_set_bit_dir(port,2,1);
	DIO_set_bit_dir(port,3,1);
	
	// colum>> input at most
	DIO_internal_pullup_enable(port,4);
	DIO_internal_pullup_enable(port,5);
	DIO_internal_pullup_enable(port,6);
	DIO_internal_pullup_enable(port,7);
}

unsigned char KeyPad_read(unsigned char port){
	char arr[4][4]={{'7','8','9','+'},{'4','5','6','-'},{'1','2','3','*'},{'c','0','/','='}};
	unsigned char row,coloumn,ret=0xff;
	for (row =0;row<4;row++)
	{
		DIO_write_bit(port,0,1);
		DIO_write_bit(port,1,1);
		DIO_write_bit(port,2,1);
		DIO_write_bit(port,3,1);
		DIO_write_bit(port,row,0);
		for(coloumn=0;coloumn<4;coloumn++)
		{
			
			if (DIO_read_bit_u8(port,coloumn+4)==0)
			{
				ret=arr[row][coloumn];
				break;
			}
		}
		if (ret!=0xff)
		{
			break;
		}
	}
	
	return ret;
}