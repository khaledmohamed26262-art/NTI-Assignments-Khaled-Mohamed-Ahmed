#include <stdio.h>

int main()
{
    unsigned int EnteredNumber = 0;
    unsigned int BitPosition = 0;
    unsigned int OriginalNumber = 0;

    printf("Enter any number: ");
    scanf("%u", &EnteredNumber);

    printf("Enter nth bit to set (0-31): ");
    scanf("%u", &BitPosition);

    OriginalNumber = EnteredNumber;

    EnteredNumber = EnteredNumber | (1U << BitPosition);

    printf("Bit set successfully.\n\n");

    printf("Number before setting %u bit: %u (in decimal)\n", BitPosition, OriginalNumber);
    printf("Number after setting %u bit: %u (in decimal)\n", BitPosition, EnteredNumber);

    return 0;
}