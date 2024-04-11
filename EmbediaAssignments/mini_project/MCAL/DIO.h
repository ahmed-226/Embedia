#ifndef DIO_H
#define DIO_H

#include "stdTypes.h" 

enum {A,B,C,D};
enum {pin0,pin1,pin2,pin3,pin4,pin5,pin6,pin7};

#define IN 0
#define OUT 1


void pinMode(uint8_t port, uint8_t pin, uint8_t state);
void digitalWrite(uint8_t port, uint8_t pin, uint8_t state);
uint8_t digitalRead(uint8_t port, uint8_t pin);
void digitalToggle(uint8_t port, uint8_t pin);

#endif 
