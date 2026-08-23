#include <stdint.h>
#include "ADC_Interface.h"
#include "../Atmega32Register.h"

void ADC_Init(void)
{
    ADMUX_Reg = 0x60U;  
    ADCSRA_Reg = 0x86U;  
}

uint8_t ADC_ReadChannel(uint8_t channel)
{
    ADMUX_Reg = (uint8_t)((ADMUX_Reg & 0xE0U) |
                          (channel & 0x07U));

    ADCSRA_Reg |= 0x40U; /* Start new conversion */

    while ((ADCSRA_Reg & 0x40U) != 0U)
    {
        /* Wait */
    }

    return ADCH_Reg;
}