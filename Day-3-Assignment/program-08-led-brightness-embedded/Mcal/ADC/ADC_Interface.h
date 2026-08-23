#ifndef MCAL_ADC_INTERFACE_H
#define MCAL_ADC_INTERFACE_H

#include <stdint.h>

void ADC_Init(void);

uint8_t ADC_ReadChannel(
    const uint8_t ChannelNumber);

#endif