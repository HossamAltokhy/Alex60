

#include "mlcd8.h"
#include <avr/io.h>
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>


void init_LCD(){
    // set LCD_DIR to be output port
    LCD_DATA_DIR = 0xFF;
    LCD_COM_PIN_DIR |= (1<<LCD_RS)|(1<<LCD_EN);
    //......
    
   LCD_cmd(0x60); 
   LCD_cmd(0x0F); 
   LCD_cmd(0x0C); 
   LCD_cmd(0x01);
   
   _delay_ms(50);

}

void LCD_enable(){
    LCD_COM_PIN |= (1<<LCD_EN);
    _delay_ms(5);
    LCD_COM_PIN &= ~(1<<LCD_EN);
}

void LCD_data(char data){
    // Register select
    LCD_COM_PIN |= (1<<LCD_RS);
    LCD_DATA = data;
    LCD_enable();
    
}
void LCD_cmd(char cmd){
    // Register select
    LCD_COM_PIN &= ~(1<<LCD_RS);
    LCD_DATA = cmd;
    LCD_enable();
}
