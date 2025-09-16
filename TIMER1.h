/* 
 * File:   TIMER1.h
 * Author: hossa
 *
 * Created on September 16, 2025, 6:34 PM
 */

#ifndef TIMER1_H
#define	TIMER1_H


#define TIMER1_NORMAL  0
#define TIMER1_CTC     1
#define TIMER1_PWM     2
#define TIMER1_FPWM    3



#define state_ENABLE     1
#define state_DISABLE    0




#define TIMER1_DISABLE   0
#define TIMER1_NO_PRE    1
#define TIMER1_PRE_1024  5


void init_TIMER1(char mode, char CLOCK_SELECT);

void TIMER1_MODE(char mode);
void TIMER1_clock_SELECT(char CLOCK_SELECT);

void Timer1_OVF_INT(char state);
void Timer1_OCF_INT(char state);
void Timer1_ICPF_INT(char state);
#endif	/* TIMER1_H */

