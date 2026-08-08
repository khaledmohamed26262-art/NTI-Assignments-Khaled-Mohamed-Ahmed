#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int Number = 0;
    unsigned int HighestOrder = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    Number = EnteredNumber;

    while (Number >> 1)
    {
        Number = Number >> 1;
        HighestOrder++;
    }

    printf("Highest order set bit in %u is %u\n", EnteredNumber, HighestOrder);

    return 0;
}