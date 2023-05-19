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
	KeyPad_intialize('a');
	unsigned char n0,n1,n2,n3,i=0,ok=0,j=1;





		while (1)
		{
			if (EEPROM_read(0x09)!=5)
			{
				LCD_send_string("Hi set pass",'d','c',7,'c',6);
				LCD_move_cursor(2,1,'d','c',7,'c',6);
				while(i<4)
				{
					if ((KeyPad_read('a')!=0xff)&&i==0)
					{
						n0=KeyPad_read('a');
						EEPROM_write(0x10,n0);
						LCD_send_char(n0,'d','c',7,'c',6);
						/*-----------------*/
						while(KeyPad_read('a')!=0xff);
						_delay_ms(500);
						LCD_move_cursor(2,1,'d','c',7,'c',6);
						LCD_send_char('*','d','c',7,'c',6);
						/*-----------------*/
						i++;

					}


					/*-------------------------------*/
					if ((KeyPad_read('a')!=0xff)&&i==1)
					{
						n1=KeyPad_read('a');
						EEPROM_write(0x11,n1);
						LCD_send_char(n1,'d','c',7,'c',6);
						/*-----------------*/
						while(KeyPad_read('a')!=0xff);
						_delay_ms(500);
						LCD_move_cursor(2,2,'d','c',7,'c',6);
						LCD_send_char('*','d','c',7,'c',6);
						/*-----------------*/
						i++;

					}


					/*-------------------------------*/
					if ((KeyPad_read('a')!=0xff)&&i==2)
					{
						n2=KeyPad_read('a');
						EEPROM_write(0x12,n2);
						LCD_send_char(n2,'d','c',7,'c',6);
						/*-----------------*/
						while(KeyPad_read('a')!=0xff);
						_delay_ms(500);
						LCD_move_cursor(2,3,'d','c',7,'c',6);
						LCD_send_char('*','d','c',7,'c',6);
						/*-----------------*/
						i++;

					}


					/*-------------------------------*/
					if ((KeyPad_read('a')!=0xff)&&i==3)
					{
						n3=KeyPad_read('a');
						EEPROM_write(0x13,n3);
						LCD_send_char(n3,'d','c',7,'c',6);
						/*-----------------*/
						while(KeyPad_read('a')!=0xff);
						_delay_ms(500);
						LCD_move_cursor(2,4,'d','c',7,'c',6);
						LCD_send_char('*','d','c',7,'c',6);
						/*-----------------*/
						i++;

					}



				}
				EEPROM_write(0x09,5);
			}

			/*--------------------------------*/
			if (EEPROM_read(0x09)==5)
			{
				i=0;


				while((ok==0)&&j<4)
                {
					LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
					LCD_move_cursor(1,1,'d','c',7,'c',6);
					LCD_send_string("check-passs",'d','c',7,'c',6);
					LCD_move_cursor(2,1,'d','c',7,'c',6);

                        while(i<4)
                    {

                        if ((KeyPad_read('a')!=0xff)&&i==0)
                        {
                            n0=KeyPad_read('a');
                            LCD_send_char(n0,'d','c',7,'c',6);
                            /*-----------------*/
                            while(KeyPad_read('a')!=0xff);
                            _delay_ms(500);
                            LCD_move_cursor(2,1,'d','c',7,'c',6);
                            LCD_send_char('*','d','c',7,'c',6);
                            /*-----------------*/
                            i++;

                        }

                        if ((KeyPad_read('a')!=0xff)&&i==1)
                        {
                            n1=KeyPad_read('a');
                            LCD_send_char(n1,'d','c',7,'c',6);
                            /*-----------------*/
                            while(KeyPad_read('a')!=0xff);
                            _delay_ms(500);
                            LCD_move_cursor(2,2,'d','c',7,'c',6);
                            LCD_send_char('*','d','c',7,'c',6);
                            /*-----------------*/
                            i++;

                        }

                        if ((KeyPad_read('a')!=0xff)&&i==2)
                        {
                            n2=KeyPad_read('a');
                            LCD_send_char(n2,'d','c',7,'c',6);
                            /*-----------------*/
                            while(KeyPad_read('a')!=0xff);
                            _delay_ms(500);
                            LCD_move_cursor(2,3,'d','c',7,'c',6);
                            LCD_send_char('*','d','c',7,'c',6);
                            /*-----------------*/
                            i++;

                        }

                        if ((KeyPad_read('a')!=0xff)&&i==3)
                        {
                            n3=KeyPad_read('a');
                            LCD_send_char(n3,'d','c',7,'c',6);
                            /*-----------------*/
                            while(KeyPad_read('a')!=0xff);
                            _delay_ms(500);
                            LCD_move_cursor(2,4,'d','c',7,'c',6);
                            LCD_send_char('*','d','c',7,'c',6);
                            /*-----------------*/
                            i++;

                        }
                    }

                    if ((n0==EEPROM_read(0x10))&&(n1==EEPROM_read(0x11))&&(n2==EEPROM_read(0x12))&&(n3==EEPROM_read(0x13)))
                    {
                        LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
                        LCD_move_cursor(1,1,'d','c',7,'c',6);
                        LCD_send_string("correct pass",'d','c',7,'c',6);
                        ok=1;
						break;
                    }else
                    {
                        LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
                        LCD_move_cursor(1,1,'d','c',7,'c',6);
                        LCD_send_string("wrong pass ",'d','c',7,'c',6);

                        LCD_move_cursor(2,1,'d','c',7,'c',6);
                        LCD_send_string("it was ",'d','c',7,'c',6);
                        LCD_send_Snum(j,'d','c',7,'c',6);
                        LCD_send_string(" try(3)",'d','c',7,'c',6);
                        j++;
                        i=0;
						_delay_ms(5000);


                    }
                }
				if (j==4)
				{
					LCD_send_cmd(cmd_clr_lcd,'d','c',7,'c',6);
					LCD_move_cursor(1,1,'d','c',7,'c',6);
					LCD_send_string("locked",'d','c',7,'c',6);
					break;
				}
				if (ok==1)
				{

					break;
				}
			}
			//while(1);



		}

}


