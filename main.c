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





void init_UART();
char UART_receive();
int main() {

    
    
    init_UART();
    

   
    DDRA = 0xFF;


    while (1) {

        PORTA = UART_receive();

    }

    return (EXIT_SUCCESS);
}

void init_UART(){
    // UCSRB 
    
    // Enable Tx, Rx
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    
    // Set BaudRate as 9600 while F_CPU = 16MHz
    UBRRL = 103;
}

void UART_send(char data){
    
    // Pooling 
    while(!(UCSRA & (1<<UDRE)));
    UDR = data; 
    
}

char UART_receive(){
    
    while(!(UCSRA & (1<<RXC)));
    
    return UDR;
    
}