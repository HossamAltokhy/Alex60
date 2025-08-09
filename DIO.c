#include "DIO.h"
#include <avr/io.h>



void setPINA_DIR(char pinNUM, char pinDirection) {

    switch (pinDirection) {
        case OUT:
            // set as output pin.
            DDRA |= (1 << pinNUM);
            break;
        case IN:
            // set as input pin.
            DDRA &= ~(1 << pinNUM);
            break;

    }



}


void setPORTA_DIR(char portDirection){
    
    switch(portDirection){
        case OUT:
            DDRA = 0xFF; //0b11111111;
            break;
        case IN:
            DDRA = 0x00; // 0b00000000;
            break;
    }
    
    
    
    
}

void setPINA(char pinNUM, char state){
    
    switch(state){
        case HIGH:
            // set pinA to be HIGH 5V.
            PORTA |= (1<<pinNUM);  // |x| -> 1
            break;
        case LOW:
            // reset pinA to be LOW 0V.
            PORTA &= ~(1<<pinNUM); // |x| -> 0
            break;
    }
    
    
}

void setPORTA(char state){
    switch(state){
        case HIGH:
            PORTA = 0xFF;
            break;
        case LOW:
            PORTA = 0x00;
            break;
    }
}


void togglePINA(char pinNUM){
    
    PORTA ^= (1<<pinNUM);
    
}

void togglePORTA(){
    PORTA ^= 0xFF;
}


char checkPINA(char pinNUM){
    
    if(PINA & (1<<pinNUM)){
        // True -> input High 5V.
        return 1;
    }
    else{
        // False -> input Low 0V.
        return 0;
    }
    
    
}

char checkPORTA(){
    return PINA;
}




void setPINB_DIR(char pinNUM, char pinDirection) {

    switch (pinDirection) {
        case OUT:
            // set as output pin.
            DDRB |= (1 << pinNUM);
            break;
        case IN:
            // set as input pin.
            DDRB &= ~(1 << pinNUM);
            break;

    }



}


void setPORTB_DIR(char portDirection){
    
    switch(portDirection){
        case OUT:
            DDRB = 0xFF; //0b11111111;
            break;
        case IN:
            DDRB = 0x00; // 0b00000000;
            break;
    }
    
    
    
    
}

void setPINB(char pinNUM, char state){
    
    switch(state){
        case HIGH:
            // set PINB to be HIGH 5V.
            PORTB |= (1<<pinNUM);  // |x| -> 1
            break;
        case LOW:
            // reset PINB to be LOW 0V.
            PORTB &= ~(1<<pinNUM); // |x| -> 0
            break;
    }
    
    
}

void setPORTB(char state){
    switch(state){
        case HIGH:
            PORTB = 0xFF;
            break;
        case LOW:
            PORTB = 0x00;
            break;
    }
}


void togglePINB(char pinNUM){
    
    PORTB ^= (1<<pinNUM);
    
}

void togglePORTB(){
    PORTB ^= 0xFF;
}


char checkPINB(char pinNUM){
    
    if(PINB & (1<<pinNUM)){
        // True -> input High 5V.
        return 1;
    }
    else{
        // False -> input Low 0V.
        return 0;
    }
    
    
}

char checkPORTB(){
    return PINB;
}



void setPINC_DIR(char pinNUM, char pinDirection) {

    switch (pinDirection) {
        case OUT:
            // set as output pin.
            DDRC |= (1 << pinNUM);
            break;
        case IN:
            // set as input pin.
            DDRC &= ~(1 << pinNUM);
            break;

    }



}


void setPORTC_DIR(char portDirection){
    
    switch(portDirection){
        case OUT:
            DDRC = 0xFF; //0b11111111;
            break;
        case IN:
            DDRC = 0x00; // 0b00000000;
            break;
    }
    
    
    
    
}

void setPINC(char pinNUM, char state){
    
    switch(state){
        case HIGH:
            // set PINC to be HIGH 5V.
            PORTC |= (1<<pinNUM);  // |x| -> 1
            break;
        case LOW:
            // reset PINC to be LOW 0V.
            PORTC &= ~(1<<pinNUM); // |x| -> 0
            break;
    }
    
    
}

void setPORTC(char state){
    switch(state){
        case HIGH:
            PORTC = 0xFF;
            break;
        case LOW:
            PORTC = 0x00;
            break;
    }
}


void togglePINC(char pinNUM){
    
    PORTC ^= (1<<pinNUM);
    
}

void togglePORTC(){
    PORTC ^= 0xFF;
}


char checkPINC(char pinNUM){
    
    if(PINC & (1<<pinNUM)){
        // True -> input High 5V.
        return 1;
    }
    else{
        // False -> input Low 0V.
        return 0;
    }
    
    
}

char checkPORTC(){
    return PINC;
}



void setPIND_DIR(char pinNUM, char pinDirection) {

    switch (pinDirection) {
        case OUT:
            // set as output pin.
            DDRD |= (1 << pinNUM);
            break;
        case IN:
            // set as input pin.
            DDRD &= ~(1 << pinNUM);
            break;

    }



}


void setPORTD_DIR(char portDirection){
    
    switch(portDirection){
        case OUT:
            DDRD = 0xFF; //0b11111111;
            break;
        case IN:
            DDRD = 0x00; // 0b00000000;
            break;
    }
    
    
    
    
}

void setPIND(char pinNUM, char state){
    
    switch(state){
        case HIGH:
            // set PIND to be HIGH 5V.
            PORTD |= (1<<pinNUM);  // |x| -> 1
            break;
        case LOW:
            // reset PIND to be LOW 0V.
            PORTD &= ~(1<<pinNUM); // |x| -> 0
            break;
    }
    
    
}

void setPORTD(char state){
    switch(state){
        case HIGH:
            PORTD = 0xFF;
            break;
        case LOW:
            PORTD = 0x00;
            break;
    }
}


void togglePIND(char pinNUM){
    
    PORTD ^= (1<<pinNUM);
    
}

void togglePORTD(){
    PORTD ^= 0xFF;
}


char checkPIND(char pinNUM){
    
    if(PIND & (1<<pinNUM)){
        // True -> input High 5V.
        return 1;
    }
    else{
        // False -> input Low 0V.
        return 0;
    }
    
    
}

char checkPORTD(){
    return PIND;
}