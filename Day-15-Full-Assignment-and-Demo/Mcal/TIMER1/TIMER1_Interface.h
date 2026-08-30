#ifndef TIMER1_INTERFACE_H
#define TIMER1_INTERFACE_H

#include <stdint.h>

#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Register.h"

#include "TIMER1_Private.h"
#include "TIMER1_Config.h"

void TIMER1_Init(
    uint8_t Copy_u8Mode,
    uint8_t Copy_u8Prescaler
);

void TIMER1_DeInit(void);

void TIMER1_Start(void);

void TIMER1_Stop(void);

void TIMER1_SetTimerValue(
    uint16_t Copy_u16TimerValue
);

void TIMER1_GetTimerValue(
    uint16_t *Copy_pu16TimerValue
);

void TIMER1_SetCompareValue(
    uint8_t Copy_u8Channel,
    uint16_t Copy_u16CompareValue
);

void TIMER1_GetCompareValue(
    uint8_t Copy_u8Channel,
    uint16_t *Copy_pu16CompareValue
);

void TIMER1_SetCompareOutputMode(
    uint8_t Copy_u8Channel,
    uint8_t Copy_u8CompareMode
);

void TIMER1_EnableInterrupt(
    uint8_t Copy_u8InterruptSource
);

void TIMER1_DisableInterrupt(
    uint8_t Copy_u8InterruptSource
);

void TIMER1_SetCallBack(
    void (*Copy_pfLocalFunction)(void),
    uint8_t Copy_u8InterruptSource
);

void __vector_7(void) __attribute__((signal));
void __vector_8(void) __attribute__((signal));
void __vector_9(void) __attribute__((signal));

#endif
