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



int main() {

    // set bit2 on DDRA to set it as output pin.
    DDRA |= (1 << LED_YELLOW);
    
    setPINA_DIR(LED_YELLOW, OUT);
    
    init_LEDS();





    while (1) {

        // Set bit2 on PORTA to drive led with 5V.
        PORTA |= (1 << LED_YELLOW);


        // apply some delay to recognize sequence.
        _delay_ms(500);

        // Reset bit2 on PORTA to disable led.
        PORTA &= ~(1 << LED_YELLOW);


        // apply some delay to recognize sequence.
        _delay_ms(500);
    }

    return (EXIT_SUCCESS);
}

