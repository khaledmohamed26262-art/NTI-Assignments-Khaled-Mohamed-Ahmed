#ifndef EXTI_INTERFACE
#define EXTI_INTERFACE
#include<stdint.h>
#include "../../Common/BitMath.h"
#include "../../Common/Definition.h"
#include "../Atmega32Register.h"
#include "EXTI_Private.h"
#include "EXTI_Config.h"

/*API's*/
void EXTI_Init(uint8_t InterruptNumber,uint8_t SensControl);
void EXTI_Disable(uint8_t InterruptNumber);

/*Call-Back-Function*/

/*ISR*/
/*EXTI0*/
void __vector_1()   __attribute__((signal));
/*EXTI1*/
void __vector_2()  __attribute__((signal));
/*EXTI2*/
// void __vector_3()  __attribute__((signal));
#endif /* EXTI_INTERFACE */
