#define F_CPU 16000000UL
#include <util/delay.h>

#include "keypad.h"
#include "DIO.h"
#include "leds.h"

void init_keypad() {

    // some pins to be inputs
    // 4,5,6,7
    setPINC_DIR(4, IN);
    setPINC_DIR(5, IN);
    setPINC_DIR(6, IN);
    setPINC_DIR(7, IN);
    // some pins to be outputs
    // 0,1,2
    setPINC_DIR(0, OUT);
    setPINC_DIR(1, OUT);
    setPINC_DIR(2, OUT);

    //delay for DIO
    _delay_ms(20);

    // set default
    setPINC(0, HIGH);
    setPINC(1, HIGH);
    setPINC(2, HIGH);

}

char keypad_read() {
    // set default

    while (1) {
        setPINC(0, HIGH);
        setPINC(1, HIGH);
        setPINC(2, HIGH);
        _delay_ms(20);
        char data = checkPORTC() & 0xF0;
        if (data) {
            switch (data) {
                case 0x10:
                    // 1,2,3
                    setPINC(0, LOW);
                    if (checkPORTC() & 0xF0) {
                        setPINC(1, LOW);
                        if (checkPORTC() & 0xF0) {
                            return '1';
                        } else {
                            return '2';
                        }
                    } else {
                        return '3';
                    }
                    break;
                case 0x20:
                    // 4,5,6
                    setPINC(0, LOW);
                    if (checkPORTC() & 0xF0) {
                        setPINC(1, LOW);
                        if (checkPORTC() & 0xF0) {
                            return '4';
                        } else {
                            return '5';
                        }
                    } else {
                        return '6';
                    }
                    break;
                case 0x40:
                    //7,8,9
                    setPINC(0, LOW);
                    if (checkPORTC() & 0xF0) {
                        setPINC(1, LOW);
                        if (checkPORTC() & 0xF0) {
                            return '7';
                        } else {
                            return '8';
                        }
                    } else {
                        return '9';
                    }

                    break;
                case 0x80:
                    //*,0,#
                    setPINC(0, LOW);
                    if (checkPORTC() & 0xF0) {
                        setPINC(1, LOW);
                        if (checkPORTC() & 0xF0) {
                            return '*';
                        } else {
                            return '0';
                        }
                    } else {
                        return '#';
                    }
                    break;


//                default:
//                    return -1;
            }
        }
    }

}
