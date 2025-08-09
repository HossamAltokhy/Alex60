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

int main() {

    init_LEDS();
    init_keypad();
    setPORTD_DIR(OUT);
    
    while (1) {

        
        PORTD = keypad_read();
        _delay_ms(50);

    }

    return (EXIT_SUCCESS);
}

