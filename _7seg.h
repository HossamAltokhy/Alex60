/* 
 * File:   _7seg.h
 * Author: hossa
 *
 * Created on August 16, 2025, 7:40 AM
 */

#ifndef _7SEG_H
#define	_7SEG_H

#define CC   1   // Common Cathod


void init_7Seg();

void _7seg_write(char num);
void _7seg_1_write(char num);
void _7seg_2_write(char num);

void _7seg_1_EN();
void _7seg_1_DIS();
void _7seg_2_EN();
void _7seg_2_DIS();


#endif	/* _7SEG_H */

