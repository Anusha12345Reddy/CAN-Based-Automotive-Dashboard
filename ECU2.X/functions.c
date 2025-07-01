
#include <xc.h>
#include "adc.h"
#include "clcd.h"
#include "digital_keypad.h"
#include "can.h"
#include "ecu2_sensor.h"
#include "ecu2_main.h"
#include "matrix_keypad.h"
#define _XTAL_FREQ 20000000

unsigned char flag;
unsigned long int delay;
unsigned int id, data_length;
unsigned char *arr[4] = {"L","R","O"};
int pos;

unsigned short int get_rpm()
{
    unsigned short int adc_val, rpm;
    char str[5];
    
    if (delay++ == 1000)
    {
        delay = 0;
        adc_val = read_adc(RPM_ADC_CHANNEL); 
        rpm = ((adc_val * (7000 - 1500)) / 1023) + 1500; 
        str[0] = (rpm / 1000) + '0';
        str[1] = (rpm / 100) % 10 + '0';
        str[2] = (rpm / 10) % 10 + '0';
        str[3] = rpm % 10 + '0';
        str[4] = '\0';
    }
    clcd_print("RPM", LINE1(12));
    clcd_print(str, LINE2(12));

    can_transmit(0x50, 4, str);

//    __delay_us(100);
//    if (can_receive(&id, &data_length, data) && id == 0x50) 
//    {
//        clcd_putch(data[0], LINE2(12));
//        clcd_putch(data[1], LINE2(13));
//        clcd_putch(data[2], LINE2(14));
//        clcd_putch(data[3], LINE2(15));
//    }    
}

IndicatorStatus get_indicator_status()
{
    unsigned short int key;
    key = read_switches(STATE_CHANGE);
    if(key == MK_SW1)
    {
        flag=e_ind_left;
    }
    else if(key == MK_SW2)
    {
        flag =e_ind_off;
    }
    else if(key == MK_SW3)
    {
        flag =e_ind_right;
    }
    
    if(flag == e_ind_left)
    {
//        RIGHT_IND_OFF();
//        if(delay++ == 10000)
//        {
//            RB0=!RB0;
//            RB1=!RB1;
//            delay = 0;
//        } 
        pos = 0;
        //clcd_putch(arr[0],LINE2(14));
    }
    else if(flag == e_ind_off)
    {
//        PORTB = 0x00;
        //clcd_putch(arr[2],LINE2(14));
        pos = 2;
    }
    else if(flag == e_ind_right)
    {
//        LEFT_IND_OFF();
//        if(delay++ == 10000)
//        {
//             RB7=!RB7;
//             RB6=!RB6;
//             delay = 0;
//        }
        pos = 1; 
    }
    clcd_print("IS",LINE1(9));
    can_transmit(0x40, 1, (unsigned char*)arr[pos]);
        __delay_us(100);
//        if (can_receive(&id, &data_length, data) && id == 0x40) 
//        {
//        clcd_putch(data[0], LINE2(9));
//      
//        }
}
