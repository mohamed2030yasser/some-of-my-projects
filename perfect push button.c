/*
 * main.c
 *
 * Created: 6/30/2022 12:49:43 PM
 *  Author: Diefco
 */



#include <util/delay.h>
#define F_CPU 8000000UL
#include "LED/LED.h"
#include "BUTTON/BUTTON.h"
#include "DIO/DIO.h"


int main(void)
{
	LED_initialize('A',0);
	BUTTON_initialize('C',0);
	DIO_internal_pullup_enable('C',0);
	unsigned char x=0;

    while(1)
    {
		if (BUTTON_read_u8('C',0)==0)
		{
			x=x^1;
			while(BUTTON_read_u8('C',0)==0){
				if (x)
				{
					LED_on('A',0);
				}
				if (x==0)
				{
					LED_off('A',0);
				}
			}
		}


        //TODO:: Please write your application code
    }
}
