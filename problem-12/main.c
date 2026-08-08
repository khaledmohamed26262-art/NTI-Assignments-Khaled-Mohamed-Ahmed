#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int NumberOfRotations = 0;
    unsigned int LeftRotatedNumber = 0;
    unsigned int RightRotatedNumber = 0;
    unsigned int NumberOfBits = sizeof(unsigned int) * 8;

    printf("Enter a number: ");
    scanf("%u", &EnteredNumber);

    printf("Enter number of rotation: ");
    scanf("%u", &NumberOfRotations);

    NumberOfRotations = NumberOfRotations % NumberOfBits;

    if (NumberOfRotations == 0)
    {
        LeftRotatedNumber = EnteredNumber;
        RightRotatedNumber = EnteredNumber;
    }
    else
    {
        LeftRotatedNumber = (EnteredNumber << NumberOfRotations) | (EnteredNumber >> (NumberOfBits - NumberOfRotations));
        RightRotatedNumber = (EnteredNumber >> NumberOfRotations) | (EnteredNumber << (NumberOfBits - NumberOfRotations));
    }

    printf("%u left rotated %u times = %u\n\n", EnteredNumber, NumberOfRotations, LeftRotatedNumber);
    printf("%u right rotated %u times = %u\n", EnteredNumber, NumberOfRotations, RightRotatedNumber);

    return 0;
}