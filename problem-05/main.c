#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int BitPosition = 0;
    unsigned int OriginalNumber = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    printf("Enter nth bit to clear (0-31): ");
    scanf("%u", &BitPosition);

    OriginalNumber = EnteredNumber;

    EnteredNumber = EnteredNumber & ~(1U << BitPosition);

    printf("Bit cleared successfully.\n\n");

    printf("Number before clearing %u bit: %u (in decimal)\n", BitPosition, OriginalNumber);
    printf("Number after clearing %u bit: %u (in decimal)\n", BitPosition, EnteredNumber);

    return 0;
}