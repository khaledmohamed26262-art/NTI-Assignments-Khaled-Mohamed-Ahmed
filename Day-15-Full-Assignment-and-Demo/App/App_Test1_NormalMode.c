#include <stdint.h>

#include "../Mcal/DIO/DIO_Interface.h"
#include "../Mcal/GIE/GIE_Interface.h"
#include "../Mcal/TIMER1/TIMER1_Interface.h"

#include "../Hal/LED/Led_Interface.h"
#include "../Hal/Buzzer/Buzzer_Interface.h"
#include "../Hal/Segment/Segment_Interface.h"

#include "App_Test1_NormalMode.h"

#define LED_GROUP       DIO_GroupC
#define LED_PIN         DIO_Pin0

#define BUZZER_GROUP    DIO_GroupC
#define BUZZER_PIN      DIO_Pin1

#define SEGMENT_GROUP   DIO_GroupA
#define SEGMENT_TYPE    SSD_Cathode

static volatile uint16_t Ms_Ticks = 0U;
static volatile uint8_t Segment_Digit = 0U;

static void Timer1_Normal_1ms_Tick(void)
{
    TIMER1_SetTimerValue(
        TIMER1_NORMAL_PRELOAD_VALUE
    );

    Ms_Ticks++;

    if((Ms_Ticks % 500U) == 0U)
    {
        Led_Toggle(
            LED_GROUP,
            LED_PIN
        );
    }

    if((Ms_Ticks % 150U) == 0U)
    {
        DIO_TogglePin(
            BUZZER_GROUP,
            BUZZER_PIN
        );
    }

    if((Ms_Ticks % 1000U) == 0U)
    {
        Segment_Digit =
            (uint8_t)((Segment_Digit + 1U) % 10U);

        SSD_DisplayNumber(
            SEGMENT_GROUP,
            SEGMENT_TYPE,
            Segment_Digit
        );
    }

    if(Ms_Ticks >= 3000U)
    {
        Ms_Ticks = 0U;
    }
}

void App_Test1_NormalMode_Init(void)
{
    Led_Init(
        LED_GROUP,
        LED_PIN
    );

    Led_Off(
        LED_GROUP,
        LED_PIN,
        LED_SOURCE_CONNECTION
    );

    Buzzer_Init(
        BUZZER_GROUP,
        BUZZER_PIN
    );

    Buzzer_Off(
        BUZZER_GROUP,
        BUZZER_PIN
    );

    SSD_Init(
        SEGMENT_GROUP
    );

    SSD_DisplayNumber(
        SEGMENT_GROUP,
        SEGMENT_TYPE,
        Segment_Digit
    );

    TIMER1_Init(
        TIMER1_NormalMode,
        TIMER1_Prescaler64
    );

    TIMER1_SetTimerValue(
        TIMER1_NORMAL_PRELOAD_VALUE
    );

    TIMER1_SetCallBack(
        Timer1_Normal_1ms_Tick,
        TIMER1_OverflowInterrupt
    );

    TIMER1_EnableInterrupt(
        TIMER1_OverflowInterrupt
    );

    GIE_Enable();
}
