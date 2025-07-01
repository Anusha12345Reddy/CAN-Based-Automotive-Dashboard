/*
 * File:   ecu2_main.c
 * Author: ANUSHA
 *
 * Created on 15 May, 2025, 10:15 AM
 */

#include <xc.h>
#include "adc.h"
#include "clcd.h"
#include "digital_keypad.h"
#include "can.h"
#include "ecu2_sensor.h"
#include "ecu2_main.h"
#include "matrix_keypad.h"

void init_config()
{
    //TRISB = 0x00;
    //PORTB = 0x00;
    init_adc();
    init_clcd();
    init_can();
    //init_digital_keypad();
    init_matrix_keypad();
}

void main() 
{
    init_config();
    unsigned short int rpm, indicator;
    while(1)
    {
        indicator = get_indicator_status();
        rpm = get_rpm();  
    }
}
