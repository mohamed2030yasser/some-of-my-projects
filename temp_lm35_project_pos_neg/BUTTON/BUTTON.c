#include <C:/Users/Diefco/Desktop/XC8Application1/XC8Application1/DIO/DIO.h>



void BUTTON_initialize(unsigned char port,unsigned char pin_num){

	
		DIO_set_bit_dir(port,pin_num,0);
	
}

unsigned char BUTTON_read_u8(unsigned char port,unsigned char pin_num){
	
	return DIO_read_bit_u8(port,pin_num);
}