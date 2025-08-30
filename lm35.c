#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>

#include "ADC.h"
#include "lm35.h"


void init_LM35(char tempSensor){
    
    init_ADC(tempSensor, Vref_AVCC, PRE_128);
    
}

void LM35_sample(){
    ADC_SC();
}


void LM35_select(char tempSensor){
    ADC_select_CH(tempSensor);
}
int LM35_read(){
    
    return ADC_read()/10.0;
    
}
