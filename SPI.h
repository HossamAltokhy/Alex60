/* 
 * File:   SPI.h
 * Author: hossa
 *
 * Created on October 17, 2025, 9:38 AM
 */

#ifndef SPI_H
#define	SPI_H


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

#endif	/* SPI_H */

