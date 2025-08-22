/* 
 * File:   main.c
 * Author: hossa
 *
 * Created on August 8, 2025, 8:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>


#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO.h"
#include "leds.h"
#include "buttons.h"
#include "keypad.h"
#include "kit_keypad.h"
#include "_7seg.h"
#include "mlcd4.h"
#include <string.h>

int main() {
    
    init_LCD4();

    init_keypad();

    
    LCD4_data('A');
    while (1) {

        
        LCD4_data(keypad_read());
        _delay_ms(250);


    }

    return (EXIT_SUCCESS);
}

