#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int Number = 0;
    unsigned int LowestOrder = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    Number = EnteredNumber;

    if (Number == 0)
    {
        printf("No set bit in 0\n");
        return 0;
    }

    while ((Number & 1U) == 0)
    {
        Number = Number >> 1;
        LowestOrder++;
    }

    printf("Lowest order set bit in %u is %u\n", EnteredNumber, LowestOrder);

    return 0;
}