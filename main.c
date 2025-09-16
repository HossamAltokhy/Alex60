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
#include "TIMER1.h"
#include "TIMER0.h"
#include <string.h>




ISR(TIMER1_CAPT_vect){
    
   
    PORTA =  ICR1L;
    PORTB =  ICR1H;
    
}

int main() {


    setPORTA_DIR(OUT);
    setPORTB_DIR(OUT);
    
    init_TIMER1(TIMER1_CTC, TIMER1_PRE_1024);
    
    Timer1_ICPF_INT(state_ENABLE);
    
    sei();

   
    


    while (1) {

      

    }

    return (EXIT_SUCCESS);
}

