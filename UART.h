/* 
 * File:   UART.h
 * Author: hossa
 *
 * Created on September 26, 2025, 9:59 AM
 */

#ifndef UART_H
#define	UART_H


#define BAUDRATE_9600     9600
//#define BAUDRATE_2400     2400



void init_UART(int Baudrate);
char UART_receive();
void UART_send(char data);
void UART_str(char * str);
void UART_num(long int num);

#endif	/* UART_H */

