#include "App/App_Interface.h"

int main(void)
{
    /*
     * Initialize the complete application.
     */
    App_Init();

    /*
     * All timing tasks are executed
     * using Timer1 Overflow Interrupt.
     */
    while(1)
    {
    }

    return 0;
}