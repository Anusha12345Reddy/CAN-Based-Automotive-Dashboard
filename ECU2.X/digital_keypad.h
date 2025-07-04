/* 
 * File:   digital_keypad.h
 * Author: ANUSHA
 *
 * Created on 15 May, 2025, 10:218 AM
 */

#ifndef DIGITAL_KEYPAD_H
#define DIGITAL_KEYPAD_H

#define LEVEL					     	0
#define STATE_CHANGE			       	1

#define KEY_PORT					PORTC

#define SWITCH1                     0x0E
#define SWITCH2                     0x0D
#define SWITCH3					0x0B
#define SWITCH4					0x07
#define ALL_RELEASED            0x0F

#define INPUT_PINS					0x0F

void init_digital_keypad(void);
unsigned char read_digital_keypad(unsigned char detection_type);

#endif


