

#include "buttons.h"

#include "DIO.h"


void init_buttons(){
    
    setPINC_DIR(button0, IN);
    setPINC_DIR(button1, IN);
    
}

char isPressed(char pin){
    return checkPINC(pin);
}