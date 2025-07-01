
#include <xc.h>
#include "clcd.h"
#include "can.h"
#include "message_handler.h"
#include "msg_id.h"
#include "main.h"

unsigned int id, data_length;
unsigned char data[8];

unsigned short int get_speed() 
{
    clcd_print("SP", LINE1(0));
    __delay_us(100);
    if (can_receive(&id, &data_length, data) && id == 0x10) 
    {
        clcd_putch(data[0], LINE2(0));
        clcd_putch(data[1], LINE2(1));
    }
}

unsigned short int get_gear_position() 
{
    clcd_print("GP", LINE1(3));
    __delay_us(100);
    if (can_receive(&id, &data_length, data) && id == 0x20) 
    {
        clcd_putch(data[0], LINE2(3));
        clcd_putch(data[1], LINE2(4));
    }
}

unsigned short int get_engine_temp() 
{
    clcd_print("ET", LINE1(6));
    if (can_receive(&id, &data_length, data) && id == 0x30) 
    {
        clcd_putch(data[0], LINE2(6));
        clcd_putch(data[1], LINE2(7));
    }
}

unsigned short int get_indicator_status()
{
    clcd_print("IS",LINE1(9));
    __delay_us(100);
    if (can_receive(&id, &data_length, data) && id == 0x40) 
    {
        clcd_putch(data[0], LINE2(9));
      //clcd_putch(data[1], LINE2(1));
    }
}

unsigned int get_rpm()
{
    clcd_print("RPM",LINE1(12));
    __delay_us(100);
    if (can_receive(&id, &data_length, data) && id == 0x50) 
    {
        clcd_putch(data[0], LINE2(12));
        clcd_putch(data[1], LINE2(13));
        clcd_putch(data[2], LINE2(14));
        clcd_putch(data[3], LINE2(15));
    }
}