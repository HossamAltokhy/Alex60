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
#include "UART.h"


#define SPI_MODE_MSTR   1
#define SPI_MODE_SLAVE  0

#define MOSI    PB5
#define MISO    PB6
#define SCK     PB7
#define SS      PB4

#define SPI_PRE_4       0
#define SPI_PRE_16      1
#define SPI_PRE_64      2
#define SPI_PRE_128     3

#define SPI_PRESCALAR   SPI_PRE_128
#define SPI_SPEED_2X    0


//ISR(SPI_STC_vect){
//    LCD4_data(SPDR);
//}

void init_SPI(char SPI_MODE);

char SPI_send(char data);
char SPI_receive();
int main() {

    
    setPORTA_DIR(OUT);
    init_SPI(SPI_MODE_MSTR);
   
    

    
    //sei();
    while (1) {

        setPORTA(SPI_send('A'));
        
        _delay_ms(200);
        
       

    }

    return (EXIT_SUCCESS);
}

void init_SPI(char SPI_MODE){
 
    switch(SPI_MODE){
        case SPI_MODE_MSTR:
            // Define Pin Control Direction
            // DDRB |= (1<<MOSI)|(1<<SS)|(1<<SCK);
            setPINB_DIR(MOSI, OUT);
            setPINB_DIR(SS, OUT);
            setPINB_DIR(SCK, OUT);
            // SPI Control Register
            SPCR |= SPI_PRESCALAR; // (1<<SPR1)|(1<<SPR0); // Prescalar  >> Fosc/128
            SPSR |= (SPI_SPEED_2X<<SPI2X); // In case duplication is needed.
            SPCR |= (1<<MSTR); // Activate Master mode
            break;
            
        case SPI_MODE_SLAVE:
            // Define Pin Control Direction
            // DDRB |= (1<<MISO);
            setPINB_DIR(MISO, OUT);
            //SPCR |= (1<<SPIE); // Enable SPI INT.
            SPCR &= ~(1<<MSTR); // Activate SLAVE mode
            break;
    }
    
    
    SPCR |= (1<<SPE); // Enable SPI.
}

char SPI_send(char data){
    // put data in the data register
    SPDR = data;
    // Wait till data fully transmit....
    while(!(SPSR & (1<<SPIF)));
    // Transmission is Completed!!
    
    // read data received from slave
    return SPDR;
}

char SPI_receive(){
    // Wait till data fully received....
    while(!(SPSR & (1<<SPIF)));
    // read data received from Master
    return SPDR;
}