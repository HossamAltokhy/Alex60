/* 
 * File:   MEM.h
 * Author: hossa
 *
 * Created on October 17, 2025, 9:44 AM
 */

#ifndef MEM_H
#define	MEM_H

#define MEM_24C16_W     0xA0//1010XXX0
#define MEM_24C16_R     0xA1//1010XXX1
#define DEV_ADDRESS     0x07
void MEM_24C16_CURRENT_WRITE(char data);
char MEM_26C16_CURRENT_READ();

char MEM_24C16_WRITE(short MEM_LOC, char data);
char MEM_26C16_READ(short MEM_LOC);

#endif	/* MEM_H */

