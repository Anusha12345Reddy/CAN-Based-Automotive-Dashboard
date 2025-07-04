/* 
 * File:   message_handler.h
 * Author: ANUSHA
 *
 * Created on 1 June, 2025, 9:45 PM
 */

#ifndef MESSAGE_HANDLER_H
#define	MESSAGE_HANDLER_H

#include <stdint.h>
#include <xc.h>
#include "clcd.h"
#include "can.h"
#include "msg_id.h"

#define LED_OFF 0
#define LED_ON 1

#define RIGHT_IND_ON() (PORTB = PORTB | 0xC0)
#define RIGHT_IND_OFF() (PORTB = PORTB & ~0xC0)
#define LEFT_IND_ON() (PORTB = PORTB | 0x03)
#define LEFT_IND_OFF() (PORTB = PORTB & ~0x03)

extern volatile unsigned char led_state, status;

typedef enum {
    e_ind_off,
    e_ind_left,
    e_ind_right
} IndicatorStatus;

void process_canbus_data();
void handle_speed_data(uint8_t *data, uint8_t len);
void handle_gear_data(uint8_t *data, uint8_t len);
void handle_rpm_data(uint8_t *data, uint8_t len);
void handle_engine_temp_data(uint8_t *data, uint8_t len);
void handle_indicator_data(uint8_t *data, uint8_t len);

#endif	/* MESSAGE_HANDLER_H */

