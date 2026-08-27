#include "EXTI_Interface.h"


/*API's*/
void EXTI_Init(uint8_t InterruptNumber,uint8_t SensControl)
{
    if(InterruptNumber==EXTI0) //MCUCR    ISC00 ISC01
    {
        if(SensControl== EXTI_LowLevel)
        {
            ClearBit(MCUCR_Reg,Bit_ISC00);
            ClearBit(MCUCR_Reg,Bit_ISC01);
        }
        else if (SensControl==EXTI_AnyLogic)
        {
            SetBit  (MCUCR_Reg,Bit_ISC00);
            ClearBit(MCUCR_Reg,Bit_ISC01);
        }
        else if (SensControl==EXTI_Falling)
        {
            ClearBit(MCUCR_Reg,Bit_ISC00);
            SetBit(MCUCR_Reg,Bit_ISC01);
        }
        else if (SensControl==EXTI_Rising)
        {
            SetBit(MCUCR_Reg,Bit_ISC00);
            SetBit(MCUCR_Reg,Bit_ISC01);
        }
        else
        {

        }
        // Enable for INT0 
        // GICR - INT0 -> 1 
        SetBit(GICR_Reg,Bit_INT0);
    }
    else if(InterruptNumber==EXTI1)
    {

    }
    else if (InterruptNumber==EXTI2)
    {

    }
    else
    {
        // @todo return the Error Code Wrong InterruptNumber 
    }
}
void EXTI_Disable(uint8_t InterruptNumber)
{
    if(InterruptNumber==EXTI0)
    {
        ClearBit(GICR_Reg,Bit_INT0);
    }
    else if(InterruptNumber==EXTI1)
    {
        ClearBit(GICR_Reg,Bit_INT1);
    }
    else if(InterruptNumber==EXTI2)
    {
        ClearBit(GICR_Reg,Bit_INT2);
    }
    else
    {

    }
}

/*Call-Back-Function*/

/*ISR*/

/*EXTI1*/
void __vector_2()  {} 
/*EXTI2*/
// void __vector_3()  {}