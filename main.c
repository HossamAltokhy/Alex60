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


int data = 0;
int i = 0;

char str1[]= "Temp";
char str2[]= " = ";
char str3[]= "'C";

ISR(ADC_vect) {

    data = LM35_read();
    LCD4_cmd(0x01);
    LCD4_str(str1);
    LCD4_num(i);
    LCD4_str(str2);
    LCD4_num(data);
    LCD4_str(str3);

}

int main() {

    


    init_LCD4();

    init_LM35(TempSensor0);

    sei();
    
    while (1) {

      
        LM35_sample();
        _delay_ms(900);
        i++;
        if(i > 3){
            i = 0;
        }
        LM35_select(TempSensor0+i);
        
        
        
       
        


    }

    return (EXIT_SUCCESS);
}

