/*
 * CFile1.c
 *
 * Created: 6/30/2022 1:08:41 PM
 *  Author: Diefco
 */ 
#define register_size	8
#define set_bit(reg,bit)	reg=reg|(1<<bit)
#define clr_bit(reg,bit)	reg=reg&~(1<<bit)
#define tog_bit(reg,bit)	reg=reg^(1<<bit)
#define read_bit(reg,bit)	(reg&(1<<bit))>>bit
#define is_bit_set(reg,bit) (reg&(1<<bit))>>bit
#define is_bit_clr(reg,bit) !((reg&(1<<bit))>>bit)
#define ror(reg,num)		(reg<<(num))|(reg>>(register_size-num))
#define rol(reg,num)		(reg>>(num))|(reg<<(register_size-num))