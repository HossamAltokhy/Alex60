#include "leds.h"
#include "DIO.h"

void init_LEDS() {
    setPINB_DIR(LED1, OUT);
    setPINC_DIR(LED2, OUT);
    setPINC_DIR(LED3, OUT);
    setPIND_DIR(LED4, OUT);
}

void led_on(char ledNum) {
    switch (ledNum) {
        case LED1:
            setPINB(LED1, HIGH);
            break;
        case LED2:
            setPINC(LED2, HIGH);
            break;
        case LED3:
            setPINC(LED3, HIGH);
            break;
        case LED4:
            setPIND(LED4, HIGH);
            break;

    }

}

void led_off(char ledNum) {
    switch (ledNum) {
        case LED1:
            setPINB(LED1, LOW);
            break;
        case LED2:
            setPINC(LED2, LOW);
            break;
        case LED3:
            setPINC(LED3, LOW);
            break;
        case LED4:
            setPIND(LED4, LOW);
            break;

    }


}

void led_tog(char ledNum) {
    switch (ledNum) {
        case LED1:
            togglePINB(LED1);
            break;
        case LED2:
            togglePINC(LED2);
            break;
        case LED3:
            togglePINC(LED3);
            break;
        case LED4:
            togglePIND(LED4);
            break;

    }
}

void led_on_all() {
    led_on(LED1);
    led_on(LED2);
    led_on(LED3);
    led_on(LED4);
}

void led_off_all() {
    led_off(LED1);
    led_off(LED2);
    led_off(LED3);
    led_off(LED4);
}

void led_tog_all() {
    led_tog(LED1);
    led_tog(LED2);
    led_tog(LED3);
    led_tog(LED4);
}