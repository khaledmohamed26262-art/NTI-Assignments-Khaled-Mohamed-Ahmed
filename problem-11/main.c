#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int ZeroBits = 0;
    unsigned int OneBits = 0;
    unsigned int BitPosition = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    for (BitPosition = 0; BitPosition < 32; BitPosition++)
    {
        if (EnteredNumber & (1U << BitPosition))
        {
            OneBits++;
        }
        else
        {
            ZeroBits++;
        }
    }

    printf("Total zero bit is %u\n", ZeroBits);
    printf("Total one bit is %u\n", OneBits);

    return 0;
}