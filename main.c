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



TaskHandle_t handler1 = NULL;
TaskHandle_t handler2 = NULL;

xQueueHandle xQueue1 = NULL; // T1 >> T2
xQueueHandle xQueue2 = NULL; // T1 << T2

void Task1(void * ptr) {

    // initializations

    // Processing once

    int x = 100;
    int result = 0;
    //End
    while (1) {

        if (xQueueSendToBack(xQueue1, &x, 0) == pdPASS) {
            x++;
        }
        if (xQueueReceive(xQueue2, &result, 1) == pdPASS) {
            UART_num(result);
            UART_send('\r');

        }
        taskYIELD();

    }


    // Delete its own memory space
    vTaskDelete(NULL);

}

void Task2(void * ptr) {




    int x = 200;
    int result = 0;
    //End
    vTaskDelay(2);
    while (1) {

        if (xQueueSendToBack(xQueue2, &x, 0) == pdPASS) {
            x++;
        }


        if (xQueueReceive(xQueue1, &result, 1) == pdPASS) {
            UART_num(result);
            UART_send('\r');

        }

        taskYIELD();
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
    xQueue1 = xQueueCreate(2, sizeof (int));
    xQueue2 = xQueueCreate(2, sizeof (int));


    if (xQueue1 && xQueue2) {


        xTaskCreate(Task1, "T1", 100, NULL, 3, &handler1);
        xTaskCreate(Task2, "T2", 100, NULL, 3, &handler2);



        // Start FreeRTOS To RUN....
        vTaskStartScheduler();
    }



    while (1) {
        // No use...

        UART_send('!');
    }


    return 0;
}
