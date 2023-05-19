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






int main(void)
{
	/*-------------[ BUTTON_initialize ]--------------*/
	BUTTON_initialize('a',0);
	BUTTON_initialize('a',1);
	BUTTON_initialize('a',2);
	BUTTON_initialize('a',3);
	BUTTON_initialize('a',4);
	/*-------------[ DIO_internal_pullup_enable ]--------------*/
	DIO_internal_pullup_enable('a',0);
	DIO_internal_pullup_enable('a',1);
	DIO_internal_pullup_enable('a',2);
	DIO_internal_pullup_enable('a',3);
	DIO_internal_pullup_enable('a',4);
	/*-------------[ LCD_inatialize ]--------------*/
	LCD_inatialize('d','c',7,'c',6);
	/*-------------[ set vote frame ]--------------*/
	LCD_send_string("A :",'d','c',7,'c',6);
	LCD_move_cursor(1,8,'d','c',7,'c',6);
	LCD_send_string("B :",'d','c',7,'c',6);
	LCD_move_cursor(2,1,'d','c',7,'c',6);
	LCD_send_string("C :",'d','c',7,'c',6);
	LCD_move_cursor(2,8,'d','c',7,'c',6);
	LCD_send_string("D :",'d','c',7,'c',6);

	/*-------------[ variable ]--------------*/
	int A=0,B=0,C=0,D=0;



		while (1)
		{
			if (DIO_read_bit_u8('a',0)==0)
			{
				A++;
				LCD_move_cursor(1,4,'d','c',7,'c',6);
				LCD_send_Snum(A,'d','c',7,'c',6);

				while(DIO_read_bit_u8('a',0)==0)
				{

				}

			} else if (DIO_read_bit_u8('a',1)==0)
			{
				B++;
				LCD_move_cursor(1,11,'d','c',7,'c',6);
				LCD_send_Snum(B,'d','c',7,'c',6);

				while(DIO_read_bit_u8('a',1)==0)
				{

				}
			} else if (DIO_read_bit_u8('a',2)==0)
			{
				C++;
				LCD_move_cursor(2,4,'d','c',7,'c',6);
				LCD_send_Snum(C,'d','c',7,'c',6);

				while(DIO_read_bit_u8('a',2)==0)
				{

				}
			} else if (DIO_read_bit_u8('a',3)==0)
			{
				D++;
				LCD_move_cursor(2,11,'d','c',7,'c',6);
				LCD_send_Snum(D,'d','c',7,'c',6);

				while(DIO_read_bit_u8('a',3)==0)
				{

				}
				}else if (DIO_read_bit_u8('a',4)==0)
				{

					A=0,B=0,C=0,D=0;
					LCD_move_cursor(1,6,'d','c',7,'c',6);

					LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
					_delay_ms(5000);
					LCD_send_string("RESET",'d','c',7,'c',6);
					LCD_move_cursor(2,6,'d','c',7,'c',6);
					LCD_send_string("VOTING",'d','c',7,'c',6);
					_delay_ms(5000);
					LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
					_delay_ms(5000);

					LCD_move_cursor(1,1,'d','c',7,'c',6);
					LCD_send_string("A :",'d','c',7,'c',6);
					LCD_move_cursor(1,8,'d','c',7,'c',6);
					LCD_send_string("B :",'d','c',7,'c',6);
					LCD_move_cursor(2,1,'d','c',7,'c',6);
					LCD_send_string("C :",'d','c',7,'c',6);
					LCD_move_cursor(2,8,'d','c',7,'c',6);
					LCD_send_string("D :",'d','c',7,'c',6);

					while(DIO_read_bit_u8('a',4)==0)
					{

					}
				}

		}

}

