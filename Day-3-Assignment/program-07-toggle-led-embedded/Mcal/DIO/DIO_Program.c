#include "DIO_Interface.h"
#include "DIO_Private.h"
#include "DIO_Config.h"

#include "../Atmega32Register.h"
#include "../../Common/BitMath.h"

void DIO_DirectionSelectorPin(
    const uint8_t GroupName,
    const uint8_t PinNo,
    const uint8_t DirectionState)
{
    if (PinNo < 8U)
    {
        if (DirectionState == Output)
        {
            switch (GroupName)
            {
                case GroupA:
                    SetBit(DDRA_Reg, PinNo);
                    break;

                case GroupB:
                    SetBit(DDRB_Reg, PinNo);
                    break;

                case GroupC:
                    SetBit(DDRC_Reg, PinNo);
                    break;

                case GroupD:
                    SetBit(DDRD_Reg, PinNo);
                    break;

                default:
                    break;
            }
        }
        else if (DirectionState == Input)
        {
            switch (GroupName)
            {
                case GroupA:
                    ClearBit(DDRA_Reg, PinNo);
                    break;

                case GroupB:
                    ClearBit(DDRB_Reg, PinNo);
                    break;

                case GroupC:
                    ClearBit(DDRC_Reg, PinNo);
                    break;

                case GroupD:
                    ClearBit(DDRD_Reg, PinNo);
                    break;

                default:
                    break;
            }
        }
    }
}

void DIO_DirectionSelectorGroup(
    const uint8_t GroupName,
    const uint8_t DirectionState)
{
    uint8_t directionValue =
        DIO_ALL_PINS_INPUT;

    if (DirectionState == Output)
    {
        directionValue =
            DIO_ALL_PINS_OUTPUT;
    }

    switch (GroupName)
    {
        case GroupA:
            DDRA_Reg = directionValue;
            break;

        case GroupB:
            DDRB_Reg = directionValue;
            break;

        case GroupC:
            DDRC_Reg = directionValue;
            break;

        case GroupD:
            DDRD_Reg = directionValue;
            break;

        default:
            break;
    }
}

void DIO_WritePin(
    const uint8_t GroupName,
    const uint8_t PinNo,
    const uint8_t OutputValue)
{
    if (PinNo < 8U)
    {
        if (OutputValue == High)
        {
            switch (GroupName)
            {
                case GroupA:
                    SetBit(PORTA_Reg, PinNo);
                    break;

                case GroupB:
                    SetBit(PORTB_Reg, PinNo);
                    break;

                case GroupC:
                    SetBit(PORTC_Reg, PinNo);
                    break;

                case GroupD:
                    SetBit(PORTD_Reg, PinNo);
                    break;

                default:
                    break;
            }
        }
        else if (OutputValue == Low)
        {
            switch (GroupName)
            {
                case GroupA:
                    ClearBit(PORTA_Reg, PinNo);
                    break;

                case GroupB:
                    ClearBit(PORTB_Reg, PinNo);
                    break;

                case GroupC:
                    ClearBit(PORTC_Reg, PinNo);
                    break;

                case GroupD:
                    ClearBit(PORTD_Reg, PinNo);
                    break;

                default:
                    break;
            }
        }
    }
}

void DIO_WriteGroup(
    const uint8_t GroupName,
    const uint8_t OutputValue)
{
    switch (GroupName)
    {
        case GroupA:
            PORTA_Reg = OutputValue;
            break;

        case GroupB:
            PORTB_Reg = OutputValue;
            break;

        case GroupC:
            PORTC_Reg = OutputValue;
            break;

        case GroupD:
            PORTD_Reg = OutputValue;
            break;

        default:
            break;
    }
}

void DIO_ReadPin(
    const uint8_t GroupName,
    const uint8_t PinNo,
    uint8_t *InputState)
{
    if ((PinNo < 8U) &&
        (InputState != 0))
    {
        switch (GroupName)
        {
            case GroupA:
                *InputState =
                    (uint8_t)
                    ReadBit(PINA_Reg, PinNo);

                break;

            case GroupB:
                *InputState =
                    (uint8_t)
                    ReadBit(PINB_Reg, PinNo);

                break;

            case GroupC:
                *InputState =
                    (uint8_t)
                    ReadBit(PINC_Reg, PinNo);

                break;

            case GroupD:
                *InputState =
                    (uint8_t)
                    ReadBit(PIND_Reg, PinNo);

                break;

            default:
                break;
        }
    }
}

void DIO_TogglePin(
    const uint8_t GroupName,
    const uint8_t PinNo)
{
    if (PinNo < 8U)
    {
        switch (GroupName)
        {
            case GroupA:
                ToggleBit(PORTA_Reg, PinNo);
                break;

            case GroupB:
                ToggleBit(PORTB_Reg, PinNo);
                break;

            case GroupC:
                ToggleBit(PORTC_Reg, PinNo);
                break;

            case GroupD:
                ToggleBit(PORTD_Reg, PinNo);
                break;

            default:
                break;
        }
    }
}