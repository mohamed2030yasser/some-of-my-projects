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



volatile unsigned char sec=55;
volatile unsigned char min=60;
volatile unsigned char hour=12;

volatile unsigned char t_sec0=0;
volatile unsigned char t_min0=0;
volatile unsigned char t_hour0=0;
volatile unsigned char t_sec1=0;
volatile unsigned char t_min1=0;
volatile unsigned char t_hour1=0;

volatile unsigned char seg=0;
volatile unsigned char set_ok=0;
volatile unsigned char set_counter=5;

int main(void)
{
	KeyPad_intialize('b');
	LCD_inatialize('d','c',4,'c',5);
	LCD_send_string("click 1 to set",'d','c',4,'c',5);
	seven_SEG_initialize_least4bit('a');
	Timer2_initaialize_OVF_mode_interrupt();
	Timer0_initaialize_CTC_mode_interrupt();
	DIO_set_bit_dir('a',4,1);//sec1
	DIO_set_bit_dir('a',5,1);//sec2
	DIO_set_bit_dir('a',6,1);//min2
	DIO_set_bit_dir('a',7,1);//min2
	DIO_set_bit_dir('c',2,1);//hour1
	DIO_set_bit_dir('c',3,1);//hour2

	while(1)
	{
		if (set_ok==1)
		{
			LCD_send_cmd(cmd_clr_lcd,'d','c',4,'c',5);
			LCD_send_string("click 1 to set",'d','c',4,'c',5);
			sec=t_sec1;
			min=t_min1;
			hour=t_hour1;
			set_ok=0;

		}
		if (seg==0)
		{
			DIO_write_bit('a',4,0);
			DIO_write_bit('a',5,1);
			DIO_write_bit('a',6,1);
			DIO_write_bit('a',7,1);

			DIO_write_bit('c',2,1);
			DIO_write_bit('c',3,1);
			if (sec<60)
			{
				BCD_seven_SEG_write_least('a',sec%10);
			}



		}else if (seg==1)
		{
			DIO_write_bit('a',4,1);
			DIO_write_bit('a',5,0);
			DIO_write_bit('a',6,1);
			DIO_write_bit('a',7,1);

			DIO_write_bit('c',2,1);
			DIO_write_bit('c',3,1);

			if (sec<60)
			{
				BCD_seven_SEG_write_least('a',sec/10);
			}
		}else if (seg==2)
		{
			DIO_write_bit('a',4,1);
			DIO_write_bit('a',5,1);
			DIO_write_bit('a',6,0);
			DIO_write_bit('a',7,1);

			DIO_write_bit('c',2,1);
			DIO_write_bit('c',3,1);

			if (min<60)
			{
				BCD_seven_SEG_write_least('a',min%10);
			}
		}else if (seg==3)
		{
			DIO_write_bit('a',4,1);
			DIO_write_bit('a',5,1);
			DIO_write_bit('a',6,1);
			DIO_write_bit('a',7,0);

			DIO_write_bit('c',2,1);
			DIO_write_bit('c',3,1);

			if (min<60)
			{
				BCD_seven_SEG_write_least('a',min/10);
			}
		}else if (seg==4)
		{
			DIO_write_bit('a',4,1);
			DIO_write_bit('a',5,1);
			DIO_write_bit('a',6,1);
			DIO_write_bit('a',7,1);

			DIO_write_bit('c',2,0);
			DIO_write_bit('c',3,1);

			if (hour<=12)
			{
				BCD_seven_SEG_write_least('a',hour%10);
			}
		}else if (seg==5)
		{
			DIO_write_bit('a',4,1);
			DIO_write_bit('a',5,1);
			DIO_write_bit('a',6,1);
			DIO_write_bit('a',7,1);

			DIO_write_bit('c',2,1);
			DIO_write_bit('c',3,0);

			if (hour<=12)
			{
				BCD_seven_SEG_write_least('a',hour/10);
			}
		}




		if (KeyPad_read('b')=='1' && set_ok==0)
		{

			LCD_send_cmd(cmd_clr_lcd,'d','c',4,'c',5);
			LCD_send_string("hh:mm:ss",'d','c',4,'c',5);
			while(KeyPad_read('b')!=0xff);
			LCD_move_cursor(1,1,'d','c',4,'c',5);
			while (KeyPad_read('b')!='=' && set_counter<=5)
			{
				if (set_counter==5 && '0'<= KeyPad_read('b')&& KeyPad_read('b')<='1')
				{

					hour=(KeyPad_read('b')-48)*10;
					t_hour0=hour;
					LCD_send_Snum(hour/10,'d','c',4,'c',5);
					while(KeyPad_read('b')!=0xff);
					set_counter--;
				}else if (set_counter==4 && '0'<= KeyPad_read('b')&& KeyPad_read('b')<='2')
				{
					hour=t_hour0+(KeyPad_read('b')-48);
					t_hour1=hour;
					LCD_send_Snum(hour%10,'d','c',4,'c',5);
					while(KeyPad_read('b')!=0xff);
					set_counter--;
					LCD_move_cursor(1,4,'d','c',4,'c',5);
				}else if (set_counter==3 && '0'<= KeyPad_read('b')&& KeyPad_read('b')<='5')
				{
					min=(KeyPad_read('b')-48)*10;
					t_min0=min;
					LCD_send_Snum(min/10,'d','c',4,'c',5);
					while(KeyPad_read('b')!=0xff);
					set_counter--;
				}else if (set_counter==2 && '0'<= KeyPad_read('b')&& KeyPad_read('b')<='9')
				{
					min=t_min0+(KeyPad_read('b')-48);
					t_min1=min;
					LCD_send_Snum(min%10,'d','c',4,'c',5);
					while(KeyPad_read('b')!=0xff);
					set_counter--;
					LCD_move_cursor(1,7,'d','c',4,'c',5);
				}else if(set_counter==1 && '0'<= KeyPad_read('b')&& KeyPad_read('b')<='5')
				{
					sec=(KeyPad_read('b')-48)*10;
					t_sec0=sec;
					LCD_send_Snum(sec/10,'d','c',4,'c',5);
					while(KeyPad_read('b')!=0xff);
					set_counter--;
				}else if (set_counter==0 && '0'<= KeyPad_read('b')&& KeyPad_read('b')<='9')
				{
					sec=t_sec0+(KeyPad_read('b')-48);
					t_sec1=sec;
					LCD_send_Snum(sec%10,'d','c',4,'c',5);
					while(KeyPad_read('b')!=0xff);
					set_counter=5;
					set_ok=1;
					break;
				}
			}

		}
	}

}

ISR(TIMER2_OVF_vect)
{
	sec++;
	if (sec>59)
	{
		sec=0;
		min++;
		if (min>59)
		{
			min=0;
			hour++;
			if (hour>12)
			{
				hour=1;
			}
		}
	}
}

ISR(TIMER0_COMP_vect)
{
	seg++;
	if (seg>5)
	{
		seg=0;
	}

}
