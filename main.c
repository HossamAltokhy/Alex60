/* 
 * File:   main.c
 * Author: hossa
 *
 * Created on August 8, 2025, 8:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>
#include "stdio.h"
#include "stdlib.h"

#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO.h"
#include "leds.h"
#include "buttons.h"
#include "keypad.h"
#include "kit_keypad.h"
#include "_7seg.h"
#include "mlcd8.h"


char str[] = "Hello";

int main() {
    int num = 39990;
    init_LCD();


    LCD_num(num);
    while (1) {




    }

    return (EXIT_SUCCESS);
}

