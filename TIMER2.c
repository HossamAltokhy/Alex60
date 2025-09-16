#include <avr/io.h>
#include <avr/interrupt.h>
#include "TIMER0.h"
#include "TIMER2.h"

void init_Timer2(char mode, char clock) {

    Timer2_SELECT_MODE(mode);




    // Start....
    Timer2_CLOCK_SELECT(clock);
}


void init_Timer2_Async(char mode){
    
    // You could save the values of TCCR2 & OCR2
    // at Temp variables
    
    
    // Disable Timer2 interrupts
    Timer2_OVF_INT(state_DISABLE);
    Timer2_OCF_INT(state_DISABLE);
    
    // Enable AS2 
    ASSR |= (1<<AS2);
    
    
    
    
    TCNT2 = 0;
    OCR2 = TIMER2_OCR2;
    Timer2_SELECT_MODE(mode);
    
    TCCR2 |= (1<<COM21);
    TCCR2 &= ~(1<<COM20);
    
    
    while(ASSR & (1<<TCN2UB));
    while(ASSR & (1<<TCR2UB));
    while(ASSR & (1<<OCR2UB));
    
    Timer2_CLEAR_INTs();
    
    // Enable Timer2 interrupts
    Timer2_OVF_INT(state_ENABLE);
//    Timer2_OCF_INT(state_ENABLE);
    
}


void Timer2_CLEAR_INTs(){
    
    TIFR &= ~((1<<TOV2)|(1<<OCF2));
    
}

void Timer2_CLOCK_SELECT(char clock) {
    // TCCR0
    TCCR2 &= 0xF8; // 11111000
    TCCR2 |= clock;
}


void Timer2_SELECT_MODE(char TIMER_MODE) {
    switch (TIMER_MODE) {
        case TIMER2_NORMAL:
            TCCR2 &= ~((1 << WGM21) | (1 << WGM20));
            // Normal mode
            Timer2_OVF_INT(state_ENABLE);
            break;
        case TIMER2_CTC:
            TCCR2 &= ~(1 << WGM20);
            TCCR2 |= (1 << WGM21);
            OCR2 = TIMER2_OCR2; // 100
            // CTC mode
            Timer2_OCF_INT(state_ENABLE);
            break;
        case TIMER2_PWM:
            TCCR2 &= ~(1 << WGM21);
            TCCR2 |= (1 << WGM20);
            OCR2 = TIMER2_OCR2; // 100
            break;
        case TIMER2_FPWM:
            TCCR2 |= ((1 << WGM21) | (1 << WGM20));
            OCR2 = TIMER2_OCR2; // 100
            break;
    }
}


void Timer2_OVF_INT(char state) {
    // Enable individual Timer0 OV Interrupt
    if (state) {
        TIMSK |= (1 << TOIE2);
    } else {
        TIMSK &= ~(1 << TOIE2);
    }

}


void Timer2_OCF_INT(char state) {
    // Enable individual Timer0 OV Interrupt
    if (state) {
        TIMSK |= (1 << OCIE2);
    } else {
        TIMSK &= ~(1 << OCIE2);
    }

}

