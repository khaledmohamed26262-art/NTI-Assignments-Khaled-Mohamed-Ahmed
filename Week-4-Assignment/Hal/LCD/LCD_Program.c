/**
 * @file LCD_Program.c
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-08-24
 *
 * @copyright Copyright (c) 2026
 *
 */
#include "LCD_Interface.h"

void LCD_Init()
{
    /* Direction */

    /* RS -> Output */
    DIO_DirectionSelectforPin(RSGroup,RSPin,DIO_Outputfor1Pin);

    /* RW -> Output */
    DIO_DirectionSelectforPin(RWGroup,RWPin,DIO_Outputfor1Pin);

    /* E -> Output */
    DIO_DirectionSelectforPin(EGroup,EPin,DIO_Outputfor1Pin);

    DIO_WritePin(RSGroup,RSPin,DIO_Lowfor1Pin);
    DIO_WritePin(RWGroup,RWPin,DIO_Lowfor1Pin);
    DIO_WritePin(EGroup,EPin,DIO_Lowfor1Pin);

#if LCD_TypeMode==Lcd_8bitMode

    /* Data Pins -> All Output */
    DIO_DirectionSelectforGroup(DataGroup,DIO_Outputfor1Group);

    /* 8-bit Initialization */

    /* Wait for 35 msec */
    _delay_ms(35);

    /* Function Set */
    LCD_SendCommand(Lcd_FunctionSet);

    /* Wait 1 msec */
    _delay_ms(1);

    /* Display ON/OFF */
    LCD_SendCommand(Lcd_DisplayOnOFF);

    /* Wait 1 msec */
    _delay_ms(1);

    /* Clear Display */
    LCD_SendCommand(Lcd_ClearScreen);

    /* Wait 2 msec */
    _delay_ms(2);

    /* Entry Mode */
    LCD_SendCommand(Lcd_EntryMode);

    /* Wait 1 msec */
    _delay_ms(1);

#elif LCD_TypeMode==Lcd_4bitMode

    /* 4-Bit Mode Initialization */

#endif /* LCD_TypeMode */
}

void LCD_SendCommand(uint8_t Command)
{
#if LCD_TypeMode==Lcd_8bitMode

    /* RS -> Low */
    DIO_WritePin(RSGroup,RSPin,DIO_Lowfor1Pin);

    /* RW -> Low */
    DIO_WritePin(RWGroup,RWPin,DIO_Lowfor1Pin);

    /* Data Pins -> Command */
    DIO_WriteGroup(DataGroup,Command);

    /* E -> High */
    DIO_WritePin(EGroup,EPin,DIO_Highfor1Pin);

    /* Wait 1 msec */
    _delay_ms(1);

    /* E -> Low */
    DIO_WritePin(EGroup,EPin,DIO_Lowfor1Pin);

#elif LCD_TypeMode==Lcd_4bitMode

    /* 4-Bit Mode Code */

#endif /* LCD_TypeMode */
}

void LCD_WriteCharacter(uint8_t Character)
{
#if LCD_TypeMode==Lcd_8bitMode

    /* RS -> High */
    DIO_WritePin(RSGroup,RSPin,DIO_Highfor1Pin);

    /* RW -> Low */
    DIO_WritePin(RWGroup,RWPin,DIO_Lowfor1Pin);

    /* Data Pins -> Character */
    DIO_WriteGroup(DataGroup,Character);

    /* E -> High */
    DIO_WritePin(EGroup,EPin,DIO_Highfor1Pin);

    /* Wait 1 msec */
    _delay_ms(1);

    /* E -> Low */
    DIO_WritePin(EGroup,EPin,DIO_Lowfor1Pin);

#elif LCD_TypeMode==Lcd_4bitMode

    /* 4-Bit Mode Code */

#endif /* LCD_TypeMode */
}

void LCD_WriteString(uint8_t *String)
{
    if(String!=NULL)
    {
        uint8_t Index = 0;

        while(String[Index]!=NULLChar)
        {
            LCD_WriteCharacter(String[Index]);
            Index++;
        }
    }
}

void LCD_MoveTo(uint8_t LineNo,uint8_t DigitNo)
{
    uint8_t DDRAM_Address = 0;

    switch(LineNo)
    {
        case Lcd_Line1:
            DDRAM_Address=Lcd_Lin1Address+DigitNo;
            break;

        case Lcd_Line2:
            DDRAM_Address=Lcd_Lin2Address+DigitNo;
            break;

        default:
            break;
    }

    LCD_SendCommand(Lcd_SetDDRAMCommand|DDRAM_Address);

    _delay_ms(1);
}

void LCD_WriteNumber(int32_t Number)
{
    uint8_t NumberDigits[10]={0};
    uint8_t Index = 0;
    uint8_t Counter = 0;

    if(Number==0)
    {
        LCD_WriteCharacter('0');
        return;
    }

    if(Number<0)
    {
        LCD_WriteCharacter('-');
        Number=Number*-1;
    }

    while(Number!=0)
    {
        NumberDigits[Index]=(Number%10)+'0';
        Number=Number/10;
        Index++;
    }

    for(Counter=Index;Counter>0;Counter--)
    {
        LCD_WriteCharacter(NumberDigits[Counter-1]);
    }
}

void LCD_StoreSpecialCharacter(uint8_t *SpecialCharacter,uint8_t Location)
{
    if(SpecialCharacter!=NULL)
    {
        if(Location<8)
        {
            uint8_t CGRAM_Address=Location*8;
            uint8_t Index=0;

            LCD_SendCommand(0x40|CGRAM_Address);

            for(Index=0;Index<8;Index++)
            {
                LCD_WriteCharacter(SpecialCharacter[Index]);
            }

            LCD_MoveTo(Lcd_Line1,0);
        }
    }
}