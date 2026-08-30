#include <stdint.h>

#include "../Mcal/DIO/DIO_Interface.h"
#include "../Mcal/GIE/GIE_Interface.h"
#include "../Mcal/TIMER1/TIMER1_Interface.h"

#include "../Hal/Buzzer/Buzzer_Interface.h"
#include "../Hal/Segment/Segment_Interface.h"

#include "App_Interface.h"

/*
 * LED brightness:
 * Timer1 Channel A output on PD5/OC1A.
 */
#define PWM_LED_GROUP          DIO_GroupD
#define PWM_LED_PIN            DIO_Pin5

/*
 * Buzzer connection.
 */
#define BUZZER_GROUP           DIO_GroupC
#define BUZZER_PIN             DIO_Pin1

/*
 * Seven Segment connection.
 */
#define SEGMENT_GROUP          DIO_GroupA
#define SEGMENT_TYPE           SSD_Cathode

/*
 * Increase brightness button.
 * Internal Pull-up on PB0.
 */
#define UP_BUTTON_GROUP        DIO_GroupB
#define UP_BUTTON_PIN          DIO_Pin0

/*
 * Decrease brightness button.
 * Internal Pull-up on PB1.
 */
#define DOWN_BUTTON_GROUP      DIO_GroupB
#define DOWN_BUTTON_PIN        DIO_Pin1

/*
 * Timer1 Fast PWM 8-bit with:
 *
 * F_CPU = 8 MHz
 * Prescaler = 64
 *
 * Overflow period:
 * 256 * 64 / 8000000 = 2.048 ms
 */
#define LED_TOGGLE_TICKS       244U
#define BUZZER_TOGGLE_TICKS    73U
#define SEGMENT_COUNT_TICKS    488U
#define BUTTON_CHECK_TICKS     98U

/*
 * PWM Duty Cycle:
 * Minimum = 0
 * Maximum = 255
 * Step = approximately 10%.
 */
#define DUTY_MINIMUM           0U
#define DUTY_MAXIMUM           255U
#define DUTY_STEP              25U
#define DUTY_START             128U

/*
 * Software counters.
 */
static volatile uint16_t LedTicks = 0U;
static volatile uint16_t BuzzerTicks = 0U;
static volatile uint16_t SegmentTicks = 0U;
static volatile uint16_t ButtonTicks = 0U;

/*
 * Current Seven Segment number.
 */
static volatile uint8_t SegmentNumber = 0U;

/*
 * Current LED brightness.
 * 128 is approximately 50%.
 */
static volatile uint16_t CurrentDuty = DUTY_START;

/*
 * LED state:
 * 1 = LED is enabled.
 * 0 = LED is disabled.
 */
static volatile uint8_t LedEnabled = 1U;

/*
 * This function is called whenever
 * Timer1 overflows.
 *
 * One Overflow is approximately 2.048 ms.
 */
static void App_Timer1Overflow(void)
{
    uint8_t UpButtonState = DIO_Highfor1Pin;
    uint8_t DownButtonState = DIO_Highfor1Pin;

    LedTicks++;
    BuzzerTicks++;
    SegmentTicks++;
    ButtonTicks++;

    /*
     * Requirement 1:
     * Toggle LED approximately every 500 ms.
     */
    if(LedTicks >= LED_TOGGLE_TICKS)
    {
        LedTicks = 0U;

        if(LedEnabled == 1U)
        {
            LedEnabled = 0U;

            /*
             * Zero Duty makes LED appear OFF.
             */
            TIMER1_SetCompareValue(
                TIMER1_ChannelA,
                DUTY_MINIMUM
            );
        }
        else
        {
            LedEnabled = 1U;

            /*
             * Restore the selected brightness.
             */
            TIMER1_SetCompareValue(
                TIMER1_ChannelA,
                CurrentDuty
            );
        }
    }

    /*
     * Requirement 2:
     * Toggle Buzzer approximately every 150 ms.
     */
    if(BuzzerTicks >= BUZZER_TOGGLE_TICKS)
    {
        BuzzerTicks = 0U;

        DIO_TogglePin(
            BUZZER_GROUP,
            BUZZER_PIN
        );
    }

    /*
     * Requirement 3:
     * Increase Seven Segment every 1 second.
     */
    if(SegmentTicks >= SEGMENT_COUNT_TICKS)
    {
        SegmentTicks = 0U;

        SegmentNumber++;

        if(SegmentNumber == 10U)
        {
            SegmentNumber = 0U;
        }

        SSD_DisplayNumber(
            SEGMENT_GROUP,
            SEGMENT_TYPE,
            SegmentNumber
        );
    }

    /*
     * Requirements 4 and 5:
     * Check both buttons approximately every 200 ms.
     */
    if(ButtonTicks >= BUTTON_CHECK_TICKS)
    {
        ButtonTicks = 0U;

        DIO_ReadPin(
            UP_BUTTON_GROUP,
            UP_BUTTON_PIN,
            &UpButtonState
        );

        DIO_ReadPin(
            DOWN_BUTTON_GROUP,
            DOWN_BUTTON_PIN,
            &DownButtonState
        );

        /*
         * Internal Pull-up:
         * Pressed button gives Low.
         *
         * Increase brightness only if
         * UP is pressed alone.
         */
        if((UpButtonState == DIO_Lowfor1Pin) &&
           (DownButtonState == DIO_Highfor1Pin))
        {
            if(CurrentDuty <=
               (DUTY_MAXIMUM - DUTY_STEP))
            {
                CurrentDuty += DUTY_STEP;
            }
            else
            {
                CurrentDuty = DUTY_MAXIMUM;
            }

            /*
             * Update OCR1A only while LED is ON.
             * If LED is OFF, save the new value
             * until the next LED toggle.
             */
            if(LedEnabled == 1U)
            {
                TIMER1_SetCompareValue(
                    TIMER1_ChannelA,
                    CurrentDuty
                );
            }
        }
        /*
         * Decrease brightness only if
         * DOWN is pressed alone.
         */
        else if((DownButtonState == DIO_Lowfor1Pin) &&
                (UpButtonState == DIO_Highfor1Pin))
        {
            if(CurrentDuty >= DUTY_STEP)
            {
                CurrentDuty -= DUTY_STEP;
            }
            else
            {
                CurrentDuty = DUTY_MINIMUM;
            }

            if(LedEnabled == 1U)
            {
                TIMER1_SetCompareValue(
                    TIMER1_ChannelA,
                    CurrentDuty
                );
            }
        }
        else
        {
            /*
             * No button or both buttons pressed:
             * Keep the current brightness.
             */
        }
    }
}

void App_Init(void)
{
    /*
     * PD5/OC1A is the PWM output.
     */
    DIO_DirectionSelectforPin(
        PWM_LED_GROUP,
        PWM_LED_PIN,
        DIO_Outputfor1Pin
    );

    /*
     * Initialize Buzzer on PC1.
     */
    Buzzer_Init(
        BUZZER_GROUP,
        BUZZER_PIN
    );

    Buzzer_Off(
        BUZZER_GROUP,
        BUZZER_PIN
    );

    /*
     * Initialize Seven Segment on PORTA.
     */
    SSD_Init(
        SEGMENT_GROUP
    );

    SSD_DisplayNumber(
        SEGMENT_GROUP,
        SEGMENT_TYPE,
        SegmentNumber
    );

    /*
     * PB0 = Input with Internal Pull-up.
     */
    DIO_DirectionSelectforPin(
        UP_BUTTON_GROUP,
        UP_BUTTON_PIN,
        DIO_Inputfor1Pin
    );

    DIO_WritePin(
        UP_BUTTON_GROUP,
        UP_BUTTON_PIN,
        DIO_Highfor1Pin
    );

    /*
     * PB1 = Input with Internal Pull-up.
     */
    DIO_DirectionSelectforPin(
        DOWN_BUTTON_GROUP,
        DOWN_BUTTON_PIN,
        DIO_Inputfor1Pin
    );

    DIO_WritePin(
        DOWN_BUTTON_GROUP,
        DOWN_BUTTON_PIN,
        DIO_Highfor1Pin
    );

    /*
     * Timer1:
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
     * Start LED at approximately 50%.
     */
    TIMER1_SetCompareValue(
        TIMER1_ChannelA,
        CurrentDuty
    );

    /*
     * Connect Timer1 Overflow Interrupt
     * to the Application function.
     */
    TIMER1_SetCallBack(
        App_Timer1Overflow,
        TIMER1_OverflowInterrupt
    );

    /*
     * Enable Timer1 Overflow Interrupt.
     */
    TIMER1_EnableInterrupt(
        TIMER1_OverflowInterrupt
    );

    /*
     * Enable Global Interrupt.
     */
    GIE_Enable();
}