#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <stdint.h>
#include <util/delay.h>

#include "../Mcal/DIO/DIO_Interface.h"
#include "../Mcal/TIMER1/TIMER1_Interface.h"

#include "App_Test3_PWM.h"

/*
 * PWM output:
 * PD5 is OC1A.
 */
#define PWM_GROUP          DIO_GroupD
#define PWM_PIN            DIO_Pin5

/*
 * Increase button:
 * PB0 with Internal Pull-up.
 */
#define UP_BUTTON_GROUP    DIO_GroupB
#define UP_BUTTON_PIN      DIO_Pin0

/*
 * Decrease button:
 * PB1 with Internal Pull-up.
 */
#define DOWN_BUTTON_GROUP  DIO_GroupB
#define DOWN_BUTTON_PIN    DIO_Pin1

/*
 * Fast PWM 8-bit:
 * Minimum = 0
 * Maximum = 255
 *
 * Start from approximately 50%.
 */
static uint16_t DutyValue = 128U;

void App_Test3_PWM_Init(void)
{
    /*
     * PD5/OC1A is the PWM Output pin.
     */
    DIO_DirectionSelectforPin(
        PWM_GROUP,
        PWM_PIN,
        DIO_Outputfor1Pin
    );

    /*
     * PB0 is Input for Increase button.
     */
    DIO_DirectionSelectforPin(
        UP_BUTTON_GROUP,
        UP_BUTTON_PIN,
        DIO_Inputfor1Pin
    );

    /*
     * Write High while PB0 is Input
     * to enable Internal Pull-up.
     */
    DIO_WritePin(
        UP_BUTTON_GROUP,
        UP_BUTTON_PIN,
        DIO_Highfor1Pin
    );

    /*
     * PB1 is Input for Decrease button.
     */
    DIO_DirectionSelectforPin(
        DOWN_BUTTON_GROUP,
        DOWN_BUTTON_PIN,
        DIO_Inputfor1Pin
    );

    /*
     * Enable Internal Pull-up on PB1.
     */
    DIO_WritePin(
        DOWN_BUTTON_GROUP,
        DOWN_BUTTON_PIN,
        DIO_Highfor1Pin
    );

    /*
     * Initialize Timer1:
     * Fast PWM 8-bit
     * Prescaler = 64
     */
    TIMER1_Init(
        TIMER1_FastPWM8Bit,
        TIMER1_Prescaler64
    );

    /*
     * Non-inverting PWM on OC1A.
     */
    TIMER1_SetCompareOutputMode(
        TIMER1_ChannelA,
        TIMER1_OC_NonInverting
    );

    /*
     * Initial Duty Cycle:
     * OCR1A = 128, approximately 50%.
     */
    TIMER1_SetCompareValue(
        TIMER1_ChannelA,
        DutyValue
    );
}

void App_Test3_PWM_Task(void)
{
    uint8_t UpButtonState =
        DIO_Highfor1Pin;

    uint8_t DownButtonState =
        DIO_Highfor1Pin;

    /*
     * Read Increase button.
     */
    DIO_ReadPin(
        UP_BUTTON_GROUP,
        UP_BUTTON_PIN,
        &UpButtonState
    );

    /*
     * Read Decrease button.
     */
    DIO_ReadPin(
        DOWN_BUTTON_GROUP,
        DOWN_BUTTON_PIN,
        &DownButtonState
    );

    /*
     * Internal Pull-up:
     * Pressed button gives Low.
     */
    if(UpButtonState == DIO_Lowfor1Pin)
    {
        /*
         * Simple button debounce.
         */
        _delay_ms(30);

        DIO_ReadPin(
            UP_BUTTON_GROUP,
            UP_BUTTON_PIN,
            &UpButtonState
        );

        if(UpButtonState == DIO_Lowfor1Pin)
        {
            /*
             * Increase Duty Cycle by 25.
             * Maximum value is 255.
             */
            if(DutyValue <= 230U)
            {
                DutyValue += 25U;
            }
            else
            {
                DutyValue = 255U;
            }

            TIMER1_SetCompareValue(
                TIMER1_ChannelA,
                DutyValue
            );

            /*
             * Wait until button is released
             * to count one press only.
             */
            do
            {
                DIO_ReadPin(
                    UP_BUTTON_GROUP,
                    UP_BUTTON_PIN,
                    &UpButtonState
                );
            }
            while(UpButtonState ==
                  DIO_Lowfor1Pin);
        }
    }
    else if(DownButtonState ==
            DIO_Lowfor1Pin)
    {
        /*
         * Simple button debounce.
         */
        _delay_ms(30);

        DIO_ReadPin(
            DOWN_BUTTON_GROUP,
            DOWN_BUTTON_PIN,
            &DownButtonState
        );

        if(DownButtonState ==
           DIO_Lowfor1Pin)
        {
            /*
             * Decrease Duty Cycle by 25.
             * Minimum value is zero.
             */
            if(DutyValue >= 25U)
            {
                DutyValue -= 25U;
            }
            else
            {
                DutyValue = 0U;
            }

            TIMER1_SetCompareValue(
                TIMER1_ChannelA,
                DutyValue
            );

            /*
             * Wait until button is released.
             */
            do
            {
                DIO_ReadPin(
                    DOWN_BUTTON_GROUP,
                    DOWN_BUTTON_PIN,
                    &DownButtonState
                );
            }
            while(DownButtonState ==
                  DIO_Lowfor1Pin);
        }
    }
    else
    {
        /*
         * No button is pressed.
         * Keep the current Duty Cycle.
         */
    }
}