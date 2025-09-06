

#include "buttons.h"

#include "DIO.h"


void init_buttons(){
    
    setPIND_DIR(button0, IN);
    setPIND_DIR(button1, IN);
    
}

char isPressed(char pin){
    return checkPIND(pin);
}