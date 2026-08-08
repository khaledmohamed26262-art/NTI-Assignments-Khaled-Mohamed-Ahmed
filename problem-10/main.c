#include <stdio.h>

int main()
{
    signed int EnteredNumber = 0;
    signed int FlippedNumber = 0;

    printf("Enter any number: ");
    scanf("%d", &EnteredNumber);

    FlippedNumber = ~EnteredNumber;

    printf("Original number = %d (in decimal)\n", EnteredNumber);
    printf("Number after bits are flipped = %d (in decimal)\n", FlippedNumber);

    return 0;
}