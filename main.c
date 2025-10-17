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
#include "SPI.h"
#include "MEM.h"

#include "freertos/include/FreeRTOSConfig.h"
#include "freertos/include/FreeRTOS.h"
#include "freertos/include/task.h"



TaskHandle_t handler1 =  NULL;
TaskHandle_t handler2 =  NULL;


void Task1(void * ptr) { 
    
    
    while (1) {
        UART_send('A');
        vTaskDelay(5);
    }
    
}
void Task2(void * ptr) {  
    
    int counter =0;
    
    while (1) {
        counter ++;
        LCD4_data('A');
        if(counter == 5){
            vTaskDelete(NULL);
        }
       
        
    }
    
}


int main() {

    init_UART(9600);
    init_LCD4();
    
    _delay_ms(50);
    
    
    
    xTaskCreate(Task1, "T1", 100, NULL, 1, &handler1);
    xTaskCreate(Task2, "T2", 100, NULL, 1, &handler2);
    
    
   
    // Start FreeRTOS To RUN....
    vTaskStartScheduler();
    
    
    return 0;
}
