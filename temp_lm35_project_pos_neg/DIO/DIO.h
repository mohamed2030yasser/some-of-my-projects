#include "std_macros.h"
void DIO_set_bit_dir(unsigned char port ,unsigned char pin ,unsigned char dir);
void DIO_write_bit(unsigned char port ,unsigned char pin ,unsigned char write);
void DIO_tog_bit(unsigned char port ,unsigned char pin );
unsigned char DIO_read_bit_u8(unsigned char port ,unsigned char pin );
void DIO_set_dir(unsigned char port,char dir_hex);
void DIO_write_port(unsigned char port ,unsigned char val);
unsigned char DIO_read_pin_u8(unsigned char port );
void DIO_tog_port(unsigned char port );
void DIO_internal_pullup_enable(unsigned char port,unsigned char pin);
void DIO_internal_pullup_disable(unsigned char port,unsigned char pin);
void DIO_write_Low_4bits_port(unsigned char port,unsigned char val);
void DIO_write_Most_4bits_port(unsigned char port,unsigned char val);