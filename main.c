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


#define BAUDRATE_9600     9600
//#define BAUDRATE_2400     2400



ISR(USART_RXC_vect){
    
    char data = UDR;
    switch(data){
        case 'A':
            led_on(LED1);
            break;
        case 'B':
            led_on(LED2);
            break;
        case 'C':
            led_on(LED3);
            break;
        case 'D':
            led_off_all();
            break;
            
    }
    LCD4_data(data);
    
}


void init_UART(int Baudrate);
char UART_receive();
void UART_send(char data);

int main() {

    
    init_LCD4();
    
    init_buttons();
    init_LEDS();
    
    init_UART(9600);
    

   
    DDRA = 0xFF;


    sei();
    while (1) {

        
        if(isPressed(button0)){
             UART_send('A');
             _delay_ms(200);
        }
       

    }

    return (EXIT_SUCCESS);
}

void init_UART(int Baudrate){
    // UCSRB 
    
    // Enable Tx, Rx
    UCSRB |= (1<<TXEN)|(1<<RXEN);
    
    // Enable RX Interrupt
    UCSRB |= (1<<RXCIE);
    
    // Set BaudRate as 9600 while F_CPU = 16MHz
    //UBRRL = 103;
    short UBAUDR = (F_CPU / 16.0/Baudrate)-1;
    if(UBAUDR > 255){
        UBRRH  = (char)(UBAUDR>>8);
    }
    UBRRL = (char) UBAUDR;
    
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