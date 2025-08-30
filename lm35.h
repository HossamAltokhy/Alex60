/* 
 * File:   lm35.h
 * Author: hossa
 *
 * Created on August 30, 2025, 10:23 AM
 */

#ifndef LM35_H
#define	LM35_H

#define TempSensor0    PA0
#define TempSensor1    PA1
#define TempSensor2    PA2
#define TempSensor3    PA3
#define TempSensor4    PA4
#define TempSensor5    PA5
#define TempSensor6    PA6
#define TempSensor7    PA7

void init_LM35(char tempSensor);
int  LM35_read();
void LM35_sample();
void LM35_select(char tempSensor);

#endif	/* LM35_H */

