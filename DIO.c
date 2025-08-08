#include "DIO.h"
#include <avr/io.h>



void setPINA_DIR(char pinNUM, char pinDirection) {

    switch (pinDirection) {
        case OUT:
            // set as output pin.
            DDRA |= (1 << pinNUM);
            break;
        case IN:
            // set as input pin.
            DDRA &= ~(1 << pinNUM);
            break;

    }



}

