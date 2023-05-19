/*
 * main.c
 *
 * Created: 6/30/2022 12:49:43 PM
 *  Author: Diefco
 */ 



#include <util/delay.h>
#include <avr/interrupt.h>

#define F_CPU 8000000UL
#include "BUTTON/BUTTON.h"
#include "DIO/DIO.h"
#include "LED/LED.h"
#include "DIO/std_macros.h"
#include "LCD/LCD.h"
#include "KeyPad/KeyPad.h"
#include "ADC/ADC.h"
#include "EEPROM/EEPROM.h"






int main(void)
{
	
	LCD_inatialize('d','c',7,'c',6);
	ADC_intialize(16);
	for (char i=0;i<8;i++)
	{
		LED_initialize('b',i);
	}
	
	
	
	while(1)
	{
		_delay_ms(3000);
		LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
		_delay_ms(20);
		if ((ADC_read()*2.5)>=1000)
		{
			LCD_send_string("temp :",'d','c',7,'c',6);
			LCD_send_Snum(((ADC_read()*2.5)-1000)/10,'d','c',7,'c',6);
			DIO_write_port('b',ADC_read());
			LCD_send_char(223,'d','c',7,'c',6);
			LCD_send_string("C",'d','c',7,'c',6);
			
			LCD_move_cursor(2,1,'d','c',7,'c',6);
			LCD_send_string("level :",'d','c',7,'c',6);
			LCD_send_Snum((ADC_read()),'d','c',7,'c',6);
			LCD_send_string("L",'d','c',7,'c',6);
			
			LCD_move_cursor(1,1,'d','c',7,'c',6);
		}else
			{
				LCD_send_string("temp :-",'d','c',7,'c',6);
				LCD_send_Snum((1000-(ADC_read()*2.5))/10,'d','c',7,'c',6);
				DIO_write_port('b',ADC_read());
				LCD_send_char(223,'d','c',7,'c',6);
				LCD_send_string("C",'d','c',7,'c',6);
				
				LCD_move_cursor(2,1,'d','c',7,'c',6);
				LCD_send_string("level :",'d','c',7,'c',6);
				LCD_send_Snum((ADC_read()-180),'d','c',7,'c',6);
				LCD_send_string("L",'d','c',7,'c',6);
				
				LCD_move_cursor(1,1,'d','c',7,'c',6);
			}
		
		
	}
	
	
	
}