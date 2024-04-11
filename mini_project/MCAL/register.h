#ifndef REGISTER_H
#define REGISTER_H

#include "stdTypes.h" 

#define NUMBER_OF_PORTS 4

#define PORTA_REG   ((volatile uint8_t*)0x3B)
#define DDRA_REG    ((volatile uint8_t*)0x3A)
#define PINA_REG    ((volatile uint8_t*)0x39)

#define PORTB_REG   ((volatile uint8_t*)0x38)
#define DDRB_REG    ((volatile uint8_t*)0x37)
#define PINB_REG    ((volatile uint8_t*)0x36)

#define PORTC_REG   ((volatile uint8_t*)0x35)
#define DDRC_REG    ((volatile uint8_t*)0x34)
#define PINC_REG    ((volatile uint8_t*)0x33)

#define PORTD_REG   ((volatile uint8_t*)0x32)
#define DDRD_REG    ((volatile uint8_t*)0x31)
#define PIND_REG    ((volatile uint8_t*)0x30)

static uint8_t * const PORT[NUMBER_OF_PORTS]={PORTA_REG,PORTB_REG,PORTC_REG,PORTD_REG};
static uint8_t * const PIN[NUMBER_OF_PORTS]={PINA_REG,PINB_REG,PINC_REG,PIND_REG};
static uint8_t * const DDR[NUMBER_OF_PORTS]={DDRA_REG,DDRB_REG,DDRC_REG,DDRD_REG};


#endif 
