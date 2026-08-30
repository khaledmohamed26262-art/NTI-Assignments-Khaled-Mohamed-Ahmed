#include "TIMER1_Interface.h"

static TIMER1_CallBackFunction_t
TIMER1_CallBackFunctions[TIMER1_NUMBER_OF_INTERRUPTS] =
{
    NULL,
    NULL,
    NULL
};

static uint8_t TIMER1_CurrentPrescaler =
    TIMER1_NoClock;

void TIMER1_Init(
    uint8_t Copy_u8Mode,
    uint8_t Copy_u8Prescaler
)
{
    TCCR1B_Reg &= TIMER1_CS_MASK;

    TCCR1A_Reg &= TIMER1_WGM1A_MASK;
    TCCR1B_Reg &= TIMER1_WGM1B_MASK;

    TCCR1A_Reg |=
        (Copy_u8Mode & 0x03U);

    TCCR1B_Reg |=
        (((Copy_u8Mode >> 2U) & 0x03U) << Bit_WGM12);

    TCNT1_Reg = TIMER1_INITIAL_TCNT1_VALUE;
    OCR1A_Reg = TIMER1_INITIAL_OCR1A_VALUE;
    OCR1B_Reg = TIMER1_INITIAL_OCR1B_VALUE;

    if(Copy_u8Prescaler <= TIMER1_ExtClockRising)
    {
        TIMER1_CurrentPrescaler = Copy_u8Prescaler;

        TCCR1B_Reg &= TIMER1_CS_MASK;
        TCCR1B_Reg |= Copy_u8Prescaler;
    }
    else
    {
        /* Invalid Prescaler */
    }
}

void TIMER1_DeInit(void)
{
    TCCR1A_Reg = 0x00;
    TCCR1B_Reg = 0x00;

    TCNT1_Reg = 0x0000;
    OCR1A_Reg = 0x0000;
    OCR1B_Reg = 0x0000;

    ClearBit(TIMSK_Reg, Bit_TOIE1);
    ClearBit(TIMSK_Reg, Bit_OCIE1A);
    ClearBit(TIMSK_Reg, Bit_OCIE1B);

    TIMER1_CurrentPrescaler = TIMER1_NoClock;
}

void TIMER1_Start(void)
{
    TCCR1B_Reg &= TIMER1_CS_MASK;
    TCCR1B_Reg |= TIMER1_CurrentPrescaler;
}

void TIMER1_Stop(void)
{
    TCCR1B_Reg &= TIMER1_CS_MASK;
}

void TIMER1_SetTimerValue(
    uint16_t Copy_u16TimerValue
)
{
    TCNT1_Reg = Copy_u16TimerValue;
}

void TIMER1_GetTimerValue(
    uint16_t *Copy_pu16TimerValue
)
{
    if(Copy_pu16TimerValue != NULL)
    {
        *Copy_pu16TimerValue = TCNT1_Reg;
    }
    else
    {
        /* Null Pointer */
    }
}

void TIMER1_SetCompareValue(
    uint8_t Copy_u8Channel,
    uint16_t Copy_u16CompareValue
)
{
    if(Copy_u8Channel == TIMER1_ChannelA)
    {
        OCR1A_Reg = Copy_u16CompareValue;
    }
    else if(Copy_u8Channel == TIMER1_ChannelB)
    {
        OCR1B_Reg = Copy_u16CompareValue;
    }
    else
    {
        /* Invalid Channel */
    }
}

void TIMER1_GetCompareValue(
    uint8_t Copy_u8Channel,
    uint16_t *Copy_pu16CompareValue
)
{
    if(Copy_pu16CompareValue != NULL)
    {
        if(Copy_u8Channel == TIMER1_ChannelA)
        {
            *Copy_pu16CompareValue = OCR1A_Reg;
        }
        else if(Copy_u8Channel == TIMER1_ChannelB)
        {
            *Copy_pu16CompareValue = OCR1B_Reg;
        }
        else
        {
            /* Invalid Channel */
        }
    }
    else
    {
        /* Null Pointer */
    }
}

void TIMER1_SetCompareOutputMode(
    uint8_t Copy_u8Channel,
    uint8_t Copy_u8CompareMode
)
{
    if(Copy_u8CompareMode <= TIMER1_OC_Inverting)
    {
        if(Copy_u8Channel == TIMER1_ChannelA)
        {
            TCCR1A_Reg &= TIMER1_COM1A_MASK;
            TCCR1A_Reg |=
                (Copy_u8CompareMode << Bit_COM1A0);
        }
        else if(Copy_u8Channel == TIMER1_ChannelB)
        {
            TCCR1A_Reg &= TIMER1_COM1B_MASK;
            TCCR1A_Reg |=
                (Copy_u8CompareMode << Bit_COM1B0);
        }
        else
        {
            /* Invalid Channel */
        }
    }
    else
    {
        /* Invalid Compare Mode */
    }
}

void TIMER1_EnableInterrupt(
    uint8_t Copy_u8InterruptSource
)
{
    switch(Copy_u8InterruptSource)
    {
        case TIMER1_OverflowInterrupt:
            SetBit(TIMSK_Reg, Bit_TOIE1);
            break;

        case TIMER1_CompareMatchAInterrupt:
            SetBit(TIMSK_Reg, Bit_OCIE1A);
            break;

        case TIMER1_CompareMatchBInterrupt:
            SetBit(TIMSK_Reg, Bit_OCIE1B);
            break;

        default:
            /* Invalid Interrupt */
            break;
    }
}

void TIMER1_DisableInterrupt(
    uint8_t Copy_u8InterruptSource
)
{
    switch(Copy_u8InterruptSource)
    {
        case TIMER1_OverflowInterrupt:
            ClearBit(TIMSK_Reg, Bit_TOIE1);
            break;

        case TIMER1_CompareMatchAInterrupt:
            ClearBit(TIMSK_Reg, Bit_OCIE1A);
            break;

        case TIMER1_CompareMatchBInterrupt:
            ClearBit(TIMSK_Reg, Bit_OCIE1B);
            break;

        default:
            /* Invalid Interrupt */
            break;
    }
}

void TIMER1_SetCallBack(
    void (*Copy_pfLocalFunction)(void),
    uint8_t Copy_u8InterruptSource
)
{
    if(
        (Copy_pfLocalFunction != NULL) &&
        (Copy_u8InterruptSource < TIMER1_NUMBER_OF_INTERRUPTS)
    )
    {
        TIMER1_CallBackFunctions[
            Copy_u8InterruptSource
        ] = Copy_pfLocalFunction;
    }
    else
    {
        /* Invalid Callback */
    }
}

void __vector_7(void)
{
    if(
        TIMER1_CallBackFunctions[
            TIMER1_CompareMatchAInterrupt
        ] != NULL
    )
    {
        TIMER1_CallBackFunctions[
            TIMER1_CompareMatchAInterrupt
        ]();
    }
}

void __vector_8(void)
{
    if(
        TIMER1_CallBackFunctions[
            TIMER1_CompareMatchBInterrupt
        ] != NULL
    )
    {
        TIMER1_CallBackFunctions[
            TIMER1_CompareMatchBInterrupt
        ]();
    }
}

void __vector_9(void)
{
    if(
        TIMER1_CallBackFunctions[
            TIMER1_OverflowInterrupt
        ] != NULL
    )
    {
        TIMER1_CallBackFunctions[
            TIMER1_OverflowInterrupt
        ]();
    }
}
