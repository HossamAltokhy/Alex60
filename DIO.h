/* 
 * File:   DIO.h
 * Author: hossa
 *
 * Created on August 8, 2025, 10:46 AM
 */

#ifndef DIO_H
#define	DIO_H

#define OUT 1
#define IN  0

#define HIGH 1
#define LOW  0

// Data Driection
void setPINA_DIR(char pinNUM, char pinDirection);
void setPORTA_DIR(char portDirection);

// Output Data
void setPINA(char pinNUM, char state);
void setPORTA(char state);

// Toggle Output Data.
void togglePINA(char pinNUM);
void togglePORTA();

// Check Input
char checkPINA(char pinNUM);
char checkPORTA();


// Data Driection
void setPINB_DIR(char pinNUM, char pinDirection);
void setPORTB_DIR(char portDirection);

// Output Data
void setPINB(char pinNUM, char state);
void setPORTB(char state);

// Toggle Output Data.
void togglePINB(char pinNUM);
void togglePORTB();

// Check Input
char checkPINB(char pinNUM);
char checkPORTB();



// Data Driection
void setPINC_DIR(char pinNUM, char pinDirection);
void setPORTC_DIR(char portDirection);

// Output Data
void setPINC(char pinNUM, char state);
void setPORTC(char state);

// Toggle Output Data.
void togglePINC(char pinNUM);
void togglePORTC();

// Check Input
char checkPINC(char pinNUM);
char checkPORTC();



// Data Driection
void setPIND_DIR(char pinNUM, char pinDirection);
void setPORTD_DIR(char portDirection);

// Output Data
void setPIND(char pinNUM, char state);
void setPORTD(char state);

// Toggle Output Data.
void togglePIND(char pinNUM);
void togglePORTD();

// Check Input
char checkPIND(char pinNUM);
char checkPORTD();

#endif	/* DIO_H */

