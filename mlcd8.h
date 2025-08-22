/* 
 * File:   mlcd8.h
 * Author: hossa
 *
 * Created on August 16, 2025, 10:56 AM
 */

#ifndef MLCD8_H
#define	MLCD8_H

#define LCD_COM_PIN_DIR  DDRB
#define LCD_COM_PIN      PORTB
#define LCD_RS      PB0
#define LCD_EN      PB1

#define LCD_DATA        PORTA
#define LCD_DATA_DIR    DDRA

void init_LCD();
void LCD_enable();
void LCD_data(char data);
void LCD_cmd(char cmd);


// HW
void LCD_str(char * str);
void LCD_num (long int num);

#endif	/* MLCD8_H */

