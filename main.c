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
#include "TIMER2.h"
#include <string.h>




char str [] = "Hello World";

//ISR(INT0_vect) {
//    
//}
//ISR(INT1_vect) {
//    
//}
//ISR(INT2_vect) {
//    
//}




// 0 ..... 100


ISR(TIMER2_OVF_vect){
    
   
    togglePORTA();
    
}

int main() {

    //init_buttons();
    setPORTA_DIR(OUT);
    // OC0 pin as output pin.
    setPIND_DIR(PD7, OUT);
    TCCR2 |= (1<<COM21);
    TCCR2 &= ~(1<<COM20);
//    init_Timer2(TIMER2_FPWM, TIMER2_PRE_1024);
    init_Timer2_Async(TIMER2_NORMAL);

    
//    OCR_0= (1.0/16.32)*255   = 16
//    OCR_90= (1.5/16.32)*255   = 24
//    OCR_180= (2.0/16.32)*255  = 31
    sei();

    //init_LCD4();
    


    while (1) {

      
        OCR2 = 6;
       _delay_ms(1000);
       
        OCR2  = 37;

       _delay_ms(1000);
    }

    return (EXIT_SUCCESS);
}

