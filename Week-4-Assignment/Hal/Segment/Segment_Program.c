/**
 * @file Segment_Program.c
 * @author Team1
 * @brief
 * @version 0.1
 * @date 2026-08-24
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "Segment_Interface.h"

/*
    Cathode

    Bit 6 5 4 3 2 1 0
        g f e d c b a
*/

static uint8_t SSD_NumberPatterns[10] =
{
    0x3FU,
    0x06U,
    0x5BU,
    0x4FU,
    0x66U,
    0x6DU,
    0x7DU,
    0x07U,
    0x7FU,
    0x6FU
};

void SSD_Init(uint8_t SSDGroup)
{
    uint8_t PinIndex=0;

    for(PinIndex=DIO_Pin0;PinIndex<=DIO_Pin6;PinIndex++)
    {
        DIO_DirectionSelectforPin(SSDGroup,
                                  PinIndex,
                                  DIO_Outputfor1Pin);
    }
}

void SSD_DisplayNumber(uint8_t SSDGroup,uint8_t SSDType,uint8_t Number)
{
    uint8_t LocalPattern=0;
    uint8_t PinIndex=0;
    uint8_t PinState=0;

    if(Number<=Segment_MaxNumber)
    {
        LocalPattern=SSD_NumberPatterns[Number];

        if(SSDType==SSD_Anode)
        {
            LocalPattern=(uint8_t)(~LocalPattern);
        }
        else if(SSDType==SSD_Cathode)
        {
            /* Pattern Used As It Is */
        }
        else
        {
            /* Error */
        }

        if(SSDType==SSD_Anode || SSDType==SSD_Cathode)
        {
            for(PinIndex=DIO_Pin0;PinIndex<=DIO_Pin6;PinIndex++)
            {
                PinState=ReadBit(LocalPattern,PinIndex);

                DIO_WritePin(SSDGroup,
                             PinIndex,
                             PinState);
            }
        }
    }
    else
    {
        /* Error */
    }
}

void SSD_Off(uint8_t SSDGroup,uint8_t SSDType)
{
    uint8_t PinIndex=0;

    if(SSDType==SSD_Anode)
    {
        for(PinIndex=DIO_Pin0;PinIndex<=DIO_Pin6;PinIndex++)
        {
            DIO_WritePin(SSDGroup,
                         PinIndex,
                         DIO_Highfor1Pin);
        }
    }
    else if(SSDType==SSD_Cathode)
    {
        for(PinIndex=DIO_Pin0;PinIndex<=DIO_Pin6;PinIndex++)
        {
            DIO_WritePin(SSDGroup,
                         PinIndex,
                         DIO_Lowfor1Pin);
        }
    }
    else
    {
        /* Error */
    }
}