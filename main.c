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

int main() {

    init_LEDS();
//    init_kit_keypad();
    setPINA(PA1, IN);
    while (1) {
//
//        switch(kit_keypad_getNum()){
//            case 1:
//            case 4:
//            case 7:
//                led_on(LED1);
//                _delay_ms(5);
//                break;
//            case 2:
//            case 5:
//            case 8:
//                led_on(LED2);
//                _delay_ms(5);
//                break;
//            case 3:
//            case 6:
//            case 9:
//                led_on(LED3);
//                _delay_ms(5);
//                break;
//            case 0:
//                led_off_all();
//                _delay_ms(5);
//        }
        
        
        if(checkPINA(PA1)){
            led_on_all();
        }
        else{
            led_off_all();
        }
        _delay_ms(15);
       

    }

    return (EXIT_SUCCESS);
}

