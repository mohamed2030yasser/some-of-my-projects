#include <C:/Users/Diefco/Desktop/XC8Application1/XC8Application1/DIO/DIO.h>



void LED_initialize(unsigned char port,unsigned char pin_num){
	
		DIO_set_bit_dir(port,pin_num,1);
}

void LED_on(unsigned char port,unsigned char pin_num){
	
	DIO_write_bit(port,pin_num,1);
}


void LED_off(unsigned char port,unsigned char pin_num){
	
	DIO_write_bit(port,pin_num,0);
}


void LED_tog(unsigned char port,unsigned char pin_num){
	
	DIO_tog_bit(port,pin_num);
}

unsigned char LED_read_stat(unsigned char port,unsigned char pin_num){
	
	return DIO_read_bit_u8(port,pin_num);
}
