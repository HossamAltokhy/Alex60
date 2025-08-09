/* 
 * File:   leds.h
 * Author: hossa
 *
 * Created on August 8, 2025, 10:53 AM
 */

#ifndef LEDS_H
#define	LEDS_H

#define LED1   3  // PB3
#define LED2   2  // PC2
#define LED3   7  // PC7
#define LED4   6  // PD6

void init_LEDS();

void led_on(char ledNum);
void led_off(char ledNum);
void led_tog(char ledNum);


void led_on_all();
void led_off_all();
void led_tog_all();

#endif	/* LEDS_H */

