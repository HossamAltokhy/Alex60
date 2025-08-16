#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "_7seg.h"
#include "DIO.h"


// Values

char values[] = {
    0x3F, // 0
    0x06, // 1
    0x5B, // 2
    0x4F, // 3
    0x66, // 4
    0x6D, // 5
    0x7D, // 6
    0x07, // 7
    0x7F, // 8
    0x6F, // 9

};

void init_7Seg() {
    // 7 segments connected to PORTA 
    setPORTA_DIR(OUT);

    // 7SEG_1 >> Enable --> PB1
    setPINB_DIR(PB1, OUT);
    // 7SEG_2 >> Enable --> PB2
    setPINB_DIR(PB2, OUT);

    _delay_ms(20);

    // Dashed
        setPINB(PB1, HIGH);
        setPINB(PB2, HIGH);
}

void _7seg_1_EN() {
    
    setPINB(PB2, HIGH);
    _delay_ms(2);
}

void _7seg_1_DIS() {
    
    setPINB(PB2, LOW);
    _delay_ms(5);
}

void _7seg_2_EN() {
    
    setPINB(PB1, HIGH);
    _delay_ms(2);
    
}

void _7seg_2_DIS() {
   
    setPINB(PB1, LOW);
    _delay_ms(5);


}

void _7seg_write(char num) {
    setPORTA(values[(int) num]);
}

void _7seg_1_write(char num) {
    PORTB = 0x04;
    _7seg_write(num);
    _delay_ms(10);
    PORTB = 0x00;
    
    
}

void _7seg_2_write(char num) {
    PORTB = 0x02;
    _7seg_write(num);
    _delay_ms(10);
    PORTB = 0x00;
    
}

