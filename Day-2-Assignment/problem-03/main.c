#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int BitPosition = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    printf("Enter nth bit to check (0-31): ");
    scanf("%u", &BitPosition);

    if (EnteredNumber & (1U << BitPosition))
    {
        printf("The %u bit is set to 1\n", BitPosition);
    }
    else
    {
        printf("The %u bit is set to 0\n", BitPosition);
    }

    return 0;
}