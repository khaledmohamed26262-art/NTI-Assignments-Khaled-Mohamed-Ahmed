#ifndef MCAL_PWM_INTERFACE_H
#define MCAL_PWM_INTERFACE_H

#include <stdint.h>

void PWM_Init(void);

void PWM_SetDutyCycle(
    const uint8_t DutyCycle);

#endif