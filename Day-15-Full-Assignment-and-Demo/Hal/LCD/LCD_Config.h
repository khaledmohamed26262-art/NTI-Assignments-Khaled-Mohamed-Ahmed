/**
 * @file LCD_Config.h
 * @author Hesham Ahmed (Hisham4Ahmed@gmail.com)
 * @brief
 * @version 0.1
 * @date 2026-08-24
 *
 * @copyright Copyright (c) 2026
 *
 */
#ifndef LCD_CONFIG
#define LCD_CONFIG

#define LCD_TypeMode Lcd_8bitMode

/* PreConfiguration -> Compile time */

#include "../../Mcal/DIO/DIO_Interface.h"

#define RSPin         DIO_Pin0
#define RSGroup       DIO_GroupB

#define RWPin         DIO_Pin1
#define RWGroup       DIO_GroupB

#define EPin          DIO_Pin2
#define EGroup        DIO_GroupB

#if LCD_TypeMode==Lcd_8bitMode

    #define DataGroup DIO_GroupD

#elif LCD_TypeMode==Lcd_4bitMode

    #define D0Group   DIO_GroupC
    #define D0Pin     DIO_Pin4

#endif

/**
Lcd_4Bit2Line5x8F
Lcd_4Bit2Line5x11F
Lcd_4Bit1Line5x8F
Lcd_4Bit1Line5x11F
Lcd_8Bit2Line5x8F
Lcd_8Bit2Line5x11F
Lcd_8Bit1Line5x8F
Lcd_8Bit1Line5x11F
*/

#define Lcd_FunctionSet Lcd_8Bit2Line5x8F

/**
Lcd_DisplayOff
Lcd_DisplayOnCursorOff
Lcd_DisplayOnCursorOnBlinkOff
Lcd_DisplayOnCursorOnBlinkOn
*/

#define Lcd_DisplayOnOFF Lcd_DisplayOnCursorOnBlinkOn

/**
Lcd_EntryMode_DecNoShift
Lcd_EntryMode_DecShift
Lcd_EntryMode_IncNoShift
Lcd_EntryMode_IncShift
*/

#define Lcd_EntryMode Lcd_EntryMode_IncNoShift

#endif /* LCD_CONFIG */