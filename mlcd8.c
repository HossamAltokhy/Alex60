

#include "mlcd8.h"
#include <avr/io.h>
#include "DIO.h"
#define F_CPU 16000000UL
#include <util/delay.h>
#include "stdlib.h"


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
 // str [] = "Hello";  // '\0'
void LCD_str(char * str){
    
    for(int i =0; str[i] != '\0';i++){
        LCD_data(str[i]);
    }
    
}

void LCD_num ( int num){
    // num = 0123456789
    
    char num_str[11];
//    
//    for(int i = 9; i >=0; i--){
//        num_str[i] = '0' + num%10;
//        num = num/10.0;
//    }
    
//    itoa(integer, array , radix);
//    itoa(num, arr , 10);
    itoa(num, num_str, 10);
    
    
    LCD_str(num_str);
    
    
}