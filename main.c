/* 
 * File:   main.c
 * Author: hossa
 *
 * Created on August 8, 2025, 8:45 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <avr/io.h>


#define F_CPU 16000000UL
#include <util/delay.h>

#include "DIO.h"
#include "leds.h"
#include "buttons.h"
#include "keypad.h"
#include "kit_keypad.h"
#include "_7seg.h"
#include "mlcd8.h"
#include <string.h>

int main() {
    long int num = 1234567890;
    init_LCD();

    init_keypad();

    //    LCD_num(num);

    int i =0;
    char user_password[4];
    char password[]= "1234";
    char correct_str[] = "Correct Password";
    char wrong_str[] = "Wrong Password";
    while (1) {

        user_password[i++]= keypad_read();
        LCD_data('*');
        
        if(i== 4){
            if(strncmp(password,user_password,4) == 0){
                LCD_cmd(0x01);
                LCD_str(correct_str);
                // code if correct
                
            }
            else{
                LCD_cmd(0x01);
                LCD_str(wrong_str);
                _delay_ms(500);
                LCD_cmd(0x01);
                
                i =0;
            }
        }

        _delay_ms(250);



    }

    return (EXIT_SUCCESS);
}

