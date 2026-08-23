#ifndef MCAL_ATMEGA32REGISTER_H
#define MCAL_ATMEGA32REGISTER_H

#include <stdint.h>

#define Register8(Address) \
    (*(volatile uint8_t *)(uintptr_t)(Address))

#define PINA_Reg  Register8(0x39U)
#define DDRA_Reg  Register8(0x3AU)
#define PORTA_Reg Register8(0x3BU)

#define PINB_Reg  Register8(0x36U)
#define DDRB_Reg  Register8(0x37U)
#define PORTB_Reg Register8(0x38U)

#define PINC_Reg  Register8(0x33U)
#define DDRC_Reg  Register8(0x34U)
#define PORTC_Reg Register8(0x35U)

#define PIND_Reg  Register8(0x30U)
#define DDRD_Reg  Register8(0x31U)
#define PORTD_Reg Register8(0x32U)

/* ADC Registers */
#define ADCL_Reg   Register8(0x24U)
#define ADCH_Reg   Register8(0x25U)
#define ADCSRA_Reg Register8(0x26U)
#define ADMUX_Reg  Register8(0x27U)

/* Timer0 PWM Registers */
#define TCCR0_Reg Register8(0x53U)
#define OCR0_Reg  Register8(0x5CU)

#endif