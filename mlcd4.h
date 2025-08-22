/* 
 * File:   mlcd4.h
 * Author: hossa
 *
 * Created on August 22, 2025, 10:18 AM
 */

#ifndef MLCD4_H
#define	MLCD4_H


#define LCD4_DATA_DIR   DDRA
#define LCD4_COM_DIR    DDRB

#define LCD4_DATA   PORTA
#define LCD4_COM    PORTB

#define LCD4_RS     PB1
#define LCD4_EN     PB2

void init_LCD4();

void LCD4_data(char data);
void LCD4_cmd(char cmd);
void LCD4_str(char *str);
void LCD4_num(int num);
void LCD4_enable();
void LCD4_cmdS(char cmd);
#endif	/* MLCD4_H */

