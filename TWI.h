/* 
 * File:   TWI.h
 * Author: hossa
 *
 * Created on October 7, 2025, 7:35 PM
 */

#ifndef TWI_H
#define	TWI_H


void init_TWI(char Address);
int TWI_MT(char address, char data);
char TWI_MR(char address);
char TWI_SR();
char TWI_ST(char data);

#endif	/* TWI_H */

