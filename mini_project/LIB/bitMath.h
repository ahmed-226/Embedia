#ifndef BITMATH_H
#define BITMATH_H

#define setBit(reg, bit)        reg |= (1 << bit)
#define clearBit(reg, bit)      reg &= ~(1 << bit)
#define toggleBit(reg, bit)     reg ^= (1 << bit)
#define getBit(reg, bit)        (reg&(1<<bit))>>bit

#endif
