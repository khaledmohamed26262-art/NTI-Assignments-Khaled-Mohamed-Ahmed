#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int LeadingZeros = 0;
    unsigned int BitMask = 1U << (sizeof(unsigned int) * 8 - 1);

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    while ((EnteredNumber & BitMask) == 0 && BitMask != 0)
    {
        LeadingZeros++;
        BitMask = BitMask >> 1;
    }

    printf("Total number of leading zeros in %u is %u\n", EnteredNumber, LeadingZeros);

    return 0;
}