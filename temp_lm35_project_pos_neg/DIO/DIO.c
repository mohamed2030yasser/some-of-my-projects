#include <avr/io.h>
#include "std_macros.h"




void DIO_set_bit_dir(unsigned char port ,unsigned char pin ,unsigned char dir){
    switch(port){
    case 'A':
    case 'a':
            if(dir==1){
            set_bit(DDRA,pin);
            }else
            clr_bit(DDRA,pin);
            break;
    case 'B':
    case 'b':
        {
            if(dir==1){
            set_bit(DDRB,pin);
            }else
            clr_bit(DDRB,pin);
            break;
        }
    case 'C':
    case 'c':
        {
            if(dir==1){
            set_bit(DDRC,pin);
            }else
            clr_bit(DDRC,pin);
            break;
        }
    case 'D':
    case 'd':
        {
            if(dir==1){
            set_bit(DDRD,pin);
            }else
            clr_bit(DDRD,pin);
            break;
        }

    }



}



void DIO_write_bit(unsigned char port ,unsigned char pin ,unsigned char write){
    switch(port){
    case 'A':
    case 'a':
            if(write==1){
            set_bit(PORTA,pin);
            }else
            clr_bit(PORTA,pin);
            break;
    case 'B':
    case 'b':
        {
            if(write==1){
            set_bit(PORTB,pin);
            }else
            clr_bit(PORTB,pin);
            break;
        }
    case 'C':
    case 'c':
        {
            if(write==1){
            set_bit(PORTC,pin);
            }else
            clr_bit(PORTC,pin);
            break;
        }
    case 'D':
    case 'd':
        {
            if(write==1){
            set_bit(PORTD,pin);
            }else
            clr_bit(PORTD,pin);
            break;
        }

    }



}


void DIO_tog_bit(unsigned char port ,unsigned char pin ){
    switch(port){
    case 'A':
    case 'a':
        {
            tog_bit(PORTA,pin);
            break;
        }
    case 'B':
    case 'b':
        {
            tog_bit(PORTB,pin);
            break;
        }
    case 'C':
    case 'c':
        {
            tog_bit(PORTC,pin);
            break;
        }
    case 'D':
    case 'd':
        {
            tog_bit(PORTD,pin);
            break;
        }

    }



}



unsigned char DIO_read_bit_u8(unsigned char port ,unsigned char pin ){


    unsigned char x;
    switch(port){
    case 'A':
    case 'a':
        {
            x=read_bit(PINA,pin);
            break;
        }
    case 'B':
    case 'b':
        {
            x=read_bit(PINB,pin);
            break;
        }
    case 'C':
    case 'c':
        {
            x=read_bit(PINC,pin);
            break;
        }
    case 'D':
    case 'd':
        {
            x=read_bit(PIND,pin);
            break;
        }

    }

    return x;

}



void DIO_set_dir(unsigned char port,char dir_hex){
    switch(port){
    case 'A':
    case 'a':
        {
            DDRA=dir_hex;
            break;
        }
    case 'B':
    case 'b':
        {
            DDRB=dir_hex;
            break;
        }
    case 'C':
    case 'c':
        {
            DDRC=dir_hex;
            break;
        }
    case 'D':
    case 'd':
        {
            DDRD=dir_hex;
            break;
        }

    }
}


void DIO_write_port(unsigned char port ,unsigned char val){
    switch(port){
    case 'A':
    case 'a':
        {
            PORTA=val;
            break;
        }
    case 'B':
    case 'b':
        {
            PORTB=val;
            break;
        }
    case 'C':
    case 'c':
        {
            PORTC=val;
            break;
        }
    case 'D':
    case 'd':
        {
            PORTD=val;
            break;
        }

    }



}

unsigned char DIO_read_pin_u8(unsigned char port ){


    unsigned char x;
    switch(port){
    case 'A':
    case 'a':
        {
            x=PINA;
            break;
        }
    case 'B':
    case 'b':
        {
            x=PINB;
            break;
        }
    case 'C':
    case 'c':
        {
            x=PINC;
            break;
        }
    case 'D':
    case 'd':
        {
            x=PIND;
            break;
        }

    }

    return x;

}


void DIO_tog_port(unsigned char port ){
    switch(port){
    case 'A':
    case 'a':
        {
            PORTA=~PORTA;
            break;
        }
    case 'B':
    case 'b':
        {
            PORTB=~PORTB;
            break;
        }
    case 'C':
    case 'c':
        {
            PORTC=~PORTC;
            break;
        }
    case 'D':
    case 'd':
        {
            PORTD=~PORTD;
            break;
        }

    }



}


void DIO_internal_pullup_enable(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
		case 'a':
		{
			clr_bit(DDRA,pin);
			set_bit(PORTA,pin);
			break;
		}
		case 'B':
		case 'b':
		{
			clr_bit(DDRB,pin);
			set_bit(PORTB,pin);
			break;
		}
		case 'C':
		case 'c':
		{
			clr_bit(DDRC,pin);
			set_bit(PORTC,pin);
			break;
		}
		case 'D':
		case 'd':
		{
			clr_bit(DDRD,pin);
			set_bit(PORTD,pin);
			break;
		}

	}



}


void DIO_internal_pullup_disable(unsigned char port,unsigned char pin){
	switch(port){
		case 'A':
		case 'a':
		{
			clr_bit(DDRA,pin);
			clr_bit(PORTA,pin);
			break;
		}
		case 'B':
		case 'b':
		{
			clr_bit(DDRB,pin);
			clr_bit(PORTB,pin);
			break;
		}
		case 'C':
		case 'c':
		{
			clr_bit(DDRC,pin);
			clr_bit(PORTC,pin);
			break;
		}
		case 'D':
		case 'd':
		{
			clr_bit(DDRD,pin);
			clr_bit(PORTD,pin);
			break;
		}

	}



}


void DIO_write_Low_4bits_port(unsigned char port,unsigned char val){
	DIO_write_bit(port,0,read_bit(val,0));
	DIO_write_bit(port,1,read_bit(val,1));
	DIO_write_bit(port,2,read_bit(val,2));
	DIO_write_bit(port,3,read_bit(val,3));
}

void DIO_write_Most_4bits_port(unsigned char port,unsigned char val){
	DIO_write_bit(port,4,read_bit(val,0));
	DIO_write_bit(port,5,read_bit(val,1));
	DIO_write_bit(port,6,read_bit(val,2));
	DIO_write_bit(port,7,read_bit(val,3));
}
