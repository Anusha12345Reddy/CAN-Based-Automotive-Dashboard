
#include <xc.h>
#include "adc.h"
#include "clcd.h"
#include "matrix_keypad.h"
#include "ecu1_sensor.h"
#include "ecu1_main.h"
#include "msg_id.h"
#include "can.h"

unsigned int id, data_length;
unsigned char data[8];

unsigned short int get_speed()
{
    unsigned short int speed;
    unsigned int delay;
    //if(delay++==1000)
    {
        speed = read_adc(CHANNEL4)/10;
        if(speed > 100)
            speed = 99;
        char str[3];
        str[1] = speed % 10 + '0'; 
        str[0] = speed / 10 + '0'; 
        str[2] = '\0';
        clcd_print("SP",LINE1(0));
        clcd_print(str,LINE2(0));
        can_transmit(0x10, 2, str);
        __delay_us(100);

//        can_receive(&id, &data_length, data);
//        clcd_putch(data[0], LINE2(0));
//        clcd_putch(data[1], LINE2(1));
//        if (can_receive(&id, &data_length, data) && id == 0x10) 
//        {
//        clcd_putch(data[0], LINE2(0));
//        clcd_putch(data[1], LINE2(1));
//        }

    }
    return speed;
}

unsigned char get_gear_pos()
{
    unsigned char key;
    unsigned char *gear_arr[8] = {"GN", "G1", "G2", "G3", "G4", "G5", "GR", "CS"};
    unsigned short int pos = 0;
    key = read_switches(STATE_CHANGE);
    if(key==MK_SW1)
    {
        if(pos<6)
        {
            pos++;
        }
    }
    else if(key==MK_SW2)
    {
        if(pos>0)
        {
            pos--;
        }
    }
    else if(key == MK_SW3)
    {
        pos = 7;
    }
    clcd_print("GP", LINE1(3));
    //clcd_print(gear_arr[pos], LINE2(3));
    //return pos;
    can_transmit(0x20, 2, (unsigned char*)gear_arr[pos]);
    //__delay_us(100);
//    if (can_receive(&id, &data_length, data) && id == 0x20) 
//    {
//        clcd_putch(data[0], LINE2(3));
//        clcd_putch(data[1], LINE2(4));
//    }
}
    
unsigned short int get_engine_temp()
{
    unsigned int delay1;
    unsigned short int adc_reg_value;
    float volt,temp;
    char str1[3];
    if(delay1++==1000)
    {
        adc_reg_value = read_adc(CHANNEL6);
        volt = (adc_reg_value*5.0)/1023.0;
        temp = volt*100;
        if(temp >= 18 && temp <= 32)
        {
            str1[1] = (unsigned short int)temp % 10 +'0';
            str1[0] = (unsigned short int)temp / 10 +'0';
            str1[2] = '\0';
        }
        clcd_print("TMP",LINE1(6));
        clcd_print(str1,LINE2(6)); 
        can_transmit(0x30,2,str1);

        //__delay_us(100);

//        if (can_receive(&id, &data_length, data) && id == 0x30) 
//        {
//        clcd_putch(data[0], LINE2(6));
//        clcd_putch(data[1], LINE2(7));
//        }
        delay1 = 0;
    }
    return(unsigned short int)temp;
}

