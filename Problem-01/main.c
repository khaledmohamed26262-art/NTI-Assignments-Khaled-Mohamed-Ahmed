#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    if (EnteredNumber & 1)
    {
        printf("LSB of %u is set (1).\n", EnteredNumber);
    }
    else
    {
        printf("LSB of %u is unset (0).\n", EnteredNumber);
    }

    return 0;
}