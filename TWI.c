#include <avr/io.h>
#include "TWI.h"



void init_TWI(char address) {
    TWBR = 18;
    TWSR &= ~((1 << TWPS1) | (1 << TWPS0));
    TWAR = address << 1; //  No Global Call is enabled.
}

int TWI_MT(char address, char data) {
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    // Check Status 
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x08) {
        return -1;
    }
    // Load SLA+W
    TWDR = address; //(address<<1)+1; SLA+W (8-bits)
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Check Status
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x18) { // 18
        return -1;
    }
    // Load Data 
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    // Check Status
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x28) { // 28
        return -1;
    }
    // Stop Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);

    return 0;
}

char TWI_MR(char address){
    // Start Condition
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWSTA);
    // Check Status 
    while (!(TWCR & (1 << TWINT)));
    if ((TWSR & 0xF8) != 0x08) {
        return -1;
    }
    // Load SLA+R
    TWDR = address; //(address<<1)+1; SLA+R (8-bits)
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


char TWI_SR() {
    // Enable ACK
    char status = 0;
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status == 0x60) { // 28
        TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
        while (!(TWCR & (1 << TWINT)));
        status = (TWSR & 0xF8);
        if (status == 0x80) {
            char data = TWDR;
            while (!(TWCR & (1 << TWINT)));
            status = (TWSR & 0xF8);
            if (status == 0xA0) {
                return data;
            }
            return status;
        }
        return status;
    }

    return status;
}

char TWI_ST(char data) {
    // Enable ACK
    char status = 0;
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    status = (TWSR & 0xF8);
    if (status == 0xA8) {
        TWDR = data;
        TWCR = (1 << TWINT) | (1 << TWEN);
        while (!(TWCR & (1 << TWINT)));
        status = (TWSR & 0xF8);
        if (status == 0xB8){
            // Data Transmitted to Master and Ack also.
            return 0;
        }
    }
    
    return -1;
}
