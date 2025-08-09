

#include "buttons.h"

#include "DIO.h"


void init_buttons(){
    
    setPINA_DIR(button, IN);
    
}

char isPressed(){
    return checkPINA(button);
}