/*
 * CFile1.c
 *
 * Created: 7/13/2022 8:21:13 PM
 *  Author: Diefco
 */ 
#include <C:/Users/Diefco/Desktop/XC8Application1/XC8Application1/DIO/DIO.h>
#include <C:/Users/Diefco/Desktop/XC8Application1/XC8Application1/DIO/std_macros.h>
#include "avr/io.h"

void EEPROM_write(unsigned short address , unsigned char data){
	
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	EEDR=data;
	set_bit(EECR,EEMWE);
	set_bit(EECR,EEWE);
	while(read_bit(EECR,EEWE)){
		
	}
}


unsigned char EEPROM_read(unsigned short address){
	
	EEARL=(char)address;
	EEARH=(char)(address>>8);
	set_bit(EECR,EERE);
	return EEDR;
}