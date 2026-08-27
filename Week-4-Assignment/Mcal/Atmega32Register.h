/**
 * @file Atmega32Register.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2026-08-20
 * 
 * @copyright Copyright (c) 2026
 * 
 */
#ifndef _MCAL_ATMEGA32REGISTER_H
#define _MCAL_ATMEGA32REGISTER_H
#include <stdint.h>
/*IO- Memory Map Address*/

#define SREG_Reg *((volatile uint8_t*)0x5F)
/*Stack Pointer */
#define SPH_Reg *((volatile uint8_t*)0x5E)
#define SPL_Reg *((volatile uint8_t*)0x5D)
#define SP_Reg  *((volatile uint16_t*)0x5D)

/*EXTI Phrepheral*/
#define MCUCR_Reg    *((volatile uint8_t*)0x55)
#define MCUCSR_Reg   *((volatile uint8_t*)0x54)
#define GICR_Reg     *((volatile uint8_t*)0x5B)
#define GIFR_Reg     *((volatile uint8_t*)0x5A)




/*DIO-GroupA*/
#define DDRA_Reg  *((volatile uint8_t*)0x3A)
#define PORTA_Reg *((volatile uint8_t*)0x3B)
#define PINA_Reg  *((volatile uint8_t*)0x39)


/*DIO-GroupB*/
#define DDRB_Reg  *((volatile uint8_t*)0x37)
#define PORTB_Reg *((volatile uint8_t*)0x38)
#define PINB_Reg  *((volatile uint8_t*)0x36)

/*DIO-GroupC*/
#define DDRC_Reg  *((volatile uint8_t*)0x34)
#define PORTC_Reg *((volatile uint8_t*)0x35)
#define PINC_Reg  *((volatile uint8_t*)0x33)

/*DIO-GroupD*/
#define DDRD_Reg  *((volatile uint8_t*)0x31)
#define PORTD_Reg *((volatile uint8_t*)0x32)
#define PIND_Reg  *((volatile uint8_t*)0x30)

/*ADC*/
#define ADMUX_Reg   *((volatile uint8_t*)0x27)
#define ADCSRA_Reg  *((volatile uint8_t*)0x26)
#define ADCL_Reg    *((volatile uint8_t*)0x24)
#define ADCH_Reg    *((volatile uint8_t*)0x25)
#define ADCData_Reg *((volatile uint16_t*)0x24)
#define SFIOR_Reg   *((volatile uint8_t*)0x50)

#endif /*_MCAL_ATMEGA32REGISTER_H*/