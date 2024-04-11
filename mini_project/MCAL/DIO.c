#include "DIO.h"
#include "register.h" 
#include "bitMath.h" 

void pinMode(uint8_t port, uint8_t pin, uint8_t state) {

    switch (state)
    {
        case IN :clearBit(*DDR[port] , pin); break;
        case OUT :setBit(*DDR[port] , pin);  break;
    }
}

void digitalWrite(uint8_t port, uint8_t pin,uint8_t state) {
    
    switch (state)
    {
        case HIGH : setBit(*PORT[port], pin); break;
        case LOW : clearBit(*PORT[port], pin); break;
    }

}

void digitalToggle(int8_t port, uint8_t pin) {
    
    toggleBit(*PORT[port], pin);
}

uint8_t digitalRead(uint8_t port, uint8_t pin) {
    return getBit(*PIN[port], pin);
}


