
#include "mlcd4.h"
#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO.h"


#include <stdlib.h>

void init_LCD4() {

    // DIO pins 
    LCD4_DATA_DIR |= 0xF0;
    LCD4_COM_DIR |= (1 << LCD4_RS) |
            (1 << LCD4_EN);


    // commands
    
    
    LCD4_cmd(0x02); // Function set 4bit (special case)
    LCD4_cmd(0x28); // Function set 4bit - 2lines
    LCD4_cmd(0x0F); // Display on Curser ON & Blinking
    LCD4_cmd(0x06); // Entry Mode
    LCD4_cmd(0x02); // Return Home

}


// DDDD XXXX

void LCD4_data(char data) {
    // RS = 1
    LCD4_COM |= (1 << LCD4_RS);
    // port = data/2
    LCD4_DATA = (LCD4_DATA & 0x0F) | (data & 0xF0);
    // en =1 , delay , en =0
    LCD4_enable();
    // port = data/2
    LCD4_DATA = (LCD4_DATA & 0x0F) | (data << 4);
    // en =1 , delay , en =0
    LCD4_enable();

}

void LCD4_cmdS(char cmd) {
    // RS = 0
    LCD4_COM &= ~(1 << LCD4_RS);
    // port = data/2
    LCD4_DATA = (LCD4_DATA & 0x0F) | (cmd & 0xF0);
    // en =1 , delay , en =0
    LCD4_enable();
    
}
void LCD4_cmd(char cmd) {
    // RS = 0
    LCD4_COM &= ~(1 << LCD4_RS);
    // port = data/2
    LCD4_DATA = (LCD4_DATA & 0x0F) | (cmd & 0xF0);
    // en =1 , delay , en =0
    LCD4_enable();
    
    // port = data/2
    LCD4_DATA = (LCD4_DATA & 0x0F) | (cmd << 4);
    // en =1 , delay , en =0
    LCD4_enable();
}

void LCD4_str(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        LCD4_data(str[i]);
    }
}

void LCD4_num(int num) {
    char num_str[11];
    ltoa(num, num_str, 10);


    LCD4_str(num_str);
}

void LCD4_enable() {
    LCD4_COM |= (1 << LCD4_EN);
    _delay_ms(5);
    LCD4_COM &= ~(1 << LCD4_EN);
}