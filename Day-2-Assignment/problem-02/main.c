#include <stdio.h>

int main()
{
    signed int EnteredNumber = 0;
    unsigned int MostSignificantBit = 0;

    printf("Enter any number: ");
    scanf("%d", &EnteredNumber);

    MostSignificantBit = 1U << (sizeof(EnteredNumber) * 8 - 1);

    if (EnteredNumber & MostSignificantBit)
    {
        printf("MSB of %d is set (1).\n", EnteredNumber);
    }
    else
    {
        printf("MSB of %d is unset (0).\n", EnteredNumber);
    }

    return 0;
}