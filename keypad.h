/* 
 * File:   keypad.h
 * Author: hossa
 *
 * Created on August 9, 2025, 10:50 AM
 */

#ifndef KEYPAD_H
#define	KEYPAD_H

#define keypad_dir  DDRA
#define keypad_port PORTA
#define keypad_pin  PINA

void init_keypad();

char keypad_read();

#endif	/* KEYPAD_H */

