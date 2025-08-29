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

int main() {

    init_LCD4();
    
    int data = 0;
    init_ADC(CH0, Vref_AVCC, PRE_128);



    while (1) {


        // Start Conversion
        ADC_SC();
        ADC_wait();
        data = ADC_read();
        
        LCD4_num(data);
        
        _delay_ms(5);
        
        ADC_select_CH(CH1);
        ADC_SC();
        ADC_wait();
        data = ADC_read();
        LCD4_cmd(0xC0);
        LCD4_num(data);
        
        
        _delay_ms(500);
        LCD4_cmd(0x01);
        ADC_select_CH(CH0);
    }

    return (EXIT_SUCCESS);
}

