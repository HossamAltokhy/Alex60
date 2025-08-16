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
#include "mlcd8.h"

int main() {

    init_LCD();

  LCD_data('A');
  LCD_data('h');
  LCD_data('m');
  LCD_data('e');
  LCD_data('d');
    while (1) {

        

    }

    return (EXIT_SUCCESS);
}

