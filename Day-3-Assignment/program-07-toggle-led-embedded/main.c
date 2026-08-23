#include <stdint.h>
#include "Mcal/DIO/DIO_Interface.h"

/**
 * Question 5:
 * C function to toggle a LED.
 */

#define LED_GROUP GroupD
#define LED_PIN 0U

#define DELAY_COUNT 50000UL

void Delay(void)
{
    volatile unsigned long int delayCounter = 0UL;

    for (delayCounter = 0UL;
         delayCounter < DELAY_COUNT;
         delayCounter++)
    {
    }
}

void ToggleLed(void)
{
    DIO_TogglePin(LED_GROUP, LED_PIN);
}

int main(void)
{
    DIO_DirectionSelectorPin(
        LED_GROUP,
        LED_PIN,
        Output);

    DIO_WritePin(
        LED_GROUP,
        LED_PIN,
        Low);

    while (1)
    {
        ToggleLed();
        Delay();
    }

    return 0;
}