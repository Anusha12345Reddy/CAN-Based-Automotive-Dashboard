/* 
 * File:   ecu1_sensor.h
 * Author: ANUSHA
 *
 * Created on 10 May, 2025, 12:49 PM
 */

#ifndef ECU1_SENSOR_H
#define	ECU1_SENSOR_H

#include <stdint.h>
#include "matrix_keypad.h"
#include "adc.h"
//#include "can.h"
#include "msg_id.h"
#include "clcd.h"

#define MAX_GEAR 6
#define SPEED_ADC_CHANNEL 0x04
#define ENG_TEMP_ADC_CHANNEL 0x06

#define GEAR_UP             MK_SW1
#define GEAR_DOWN           MK_SW2
#define COLLISION           MK_SW3

unsigned short int get_speed();
unsigned char get_gear_pos();
unsigned short int get_engine_temp();

#endif	/* ECU1_SENSOR_H */

