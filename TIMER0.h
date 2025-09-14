/* 
 * File:   TIMER0.h
 * Author: hossa
 *
 * Created on September 5, 2025, 10:24 AM
 */

#ifndef TIMER0_H
#define	TIMER0_H

#define TIMER0_NORMAL  0
#define TIMER0_CTC     1
#define TIMER0_PWM     2
#define TIMER0_FPWM    3



#define state_ENABLE     1
#define state_DISABLE    0




#define TIMER0_DISABLE   0
#define TIMER0_NO_PRE    1
#define TIMER0_PRE_1024  5

#define TIMER0_OCR0      6  //37 // 24  // 6

void init_Timer0(char mode, char clock);

void Timer0_CLOCK_SELECT(char clock);
void Timer0_SELECT_MODE(char TIMER_MODE);
void Timer0_OVF_INT(char state);
void Timer0_OCF_INT(char state);

#endif	/* TIMER0_H */

