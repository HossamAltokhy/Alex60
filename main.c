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
#include "TWI.h"
#include <avr/eeprom.h>

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


#define MEM_24C16_W     0xA0//1010XXX0
#define MEM_24C16_R     0xA1//1010XXX1
#define DEV_ADDRESS     0x07
//ISR(SPI_STC_vect){
//    LCD4_data(SPDR);
//}

void init_SPI(char SPI_MODE);

char SPI_send(char data);
char SPI_receive();


void MEM_24C16_CURRENT_WRITE(char data);
char MEM_26C16_CURRENT_READ();

char MEM_24C16_WRITE(short MEM_LOC, char data);
char MEM_26C16_READ(short MEM_LOC);

int main() {

    init_LCD4();
    
    eeprom_write_byte(0x00AA, 90);
    
    
    //init_TWI(DEV_ADDRESS);

    _delay_ms(50);

    char data = eeprom_read_byte(0x00AA);
    //MEM_24C16_WRITE(0x0007, 90);

    _delay_ms(50);
    
    

    //char data = MEM_26C16_READ(0x0007);
    
    LCD4_data(data);
    while (1) {




    }

    return (EXIT_SUCCESS);
}

char MEM_24C16_WRITE(short MEM_LOC, char data) {
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT)));
    char status = (TWSR & 0xF8);
    if (status != 0x08) {
        return -1;
    }
    // Start Condition Sent..

    // send MEM Address + Write bit
    TWDR = MEM_24C16_W;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x18) {
        return -1;
    }
//    // Send High Byte of Word Address
//    TWDR = (char) (MEM_LOC >> 8);
//    TWCR = (1 << TWINT) | (1 << TWEN);
    // Send Low Byte of Word Address
    while (!(TWCR & (1 << TWINT)));
    TWDR = (char) (MEM_LOC);
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Check Status
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x28) {
        return -1;
    }
    // Send Data
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Check Status
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x28) {
        return -1;
    }
    // Stop Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    
    return 0;

}

char MEM_26C16_READ(short MEM_LOC) {
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT)));
    char status = (TWSR & 0xF8);
    if (status != 0x08) {
        return -1;
    }
    // Start Condition Sent..

    // send MEM Address + Write bit
    TWDR = MEM_24C16_W;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x18) {
        return -1;
    }
//    // Send High Byte of Word Address
//    TWDR = (char) (MEM_LOC >> 8);
//    TWCR = (1 << TWINT) | (1 << TWEN);
    // Send Low Byte of Word Address
    while (!(TWCR & (1 << TWINT)));
    TWDR = (char) (MEM_LOC);
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Check Status
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x28) {
        return -1;
    }
    
    // Repeated start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x10) {
        return -1;
    }
    // Repeated start Condition Sent..
    
    // Load SLA+R
    TWDR = MEM_24C16_R; //(address<<1)+1; SLA+R (8-bits)
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Check Status
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x40) {
        return -1;
    }
    // Enable ACK
    TWCR = (1 << TWINT) | (1 << TWEN)|(1 << TWEA);
    // Check Status
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x50) {
        return -1;
    }
    // Read Data 
    char data = TWDR;
    // Stop Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    
    return data;
}

void MEM_24C16_CURRENT_WRITE(char data) {
    TWI_MT(MEM_24C16_W, data);
}

char MEM_26C16_CURRENT_READ() {

    char data = TWI_MR(MEM_24C16_R);

    return data;
}

void init_SPI(char SPI_MODE) {

    switch (SPI_MODE) {
        case SPI_MODE_MSTR:
            // Define Pin Control Direction
            // DDRB |= (1<<MOSI)|(1<<SS)|(1<<SCK);
            setPINB_DIR(MOSI, OUT);
            setPINB_DIR(SS, OUT);
            setPINB_DIR(SCK, OUT);
            // SPI Control Register
            SPCR |= SPI_PRESCALAR; // (1<<SPR1)|(1<<SPR0); // Prescalar  >> Fosc/128
            SPSR |= (SPI_SPEED_2X << SPI2X); // In case duplication is needed.
            SPCR |= (1 << MSTR); // Activate Master mode
            break;

        case SPI_MODE_SLAVE:
            // Define Pin Control Direction
            // DDRB |= (1<<MISO);
            setPINB_DIR(MISO, OUT);
            //SPCR |= (1<<SPIE); // Enable SPI INT.
            SPCR &= ~(1 << MSTR); // Activate SLAVE mode
            break;
    }


    SPCR |= (1 << SPE); // Enable SPI.
}

char SPI_send(char data) {
    // put data in the data register
    SPDR = data;
    // Wait till data fully transmit....
    while (!(SPSR & (1 << SPIF)));
    // Transmission is Completed!!

    // read data received from slave
    return SPDR;
}

char SPI_receive() {
    // Wait till data fully received....
    while (!(SPSR & (1 << SPIF)));
    // read data received from Master
    return SPDR;
}