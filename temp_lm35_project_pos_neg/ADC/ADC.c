/*
 * CFile1.c
 *
 * Created: 7/31/2022 10:40:29 AM
 *  Author: Diefco
 */ 

#include "../DIO/DIO.h"
#include <avr/io.h>


void ADC_intialize(unsigned char pin_num){
	/*---------[select Pin-A num]--------------*/
	ADMUX=pin_num;
	/*---------[select A-REF]--------------*/
	set_bit(ADMUX,REFS0);
	set_bit(ADMUX,REFS1);
	/*---------[select ADLAR]--------------*/
	clr_bit(ADMUX,ADLAR);
	/*---------[EN ADC]--------------*/
	set_bit(ADCSRA,ADEN);
	/*---------[select devide/64>>110 prescaller clock]--------------*/
	clr_bit(ADCSRA,ADPS0);
	set_bit(ADCSRA,ADPS1);
	set_bit(ADCSRA,ADPS2);
		
}

unsigned short ADC_read(void){
	unsigned short adc_val;
	/*--------[ start convertion ]----------*/
	set_bit(ADCSRA,ADSC);
	while(read_bit(ADCSRA,ADSC));
	/*--------[ read adc data ]----------*/
	adc_val=ADCL;
	//adc_val=ADCH;
	adc_val=adc_val|(ADCH<<8);
	return adc_val;
	
	
}