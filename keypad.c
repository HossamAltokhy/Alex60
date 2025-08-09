#define F_CPU 16000000UL
#include <util/delay.h>

#include "keypad.h"
#include "DIO.h"
#include "leds.h"

void init_keypad(){
    
    // some pins to be inputs
    // 4,5,6,7
    setPINA_DIR(4,IN);
    setPINA_DIR(5,IN);
    setPINA_DIR(6,IN);
    setPINA_DIR(7,IN);
    // some pins to be outputs
    // 0,1,2
    setPINA_DIR(0, OUT);
    setPINA_DIR(1, OUT);
    setPINA_DIR(2, OUT);
    
    //delay for DIO
    _delay_ms(20);
    
    // set default
    setPINA(0, HIGH);
    setPINA(1, HIGH);
    setPINA(2, HIGH);
    
}

char keypad_read(){
    // set default
    setPINA(0, HIGH);
    setPINA(1, HIGH);
    setPINA(2, HIGH);
    _delay_ms(20);
    char data = checkPORTA() & 0xF0;
    if(data){
        switch(data){
            case 0x10:
                // 1,2,3
                setPINA(0,LOW);
                if(checkPORTA() & 0xF0){
                    setPINA(1,LOW);
                    if(checkPORTA() & 0xF0){
                        return 1;
                    }
                    else{
                        return 2;
                    }
                }
                else{
                    return 3;
                }
                break;
            case 0x20:
                // 4,5,6
                setPINA(0,LOW);
                if(checkPORTA() & 0xF0){
                    setPINA(1,LOW);
                    if(checkPORTA() & 0xF0){
                        return 4;
                    }
                    else{
                        return 5;
                    }
                }
                else{
                    return 6;
                }
                break;
            case 0x40:
                //7,8,9
                setPINA(0,LOW);
                if(checkPORTA() & 0xF0){
                    setPINA(1,LOW);
                    if(checkPORTA() & 0xF0){
                        return 7;
                    }
                    else{
                        return 8;
                    }
                }
                else{
                    return 9;
                }
                
                break;
            case 0x80:
                //*,0,#
                setPINA(0,LOW);
                if(checkPORTA() & 0xF0){
                    setPINA(1,LOW);
                    if(checkPORTA() & 0xF0){
                        return 0;
                    }
                    else{
                        return 0;
                    }
                }
                else{
                    return 0;
                }
                break;
        }
    }
    
}
