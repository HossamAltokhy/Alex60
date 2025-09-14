/* 
 * File:   EXT_INT.h
 * Author: hossa
 *
 * Created on September 7, 2025, 2:32 PM
 */

#ifndef EXT_INT_H
#define	EXT_INT_H

#define  INT_MODE_LOW        0
#define  INT_MODE_ANY        1
#define  INT_MODE_FALLING    2   // 00000010
#define  INT_MODE_RISING     3


void init_INT(char INT, char mode);
#endif	/* EXT_INT_H */

