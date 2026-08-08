#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int Number = 0;
    unsigned int TrailingZeros = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    Number = EnteredNumber;

    while ((Number & 1U) == 0)
    {
        TrailingZeros++;
        Number = Number >> 1;
    }

    printf("Lowest order set bit in %u is %u\n", EnteredNumber, TrailingZeros);

    return 0;
}