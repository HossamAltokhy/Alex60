#include <avr/io.h>
#include "UART.h"
#define F_CPU 16000000UL
#include <util/delay.h>



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

