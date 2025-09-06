#include <avr/io.h>
#include <avr/interrupt.h>
#include "TIMER0.h"

void init_Timer0(char mode, char clock) {

    Timer0_SELECT_MODE(mode);




    // Start....
    Timer0_CLOCK_SELECT(clock);
}

void Timer0_CLOCK_SELECT(char clock) {
    // TCCR0
    TCCR0 &= 0xF8; // 11111000
    TCCR0 |= clock;
}

void Timer0_SELECT_MODE(char TIMER_MODE) {
    switch (TIMER_MODE) {
        case TIMER0_NORMAL:
            TCCR0 &= ~((1 << WGM01) | (1 << WGM00));
            // Normal mode
            Timer0_OVF_INT(state_ENABLE);
            break;
        case TIMER0_CTC:
            TCCR0 &= ~(1 << WGM00);
            TCCR0 |= (1 << WGM01);
            OCR0 = TIMER0_OCR0; // 100
            // CTC mode
            Timer0_OCF_INT(state_ENABLE);
            break;
        case TIMER0_PWM:
            TCCR0 &= ~(1 << WGM01);
            TCCR0 |= (1 << WGM00);
            OCR0 = TIMER0_OCR0; // 100
            break;
        case TIMER0_FPWM:
            TCCR0 |= ((1 << WGM01) | (1 << WGM00));
            OCR0 = TIMER0_OCR0; // 100
            break;
    }
}

void Timer0_OVF_INT(char state) {
    // Enable individual Timer0 OV Interrupt
    if (state) {
        TIMSK |= (1 << TOIE0);
    } else {
        TIMSK &= ~(1 << TOIE0);
    }

}

void Timer0_OCF_INT(char state) {
    // Enable individual Timer0 OV Interrupt
    if (state) {
        TIMSK |= (1 << OCIE0);
    } else {
        TIMSK &= ~(1 << OCIE0);
    }

}
