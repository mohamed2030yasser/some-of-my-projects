/*
 * IncFile1.h
 *
 * Created: 7/20/2022 7:48:50 PM
 *  Author: Diefco
 */ 

#define cmd_clr_lcd 0x01
#define cmd_return_home 0x02
#define cmd_write_right_to_left 0x04
#define cmd_write_left_to_right 0x06
#define cmd_shift_display_right 0x05
#define cmd_shift_display_left 0x07
#define cmd_disOFF_curOFF 0x08
#define cmd_disOFF_curON 0x0A
#define cmd_disON_curOFF 0x0C
#define cmd_disON_curON 0x0E
#define cmd_disON_curBLINK 0x0F
#define cmd_shift_cursor_left 0x10
#define cmd_shift_cursor_right 0x14
#define cmd_shift_left_txt 0x18
#define cmd_shift_right_txt 0x1c




//unsigned char [lcd_port],unsigned char [port_en_bit],unsigned char [en_bit],unsigned char [port_RS],unsigned char [RS_bit]
#define lcd_pin_value 'd','c',7,'c',6


void LCD_send_char(unsigned char ascii_value,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_inatialize(unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_send_cmd(unsigned char cmd,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_send_string(const char *data,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_send_Snum(signed long int x,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_move_cursor(unsigned char row,unsigned char colum,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_send_cmd_4bit_mode(unsigned char cmd,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit,unsigned char is_in_low);
void LCD_send_char_4bit_mode(unsigned char ascii_value,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit,unsigned char is_in_low);
void LCD_inatialize_4bit_mode(unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit,unsigned char is_in_low);
void LCD_display_custom_char(unsigned char decemal_index_cgram,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_save_custom_char(unsigned char decemal_index_cgram,unsigned char custom_char_arr[],unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);
void LCD_send_float(double x,unsigned char lcd_port,unsigned char port_en_bit,unsigned char en_bit,unsigned char port_RS,unsigned char RS_bit);