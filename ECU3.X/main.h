/* 
 * File:   main.h
 * Author: ANUSHA
 *
 * Created on 1 June, 2025, 9:58 PM
 */

#ifndef MAIN_H
#define	MAIN_H

#include <xc.h>

#define _XTAL_FREQ 20000000

/* Defines the data */
#define TRUE			1
#define FALSE			0

unsigned short int get_speed(); 
unsigned short int get_gear_position();
unsigned short int get_engine_temp();
unsigned short int get_indicator_status();
unsigned int get_rpm();
#endif	/* MAIN_H */

