

#include <avr/io.h>
#include "SPI.h"
#include "DIO.h"


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
