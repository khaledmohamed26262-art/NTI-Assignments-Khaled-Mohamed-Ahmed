#include <stdio.h>

int main()
{
    signed int EnteredNumber = 0;

    printf("Enter any number: ");
    scanf("%d", &EnteredNumber);

    if (EnteredNumber & 1)
    {
        printf("%d is odd.\n", EnteredNumber);
    }
    else
    {
        printf("%d is even.\n", EnteredNumber);
    }

    return 0;
}