/* 
 * File:   ADC.h
 * Author: hossa
 *
 * Created on August 29, 2025, 9:30 AM
 */

#ifndef ADC_H
#define	ADC_H

#define CH0   0
#define CH1   1
#define CH2   2
#define CH3   3
#define CH4   4
#define CH5   5
#define CH6   6
#define CH7   7

#define CH0_CH1  16 //0x10// 00010000

#define Vref_AREF    0    // 0x00 //if no shift is needed.
#define Vref_AVCC    1    // 0x40 //if no shift is needed.
#define Vref_2_56    3    // 0xC0 //if no shift is needed.

#define PRE_128      7

#define ADC_step  4.8828125//4.8875855327468230694037145650049

void init_ADC(char CH, char REF, char FREQ);

void ADC_select_CH(char CH);
void ADC_select_REF(char REF);

void ADC_select_FREQ(char FREQ);
void ADC_EN();

void ADC_SC();

void ADC_wait();

void ADC_INT_EN();

int ADC_read();
#endif	/* ADC_H */

