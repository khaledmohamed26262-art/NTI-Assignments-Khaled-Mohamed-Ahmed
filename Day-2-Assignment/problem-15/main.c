#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    signed int BitPosition = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    printf("Converted binary: ");

    for (BitPosition = 31; BitPosition >= 0; BitPosition--)
    {
        if (EnteredNumber & (1U << BitPosition))
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");

    return 0;
}