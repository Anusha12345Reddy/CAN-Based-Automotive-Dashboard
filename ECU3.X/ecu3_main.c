/*
 * File:   ecu3_main.c
 * Author: ANUSHA
 *
 * Created on 28 May, 2025, 10:07 AM
 */


#include <xc.h>
#include "can.h"
#include "clcd.h"
#include "main.h"
#include "msg_id.h"
#include "message_handler.h"
#include <stdio.h>
#include <stdlib.h>
#define _XTAL_FREQ 20000000

void main(void) 
{
    //init_adc();
    init_clcd();
    //init_matrix_keypad();
    init_can();
    unsigned short int speed, gear_pos, eng_temp,ind_status,rpm;

    while (1) 
    {
        speed = get_speed();
        gear_pos = get_gear_position();
        eng_temp = get_engine_temp();
        ind_status = get_indicator_status();
        rpm = get_rpm();
    }
}