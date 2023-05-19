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
#include "Ultra_Sonic/Ultra_Sonic.h"
#include "Motors/Motors.h"
#include "USART/USART.h"
#include "SPI/SPI.h"
#include "I2C/I2C.h"
#include "DHT11/DHT11.h"
#define dummy_data 0xff



int main(void)
{

	LCD_inatialize('a','b',0,'b',1);
	KeyPad_intialize('d');
	char lcd=0;
	int arr_num[20],num=0,i,j,index_num=0,index_operant=0,result=0;
	char arr_operant[20];

	//----------------------------------------------------------------
	unsigned char arr[20],index_arr=0;
	//----------------------------------------------------------------
	//LCD_move_cursor(2,5,'d','c',7,'c',6);
	//LCD_send_cmd(cmd_shift_display_left,'d','c',7,'c',6);

	//LCD_send_cmd(cmd_shift_right_txt,'d','c',7,'c',6);
	//_delay_ms(4000);

	//LCD_inatialize_4bit_mode('d','c',7,'c',6,0);
	//LCD_send_char_4bit_mode('a','d','c',7,'c',6,0);

	//LCD_send_char_4bit_mode('a','d','c',7,'c',6,0);

		while (1)
		{
			if (KeyPad_read('d')!=0xff)
			{
					if (KeyPad_read('d')=='c')
					{
						lcd=0;
						LCD_send_cmd(cmd_clr_lcd,'a','b',0,'b',1);
						while (KeyPad_read('d')!=0xff)
						{

						}
						for (index_arr=0;index_arr<=20;index_arr++)
								{
									arr[index_arr]=0;
									arr_num[index_arr]=0;
									arr_operant[index_operant]=0;
								}
								index_arr=0;
								index_num=0;
								index_operant=0;
					}else if (KeyPad_read('d')!='c')
							{
								lcd++;
								if (KeyPad_read('d')!='=')
								{

									arr[index_arr]=KeyPad_read('d');
									index_arr++;
								}
								LCD_send_char(KeyPad_read('d'),'a','b',0,'b',1);
								_delay_ms(300);
								/*-------------------------[---------------------]-----------------*/
									if (KeyPad_read('d')=='=')
									{

										for(i=0;i<20;i++){
											if(arr[i]>='0'&&arr[i]<='9'){
												for(j=i;(arr[j]>='0'&&arr[j]<='9');j++){
													num=(num*10)+(arr[j]-48);
													i++;
												}
												arr_num[index_num]=num;
												index_num++;
												num=0;
											}
										}
										/*-------------------------[clear_locations_that_not_storint_num]-----------------*/
										for(i=index_num;i<20;i++){
											arr_num[i]=0;
										}
										/*-------------------------[sorting-oprtant]-----------------*/
										for(i=0;i<20;i++){
											if(arr[i]=='+'||arr[i]=='-'||arr[i]=='*'||arr[i]=='/'||arr[i]=='='){
												arr_operant[index_operant]=arr[i];
												index_operant++;
												if(arr[i]=='-'){
													arr_num[index_operant]=-arr_num[index_operant];
												}
											}
										}
										/*-------------------------[clear_locations_that_not_storint_operant]-----------------*/
										for(i=index_operant;i<20;i++){
											arr_operant[i]=0;
										}
										/*-------------------------[handling mul & div]-----------------*/

										for(i=0;i<index_operant;i++){
											if(arr_operant[i]=='*'){
												arr_num[i+1]=arr_num[i]*arr_num[i+1];
												arr_num[i]=0;
												}else if(arr_operant[i]=='/'&&arr_num[i+1]!=0){
												arr_num[i+1]=arr_num[i]/arr_num[i+1];
												arr_num[i]=0;
											}
										}
										/*-------------------------[calculating & print resuls]-----------------*/
										result=arr_num[0];
										for(i=0;i<index_operant;i++){
											result=result+arr_num[i+1];
										}


										LCD_send_Snum(result,'a','b',0,'b',1);
									}



								while (KeyPad_read('d')!=0xff)
								{

								}
								_delay_ms(300);
								if (lcd==16)
								{
									LCD_move_cursor(2,1,'a','b',0,'b',1);
								}
								if (lcd==32)
								{
									LCD_move_cursor(1,1,'a','b',0,'b',1);
									lcd=0;
								}


								/*for (index_arr=0;index_arr<=20;index_arr++)
								{
									arr[index_arr]=0;
								}
								index_arr=0;
								*/
							}




				}

			}


}
