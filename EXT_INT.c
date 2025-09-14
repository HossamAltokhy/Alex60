#include <avr/io.h>
#include <avr/interrupt.h>
#include "EXT_INT.h"





void init_INT(char INT, char mode) {

    switch (INT) {
        case INT0:
            MCUCR &= ~((1 << ISC01) | (1 << ISC00));
            MCUCR |= mode;

            break;
        case INT1:
            MCUCR &= ~((1 << ISC01) | (1 << ISC00));
            MCUCR |= mode << 2;

            break;
        case INT2:
            if (mode == INT_MODE_RISING) {
                MCUCSR |= (1 << ISC2);
            } else {
                MCUCSR &= ~(1 << ISC2);
            }

            break;
    }


    GICR |= (1 << INT);

}
