/*
 * File:   ecu1_main.c
 * Author: ANUSHA
 *
 * Created on 10 May, 2025, 12:36 PM
 */

#include <xc.h>
#include "ecu1_main.h"
#include "adc.h"
#include "clcd.h"
#include "matrix_keypad.h"
#include "ecu1_sensor.h"
#include "msg_id.h"
#include "can.h"

void init_config()
{
    init_matrix_keypad();
    init_clcd();
    init_adc();  
    init_can();
}

void main() 
{
    init_config();
    unsigned short int speed, gear_pos, temp;
    while(1)
    {
        speed = get_speed();
        gear_pos = get_gear_pos();
        temp = get_engine_temp();   
    }
}


