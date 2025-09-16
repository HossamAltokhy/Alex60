/* 
 * File:   TIMER2.h
 * Author: hossa
 *
 * Created on September 16, 2025, 5:20 PM
 */

#ifndef TIMER2_H
#define	TIMER2_H

#define TIMER2_NORMAL  0
#define TIMER2_CTC     1
#define TIMER2_PWM     2
#define TIMER2_FPWM    3



#define state_ENABLE     1
#define state_DISABLE    0




#define TIMER2_DISABLE   0
#define TIMER2_NO_PRE    1
#define TIMER2_PRE_1024  5

#define TIMER2_OCR2      6  //37 // 24  // 6

void init_Timer2(char mode, char clock);
void init_Timer2_Async(char mode);
void Timer2_CLOCK_SELECT(char clock);
void Timer2_SELECT_MODE(char TIMER_MODE);
void Timer2_OVF_INT(char state);
void Timer2_OCF_INT(char state);
void Timer2_CLEAR_INTs();

#endif	/* TIMER2_H */

