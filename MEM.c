#include <avr/io.h>
#include "MEM.h"
#include "TWI.h"

char MEM_24C16_WRITE(short MEM_LOC, char data) {
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT)));
    char status = (TWSR & 0xF8);
    if (status != 0x08) {
        return -1;
    }
    // Start Condition Sent..

    // send MEM Address + Write bit
    TWDR = MEM_24C16_W;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x18) {
        return -1;
    }
//    // Send High Byte of Word Address
//    TWDR = (char) (MEM_LOC >> 8);
//    TWCR = (1 << TWINT) | (1 << TWEN);
    // Send Low Byte of Word Address
    while (!(TWCR & (1 << TWINT)));
    TWDR = (char) (MEM_LOC);
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Check Status
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x28) {
        return -1;
    }
    // Send Data
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Check Status
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x28) {
        return -1;
    }
    // Stop Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    
    return 0;

}

char MEM_26C16_READ(short MEM_LOC) {
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT)));
    char status = (TWSR & 0xF8);
    if (status != 0x08) {
        return -1;
    }
    // Start Condition Sent..

    // send MEM Address + Write bit
    TWDR = MEM_24C16_W;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x18) {
        return -1;
    }
//    // Send High Byte of Word Address
//    TWDR = (char) (MEM_LOC >> 8);
//    TWCR = (1 << TWINT) | (1 << TWEN);
    // Send Low Byte of Word Address
    while (!(TWCR & (1 << TWINT)));
    TWDR = (char) (MEM_LOC);
    TWCR = (1 << TWINT) | (1 << TWEN);

    // Check Status
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x28) {
        return -1;
    }
    
    // Repeated start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status != 0x10) {
        return -1;
    }
    // Repeated start Condition Sent..
    
    // Load SLA+R
    TWDR = MEM_24C16_R; //(address<<1)+1; SLA+R (8-bits)
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Check Status
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x40) {
        return -1;
    }
    // Enable ACK
    TWCR = (1 << TWINT) | (1 << TWEN)|(1 << TWEA);
    // Check Status
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x50) {
        return -1;
    }
    // Read Data 
    char data = TWDR;
    // Stop Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
    
    return data;
}

void MEM_24C16_CURRENT_WRITE(char data) {
    TWI_MT(MEM_24C16_W, data);
}

char MEM_26C16_CURRENT_READ() {

    char data = TWI_MR(MEM_24C16_R);

    return data;
}

