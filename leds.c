#include "leds.h"
#include "DIO.h"



void init_LEDS(){
    setPINA_DIR(LED_YELLOW, OUT);
}
