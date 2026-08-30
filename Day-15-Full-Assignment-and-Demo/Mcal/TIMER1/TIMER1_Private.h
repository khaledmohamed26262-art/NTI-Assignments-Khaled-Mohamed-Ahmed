#ifndef TIMER1_PRIVATE_H
#define TIMER1_PRIVATE_H

/* TCCR1A Bits */

#define Bit_COM1A1    7
#define Bit_COM1A0    6
#define Bit_COM1B1    5
#define Bit_COM1B0    4
#define Bit_FOC1A     3
#define Bit_FOC1B     2
#define Bit_WGM11     1
#define Bit_WGM10     0

/* TCCR1B Bits */

#define Bit_WGM13     4
#define Bit_WGM12     3
#define Bit_CS12      2
#define Bit_CS11      1
#define Bit_CS10      0

/* TIMSK Bits */

#define Bit_OCIE1A    4
#define Bit_OCIE1B    3
#define Bit_TOIE1     2

/* Masks */

#define TIMER1_CS_MASK       0xF8
#define TIMER1_COM1A_MASK    0x3F
#define TIMER1_COM1B_MASK    0xCF
#define TIMER1_WGM1A_MASK    0xFC
#define TIMER1_WGM1B_MASK    0xE7

typedef enum
{
    TIMER1_NormalMode           = 0x00,
    TIMER1_PhaseCorrectPWM8Bit  = 0x01,
    TIMER1_PhaseCorrectPWM9Bit  = 0x02,
    TIMER1_PhaseCorrectPWM10Bit = 0x03,
    TIMER1_CTCMode              = 0x04,
    TIMER1_FastPWM8Bit          = 0x05,
    TIMER1_FastPWM9Bit          = 0x06,
    TIMER1_FastPWM10Bit         = 0x07

} TIMER1_Mode_t;

typedef enum
{
    TIMER1_NoClock             = 0x00,
    TIMER1_Prescaler1          = 0x01,
    TIMER1_Prescaler8          = 0x02,
    TIMER1_Prescaler64         = 0x03,
    TIMER1_Prescaler256        = 0x04,
    TIMER1_Prescaler1024       = 0x05,
    TIMER1_ExtClockFalling     = 0x06,
    TIMER1_ExtClockRising      = 0x07

} TIMER1_Prescaler_t;

typedef enum
{
    TIMER1_OC_Disconnected = 0x00,
    TIMER1_OC_Toggle       = 0x01,
    TIMER1_OC_NonInverting = 0x02,
    TIMER1_OC_Inverting    = 0x03

} TIMER1_OutputCompareMode_t;

typedef enum
{
    TIMER1_ChannelA = 0,
    TIMER1_ChannelB = 1

} TIMER1_Channel_t;

typedef enum
{
    TIMER1_OverflowInterrupt      = 0,
    TIMER1_CompareMatchAInterrupt = 1,
    TIMER1_CompareMatchBInterrupt = 2

} TIMER1_InterruptSource_t;

#define TIMER1_NUMBER_OF_INTERRUPTS  3

typedef void (*TIMER1_CallBackFunction_t)(void);

#endif
