
#include <avr/io.h>
#include "ADC.h"

#define F_CPU 16000000UL
#include <util/delay.h>



void ADC_select_CH(char CH){
    // ADMUX   ......  MUX4:0
    
    //11100000
    ADMUX &= 0xE0;
    ADMUX |= CH;
}
void ADC_select_REF(char REF){
    // ADMUX   ......  REFS1:0
    //00111111
    ADMUX &= 0x3F;
    ADMUX |= (REF<<6);
}

void ADC_select_FREQ(char FREQ){
    // 11111000
    ADCSRA &= 0xF8;
    ADCSRA |= FREQ; 
}

void ADC_EN(){
    ADCSRA |= (1<<ADEN);
}

void ADC_SC(){
    ADCSRA |= (1<<ADSC);
}

void ADC_wait(){
//    while(1){
//        if(ADCSRA & (1<<ADIF)){
//            break;
//        }
//    }
    
    // wait till flag is true (ADIF).....
    while(!(ADCSRA & (1<< ADIF)));
    
    
}

int ADC_read(){
    
    //        ADCH                ADCL   
    // |-|-|-|-|-|-|x|x|    |x|x|x|x|x|x|x|x|
    // |x|x|x|x|x|x|x|x|    |x|x|-|-|-|-|-|-|  
    
    return ADCW*ADC_step; //  NOTE 
}

void init_ADC(char CH, char REF, char FREQ){
    // select CH
    ADC_select_CH(CH);
    // select FREQ
    ADC_select_FREQ(FREQ);
    // select REF
    ADC_select_REF(REF);
   
    // Enable
    ADC_EN();
}