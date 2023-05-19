/*
 * IncFile1.h
 *
 * Created: 7/10/2022 5:17:13 PM
 *  Author: Diefco
 */ 
void seven_SEG_initialize(unsigned char port);
void seven_SEG_write(unsigned char port ,unsigned char num, unsigned char is_com_anod);
void seven_SEG_off(unsigned char port,unsigned char is_com_anod);
void BCD_seven_SEG_write_least(unsigned char port ,unsigned char num);
void BCD_seven_SEG_write_most(unsigned char port ,unsigned char num);
void BCD_seven_SEG_write_off_least(unsigned char port);
void BCD_seven_SEG_write_off_most(unsigned char port);