#include "PWM_Interface.h"
#include "PWM_Private.h"
#include "PWM_Config.h"

#include "../Atmega32Register.h"
#include "../../Common/BitMath.h"

void PWM_Init(void)
{
    TCCR0_Reg = 0U;

    /*
     * Timer0 Fast PWM mode.
     * Non-inverting output on OC0.
     */
    SetBit(TCCR0_Reg,
           TIMER0_WGM00_BIT);

    SetBit(TCCR0_Reg,
           TIMER0_COM01_BIT);

    SetBit(TCCR0_Reg,
           TIMER0_WGM01_BIT);

    TCCR0_Reg =
        (uint8_t)
        (TCCR0_Reg |
         PWM_TIMER0_PRESCALER_64);

    OCR0_Reg = 0U;
}

void PWM_SetDutyCycle(
    const uint8_t DutyCycle)
{
    OCR0_Reg = DutyCycle;
}