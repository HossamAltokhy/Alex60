#include "kit_keypad.h"
#include "DIO.h"
#include <avr/io.h>

#define F_CPU 16000000UL 
#include <util/delay.h>

void init_kit_keypad() {

    // Direction of pins
    // PA1,PA2,PA3 as outputs
    setPINA_DIR(PA1, OUT);
    setPINA_DIR(PA2, OUT);
    setPINA_DIR(PA3, OUT);
    // PD2,PD3,PD7 as inputs
    setPIND_DIR(PD2, IN);
    setPIND_DIR(PD3, IN);
    setPIND_DIR(PD7, IN);

    _delay_ms(5);

    // Initialize  value of output pins 
    setPINA(PA1, LOW);
    setPINA(PA2, LOW);
    setPINA(PA3, LOW);
    
    _delay_ms(50);

}

char kit_keypad_getNum() {

    setPINA(PA1, LOW);
    setPINA(PA2, LOW);
    setPINA(PA3, LOW);

    _delay_ms(50);// 0b10001100 == 0x8C
    char check = checkPORTD()& (0x8C);

    switch (check) {
        case 0x88:
            setPINA(PA1, HIGH);
            _delay_ms(50);
            check = checkPORTD()& (0x8C);
            if (check == 0x88) {
                setPINA(PA2, HIGH);
                _delay_ms(50);
                check = checkPORTD()& (0x8C);
                if (check == 0x88) {
                    return 7;
                } else {
                    return 4;
                }
            } else {
                return 1;
            }
            break;
        case 0x84:
            setPINA(PA1, HIGH);
            _delay_ms(50);
            check = checkPORTD()& (0x8C);
            if (check == 0x84) {
                setPINA(PA2, HIGH);
                _delay_ms(50);
                check = checkPORTD()& (0x8C);
                if (check == 0x84) {
                    return 8;
                } else {
                    return 5;
                }
            } else {
                return 2;
            }
            break;

        case 0x0C:
            setPINA(PA1, HIGH);
            _delay_ms(50);
            check = checkPORTD()& (0x8C);
            if (check == 0x0C) {
                setPINA(PA2, HIGH);
                _delay_ms(50);
                check = checkPORTD()& (0x8C);
                if (check == 0x0C) {
                    return 9;
                } else {
                    return 6;
                }
            } else {
                return 3;
            }
            break;
    }

    
    setPINA(PA1, LOW);
    setPINA(PA2, LOW);
    setPINA(PA3, LOW);
 
    _delay_ms(50);
    return 0;

}

//void init_kit_keypad() {
//
//    // Direction of pins
//    // PA1,PA2,PA3 as inputs
//    setPINA_DIR(PA1, IN);
//    setPINA_DIR(PA2, IN);
//    setPINA_DIR(PA3, IN);
//    // PD2,PD3,PD7 as outputs
//    setPIND_DIR(PD2, OUT);
//    setPIND_DIR(PD3, OUT);
//    setPIND_DIR(PD7, OUT);
//
//    _delay_ms(50);
//
//    // Initialize  value of output pins 
//    setPIND(PD2, HIGH);
//    setPIND(PD3, HIGH);
//    setPIND(PD7, HIGH);
//    _delay_ms(50);
//
//}
//
//char kit_keypad_getNum() {
//
//    setPIND(PD2, HIGH);
//    setPIND(PD3, HIGH);
//    setPIND(PD7, HIGH);
//
//    _delay_ms(50);
//    char check = checkPORTA()& (0x0E);
//
//    switch (check) {
//        case 0x02:
//            setPIND(PD2, LOW);
//            _delay_ms(50);
//            check = checkPORTA()& (0x0E);
//            if (check == 0x02) {
//                setPIND(PD3, LOW);
//                _delay_ms(50);
//                check = checkPORTA()& (0x0E);
//                if (check == 0x02) {
//                    return 3;
//                } else {
//                    return 2;
//                }
//            } else {
//                return 1;
//            }
//            break;
//        case 0x04:
//            setPIND(PD2, LOW);
//            _delay_ms(50);
//            check = checkPORTA()& (0x0E);
//            if (check == 0x04) {
//                setPIND(PD3, LOW);
//                _delay_ms(50);
//                check = checkPORTA()& (0x0E);
//                if (check == 0x04) {
//                    return 6;
//                } else {
//                    return 5;
//                }
//            } else {
//                return 4;
//            }
//            break;
//
//        case 0x08:
//            setPIND(PD2, LOW);
//            _delay_ms(50);
//            check = checkPORTA()& (0x0E);
//            if (check == 0x08) {
//                setPIND(PD3, LOW);
//                _delay_ms(50);
//                check = checkPORTA()& (0x0E);
//                if (check == 0x08) {
//                    return 9;
//                } else {
//                    return 8;
//                }
//            } else {
//                return 7;
//            }
//            break;
//    }
//    
//    setPIND(PD2, HIGH);
//    setPIND(PD3, HIGH);
//    setPIND(PD7, HIGH);
//
//    _delay_ms(50);
//
//    return 0;
//
//}
