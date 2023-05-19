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
#include "7_SEG/7_SEG.h"
#include "TIMERS/TIMERS.h"

volatile unsigned  int a=0;
volatile unsigned  int b=0;
volatile unsigned  int c=0;


int main(void)
{
	unsigned  int t_on=0;
	unsigned  int t_period=0;
	float duty=0;
	float frecuency=0;
	LCD_inatialize('a','b',0,'b',1);




	while(1)
	{

		a=0,b=0,c=0;

		TCCR1A=0; //normal mode
		TIFR=(1<<ICF1);
		TCCR1B=0b11000010; //no prescaling and dedict rising edge
		while((TIFR&(1<<ICF1))==0);
		a=TCNT1;
		TIFR=(1<<ICF1);
		//----------------------
		TCCR1B=0b10000010; //no prescaling and dedict faling edge
		while((TIFR&(1<<ICF1))==0);
		b=TCNT1;
		TIFR=(1<<ICF1);
		//----------------------
		TCCR1B=0b11000010; //no prescaling and dedict rising edge
		while((TIFR&(1<<ICF1))==0);
		c=TCNT1;
		TIFR=(1<<ICF1);

		TCCR1B=0;

		//--------------------------------------
		if ((a<b)&&(b<c))
		{

			t_on=b-a;
			t_period=c-a;
			duty =(float)t_on/t_period;
			frecuency=(float)1/t_period;
			LCD_send_cmd(cmd_clr_lcd,'a','b',0,'b',1);
			LCD_move_cursor(1,1,'a','b',0,'b',1);
			LCD_send_string("Duty :",'a','b',0,'b',1);
			LCD_send_Snum(duty*100,'a','b',0,'b',1);
			LCD_send_char('%','a','b',0,'b',1);
			//---------------
			LCD_move_cursor(2,1,'a','b',0,'b',1);
			LCD_send_string("Freq :",'a','b',0,'b',1);
			LCD_send_Snum(frecuency*F_CPU/8,'a','b',0,'b',1);
			LCD_send_string("HZ",'a','b',0,'b',1);
			_delay_ms(6000);
		}else
		{
			LCD_send_cmd(cmd_clr_lcd,'a','b',0,'b',1);
			LCD_move_cursor(1,1,'a','b',0,'b',1);
			LCD_send_string("Out of range",'a','b',0,'b',1);
			_delay_ms(6000);
		}
	}
}

