/*
 * CFile1.c
 *
 * Created: 7/20/2022 7:48:58 PM
 *  Author: Diefco
 */ 

#include "../DIO/DIO.h"
#include "../DIO/std_macros.h"
#include "util/delay.h"
#include "LCD.h"



void LCD_inatialize(unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	DIO_set_dir(lcd_port,0xff);
	DIO_set_bit_dir(port_RS,RS_bit,1);
	DIO_set_bit_dir(port_en_bit,en_bit,1);
	
	_delay_ms(200);
	LCD_send_cmd(0x38,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	_delay_ms(1);
	LCD_send_cmd(0x0e,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	_delay_ms(1);
	LCD_send_cmd(0x01,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	_delay_ms(10);
	LCD_send_cmd(0x06,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	_delay_ms(1);
	
	
	
}


void LCD_send_char(unsigned char ascii_value,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){

	DIO_write_bit(port_RS,RS_bit,1);
	DIO_write_port(lcd_port,ascii_value);
	
	DIO_write_bit(port_en_bit,en_bit,1);
	_delay_ms(1);
	DIO_write_bit(port_en_bit,en_bit,0);
	_delay_ms(1);
	
	
}


void LCD_send_cmd(unsigned char cmd,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	DIO_write_bit(port_RS,RS_bit,0);
	DIO_write_port(lcd_port,cmd);
	DIO_write_bit(port_en_bit,en_bit,1);
	_delay_ms(1);
	DIO_write_bit(port_en_bit,en_bit,0);
	_delay_ms(10);
	
}


void LCD_send_string(const char *data,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	
	for(int i =0;(*data) !=0;i++){
		if (i==16)
		{
			LCD_move_cursor(2,1,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
		}
		LCD_send_char(*data,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
		_delay_ms(200);//delay to disply another char
		data++;
	}
	_delay_ms(1);
}


void LCD_send_Snum(signed long int x,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	unsigned char arr[15];
	signed char i;
	for( i =0 ; ; i++){

		arr[i]=(x%10);
		if((x=x/10)==0){
			break;
		}


	}

	while(i>=0){
		LCD_send_char((arr[i]+'0'),lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
		i--;
	}
}

void LCD_send_float(double x,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	x=50.5*1000;
	int y=x;
	unsigned char arr[15];
	signed char i;
	for (i=0; ;i++)
	{
		arr[i]=y%10;
		y=y/10;
		if ((y/10)==0)
		{
			break;
		}
	}
	
	while(i>=0)
	{
		if (i==3)
		{
			LCD_send_char('.',lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
		}
		LCD_send_char((arr[i]+'0'),lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
		i--;
	}
	
}


void LCD_move_cursor(unsigned char row,unsigned char colum,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	unsigned char x;
	if (row>2||row<1||colum>16||colum<1)
	{
		x=0x80;
	}else 
	if (row==1){
		
		x=0x80+colum-1;
	}else
	if (row==2){
		x=0xc0+colum-1;
	}
	
	LCD_send_cmd(x,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	_delay_ms(1);
	
}

void LCD_send_char_4bit_mode(unsigned char ascii_value,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit,unsigned char is_in_low){
	if (is_in_low)
	{
		DIO_write_bit(port_RS,RS_bit,1);
		DIO_write_Low_4bits_port(lcd_port,(ascii_value>>4));
		DIO_write_bit(port_en_bit,en_bit,1);
		_delay_ms(1);
		DIO_write_bit(port_en_bit,en_bit,0);
		_delay_ms(10);
		DIO_write_Low_4bits_port(lcd_port,ascii_value);
		DIO_write_bit(port_en_bit,en_bit,1);
		_delay_ms(1);
		DIO_write_bit(port_en_bit,en_bit,0);
		_delay_ms(10);
	}else{
			DIO_write_bit(port_RS,RS_bit,1);
			DIO_write_Most_4bits_port(lcd_port,(ascii_value>>4));
			DIO_write_bit(port_en_bit,en_bit,1);
			_delay_ms(1);
			DIO_write_bit(port_en_bit,en_bit,0);
			_delay_ms(10);
			DIO_write_Most_4bits_port(lcd_port,ascii_value);
			DIO_write_bit(port_en_bit,en_bit,1);
			_delay_ms(1);
			DIO_write_bit(port_en_bit,en_bit,0);
			_delay_ms(10);
		}
}

void LCD_send_cmd_4bit_mode(unsigned char cmd,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit,unsigned char is_in_low){
	if (is_in_low)
	{
		DIO_write_bit(port_RS,RS_bit,0);
		DIO_write_Low_4bits_port(lcd_port,(cmd>>4));
		DIO_write_bit(port_en_bit,en_bit,1);
		_delay_ms(1);
		DIO_write_bit(port_en_bit,en_bit,0);
		_delay_ms(10);
		DIO_write_Low_4bits_port(lcd_port,cmd);
		DIO_write_bit(port_en_bit,en_bit,1);
		_delay_ms(1);
		DIO_write_bit(port_en_bit,en_bit,0);
		_delay_ms(10);
		}else{
				DIO_write_bit(port_RS,RS_bit,0);
				DIO_write_Most_4bits_port(lcd_port,(cmd>>4));
				DIO_write_bit(port_en_bit,en_bit,1);
				_delay_ms(1);
				DIO_write_bit(port_en_bit,en_bit,0);
				_delay_ms(10);
				DIO_write_Most_4bits_port(lcd_port,cmd);
				DIO_write_bit(port_en_bit,en_bit,1);
				_delay_ms(1);
				DIO_write_bit(port_en_bit,en_bit,0);
				_delay_ms(10);
		    }
	
}

void LCD_inatialize_4bit_mode(unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit,unsigned char is_in_low){

	if (is_in_low)
	{
		DIO_set_bit_dir(lcd_port,0,1);
		DIO_set_bit_dir(lcd_port,1,1);
		DIO_set_bit_dir(lcd_port,2,1);
		DIO_set_bit_dir(lcd_port,3,1);
		DIO_set_bit_dir(port_RS,RS_bit,1);
		DIO_set_bit_dir(port_en_bit,en_bit,1);
		
		_delay_ms(200);
		LCD_send_cmd_4bit_mode(0x02,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,1); // return home
		//_delay_ms(10);
		LCD_send_cmd_4bit_mode(0x28,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,1); // 4 bit mode
		_delay_ms(1);
		LCD_send_cmd_4bit_mode(0x0e,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,1); // display on cursor on
		_delay_ms(1);
		LCD_send_cmd_4bit_mode(0x01,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,1); // clear screen
		_delay_ms(10);
		LCD_send_cmd_4bit_mode(0x06,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,1); // entry mode
		_delay_ms(1);
	}else
		{
			DIO_set_bit_dir(lcd_port,4,1);
			DIO_set_bit_dir(lcd_port,5,1);
			DIO_set_bit_dir(lcd_port,6,1);
			DIO_set_bit_dir(lcd_port,7,1);
			DIO_set_bit_dir(port_en_bit,en_bit,1);
			DIO_set_bit_dir(port_RS,RS_bit,1);
			
			
			_delay_ms(200);
			LCD_send_cmd_4bit_mode(0x02,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,0); // return home
			_delay_ms(10);
			LCD_send_cmd_4bit_mode(0x28,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,0); // 4 bit mode
			_delay_ms(1);
			LCD_send_cmd_4bit_mode(0x0e,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,0); // display on cursor on
			_delay_ms(1);
			LCD_send_cmd_4bit_mode(0x01,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,0); // clear screen
			_delay_ms(10);
			LCD_send_cmd_4bit_mode(0x06,lcd_port,port_en_bit,en_bit,port_RS,RS_bit,0); // entry mode
			_delay_ms(1);
		}
	
	
}


void LCD_display_custom_char(unsigned char decemal_index_cgram,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	
	if (decemal_index_cgram<8)
	{
		LCD_send_char(decemal_index_cgram,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	}
	
}
void LCD_save_custom_char(unsigned char decemal_index_cgram,unsigned char custom_char_arr[],unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit){
	
	LCD_send_cmd((0b01000000+(8*decemal_index_cgram)),lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	
	for (int i=0;i<8;i++)
	{
		LCD_send_char(custom_char_arr[i],lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
	}
	
	LCD_send_cmd(0x80,lcd_port,port_en_bit,en_bit,port_RS,RS_bit);
}