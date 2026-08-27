#include "Common/Definition.h"

#include "Hal/KeyPad/KeyPad_Interface.h"
#include "Hal/LCD/LCD_Interface.h"
#include "Hal/LED/Led_Interface.h"
#include "Hal/Segment/Segment_Interface.h"
#include "Hal/DC_Motor/DCMotor_Interface.h"

#include <util/delay.h>

void main()
{
    uint8_t CorrectPassword[4]={'1','2','3','4'};
    uint8_t EnteredPassword[4]={0};

    uint8_t PressedKey=KPD_NotPressed;
    uint8_t PasswordIndex=0;
    uint8_t CompareIndex=0;
    uint8_t WrongAttempts=0;
    uint8_t PasswordCorrect=0;
    uint8_t LoginState=0;

    uint8_t EnterPasswordMessage[]="Enter Password";
    uint8_t WrongPasswordMessage[]="Wrong Password";
    uint8_t AccessGrantedMessage[]="Access Granted";
    uint8_t SystemBlockedMessage[]="System Blocked";
    uint8_t ClearLine[]="                ";

    uint8_t MenuLine1[]="1:CW 2:CCW";
    uint8_t MenuLine2[]="3:STOP 4:LEDS";

    uint8_t ClockwiseMessage[]="Motor Clockwise";
    uint8_t CounterMessage[]="Motor CounterCW";
    uint8_t StopMessage[]="Motor Stopped";
    uint8_t AnimationMessage[]="LED Animation";

    KPD_Init();
    LCD_Init();

    SSD_Init(DIO_GroupC);
    SSD_DisplayNumber(DIO_GroupC,SSD_Cathode,WrongAttempts);

    Led_Init(DIO_GroupB,DIO_Pin3);
    Led_Init(DIO_GroupB,DIO_Pin4);
    Led_Init(DIO_GroupB,DIO_Pin5);

    Led_Off(DIO_GroupB,DIO_Pin3,LED_SOURCE_CONNECTION);
    Led_Off(DIO_GroupB,DIO_Pin4,LED_SOURCE_CONNECTION);
    Led_Off(DIO_GroupB,DIO_Pin5,LED_SOURCE_CONNECTION);

    DCMotor_Init();

    LCD_WriteString(EnterPasswordMessage);
    LCD_MoveTo(Lcd_Line2,0);

    while(LoginState==0 && WrongAttempts<3)
    {
        PressedKey=KPD_GetPressedKey();

        if(PressedKey!=KPD_NotPressed)
        {
            if(PressedKey>='0' && PressedKey<='9')
            {
                if(PasswordIndex<4)
                {
                    EnteredPassword[PasswordIndex]=PressedKey;
                    PasswordIndex++;

                    LCD_WriteCharacter('*');
                }
            }
            else if(PressedKey=='C')
            {
                PasswordIndex=0;

                LCD_MoveTo(Lcd_Line2,0);
                LCD_WriteString(ClearLine);
                LCD_MoveTo(Lcd_Line2,0);
            }
            else if(PressedKey=='=')
            {
                PasswordCorrect=1;

                if(PasswordIndex!=4)
                {
                    PasswordCorrect=0;
                }
                else
                {
                    for(CompareIndex=0;
                        CompareIndex<4;
                        CompareIndex++)
                    {
                        if(EnteredPassword[CompareIndex]
                           !=CorrectPassword[CompareIndex])
                        {
                            PasswordCorrect=0;
                        }
                    }
                }

                if(PasswordCorrect==1)
                {
                    LoginState=1;

                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    LCD_WriteString(AccessGrantedMessage);
                    _delay_ms(1000);
                }
                else
                {
                    WrongAttempts++;

                    SSD_DisplayNumber(DIO_GroupC,
                                      SSD_Cathode,
                                      WrongAttempts);

                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    if(WrongAttempts>=3)
                    {
                        DCMotor_Stop();

                        LCD_WriteString(SystemBlockedMessage);

                        Led_On(DIO_GroupB,
                               DIO_Pin3,
                               LED_SOURCE_CONNECTION);

                        Led_On(DIO_GroupB,
                               DIO_Pin4,
                               LED_SOURCE_CONNECTION);

                        Led_On(DIO_GroupB,
                               DIO_Pin5,
                               LED_SOURCE_CONNECTION);
                    }
                    else
                    {
                        LCD_WriteString(WrongPasswordMessage);
                        _delay_ms(1000);

                        PasswordIndex=0;

                        LCD_SendCommand(Lcd_ClearScreen);
                        _delay_ms(2);

                        LCD_WriteString(EnterPasswordMessage);
                        LCD_MoveTo(Lcd_Line2,0);
                    }
                }
            }

            while(KPD_GetPressedKey()!=KPD_NotPressed)
            {
                /* Wait Until Button Released */
            }

            _delay_ms(20);
        }
    }

    if(LoginState==1)
    {
        LCD_SendCommand(Lcd_ClearScreen);
        _delay_ms(2);

        LCD_WriteString(MenuLine1);
        LCD_MoveTo(Lcd_Line2,0);
        LCD_WriteString(MenuLine2);

        while(1)
        {
            PressedKey=KPD_GetPressedKey();

            if(PressedKey!=KPD_NotPressed)
            {
                if(PressedKey=='1')
                {
                    DCMotor_RotateClockwise();

                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    LCD_WriteString(ClockwiseMessage);
                    _delay_ms(1000);
                }
                else if(PressedKey=='2')
                {
                    DCMotor_RotateCounterClockwise();

                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    LCD_WriteString(CounterMessage);
                    _delay_ms(1000);
                }
                else if(PressedKey=='3')
                {
                    DCMotor_Stop();

                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    LCD_WriteString(StopMessage);
                    _delay_ms(1000);
                }
                else if(PressedKey=='4')
                {
                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    LCD_WriteString(AnimationMessage);

                    Led_Off(DIO_GroupB,
                            DIO_Pin3,
                            LED_SOURCE_CONNECTION);

                    Led_Off(DIO_GroupB,
                            DIO_Pin4,
                            LED_SOURCE_CONNECTION);

                    Led_Off(DIO_GroupB,
                            DIO_Pin5,
                            LED_SOURCE_CONNECTION);

                    Led_On(DIO_GroupB,
                           DIO_Pin3,
                           LED_SOURCE_CONNECTION);

                    _delay_ms(300);

                    Led_Off(DIO_GroupB,
                            DIO_Pin3,
                            LED_SOURCE_CONNECTION);

                    Led_On(DIO_GroupB,
                           DIO_Pin4,
                           LED_SOURCE_CONNECTION);

                    _delay_ms(300);

                    Led_Off(DIO_GroupB,
                            DIO_Pin4,
                            LED_SOURCE_CONNECTION);

                    Led_On(DIO_GroupB,
                           DIO_Pin5,
                           LED_SOURCE_CONNECTION);

                    _delay_ms(300);

                    Led_Off(DIO_GroupB,
                            DIO_Pin5,
                            LED_SOURCE_CONNECTION);

                    _delay_ms(300);
                }
                else
                {
                    /* No Action */
                }

                if(PressedKey>='1' && PressedKey<='4')
                {
                    LCD_SendCommand(Lcd_ClearScreen);
                    _delay_ms(2);

                    LCD_WriteString(MenuLine1);
                    LCD_MoveTo(Lcd_Line2,0);
                    LCD_WriteString(MenuLine2);
                }

                while(KPD_GetPressedKey()!=KPD_NotPressed)
                {
                    /* Wait Until Button Released */
                }

                _delay_ms(20);
            }
        }
    }
    else
    {
        DCMotor_Stop();

        while(1)
        {
            /* System Blocked */
        }
    }
}