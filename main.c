/* 
 * File:   main.c
 * Author: hossa
 *
 * Created on August 8, 2025, 8:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include <avr/interrupt.h>


#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO.h"
#include "leds.h"
#include "buttons.h"
#include "keypad.h"
#include "kit_keypad.h"
#include "_7seg.h"
#include "mlcd4.h"
#include "ADC.h"
#include "lm35.h"
#include "TIMER0.h"
#include <string.h>


#define  INT_MODE_LOW        0
#define  INT_MODE_ANY        1
#define  INT_MODE_FALLING    2   // 00000010
#define  INT_MODE_RISING     3

char str [] = "Hello World";

ISR(INT0_vect) {
    led_tog_all();
}

void init_INT(char INT, char mode) {

    switch (INT) {
        case INT0:
            MCUCR &= ~((1 << ISC01) | (1 << ISC00));
            MCUCR |= mode;

            break;
        case INT1:
            MCUCR &= ~((1 << ISC01) | (1 << ISC00));
            MCUCR |= mode << 2;

            break;
        case INT2:
            if (mode == INT_MODE_RISING) {
                MCUCSR |= (1 << ISC2);
            } else {
                MCUCSR &= ~(1 << ISC2);
            }

            break;
    }


    GICR |= (1 << INT);

}



ISR(TIMER0_OVF_vect){
    
    // 61 times per Second
    // 16.25 mSec code
    static int x = 0;
    x++;
    if(x == 61){
        led_tog(LED1);
        x = 0;
    }
    
    
    
}


int main() {

    init_LEDS();
    init_Timer0(TIMER0_NORMAL, TIMER0_PRE_1024);
    
    
    sei();


    
    while (1) {

    
    }

    return (EXIT_SUCCESS);
}

