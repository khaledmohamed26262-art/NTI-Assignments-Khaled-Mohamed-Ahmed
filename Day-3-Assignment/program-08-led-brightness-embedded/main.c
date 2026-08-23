#include <stdint.h>

#include "Mcal/DIO/DIO_Interface.h"
#include "Mcal/ADC/ADC_Interface.h"
#include "Mcal/PWM/PWM_Interface.h"

/**
 * Question 7:
 * Control LED brightness using a potentiometer.
 */

#define POTENTIOMETER_GROUP GroupA
#define POTENTIOMETER_PIN 0U
#define POTENTIOMETER_ADC_CHANNEL 0U

#define LED_PWM_GROUP GroupB
#define LED_PWM_PIN 3U

int main(void)
{
    uint8_t potentiometerValue = 0U;

    DIO_DirectionSelectorPin(
        POTENTIOMETER_GROUP,
        POTENTIOMETER_PIN,
        Input);

    /*
     * Disable the internal pull-up resistor on PA0.
     */
    DIO_WritePin(
        POTENTIOMETER_GROUP,
        POTENTIOMETER_PIN,
        Low);

    /*
     * PB3 is OC0, the Timer0 PWM output pin.
     */
    DIO_DirectionSelectorPin(
        LED_PWM_GROUP,
        LED_PWM_PIN,
        Output);

    ADC_Init();
    PWM_Init();

    while (1)
    {
        potentiometerValue =
            ADC_ReadChannel(
                POTENTIOMETER_ADC_CHANNEL);

        PWM_SetDutyCycle(
            potentiometerValue);
    }

    return 0;
}