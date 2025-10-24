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
#include "freertos/include/queue.h"
#include "freertos/include/semphr.h"



TaskHandle_t handler1 = NULL;
TaskHandle_t handler2 = NULL;

SemaphoreHandle_t SemaphoreHandler = NULL;

void Task1(void * ptr) {

    // initializations

    // Processing once

    char x = 'a';

    
    
    //End
    while (1) {

        vTaskDelay(1);
        if (SemaphoreHandler != NULL) {
            
            if (xSemaphoreTake(SemaphoreHandler, ( TickType_t ) 10) == pdTRUE) {
                UART_send(x);
                x++;
                xSemaphoreGive(SemaphoreHandler);
            }
            else{
                UART_send('*');
            }

        }

        else{
            UART_send('_');
        }

    }


    // Delete its own memory space
    vTaskDelete(NULL);

}

void Task2(void * ptr) {




    int x = 1;
    int result = 0;
    //End
    vTaskDelay(2);
    while (1) {
        vTaskDelay(1);
        if (SemaphoreHandler != NULL) {

            if (xSemaphoreTake(SemaphoreHandler,( TickType_t ) 10) == pdTRUE) {
                UART_num(x);
                x++;
                xSemaphoreGive(SemaphoreHandler);
            }
            else{
                UART_send('?');
            }

        }
        else{
            UART_send('!');
        }

    }

    // Delete its own memory space
    vTaskDelete(NULL);

}

// Status 

// Deleted - Blocked
// Running >>  CPU execute instructions 
// Ready >>> About to be the running task.

//  Resume      Suspend
//  Running  vs Suspended(Ready - Deleted - Blocked)

int main() {


    init_UART(9600);

    SemaphoreHandler = xSemaphoreCreateBinary();
    xSemaphoreGive(SemaphoreHandler);
    

    xTaskCreate(Task1, "T1", 100, NULL, 3, &handler1);
    xTaskCreate(Task2, "T2", 100, NULL, 3, &handler2);



    // Start FreeRTOS To RUN....
    vTaskStartScheduler();




    while (1) {
        // No use...

        UART_send('!');
    }


    return 0;
}
