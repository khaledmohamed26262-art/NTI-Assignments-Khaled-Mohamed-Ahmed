#include <stdio.h>

int main()
{
    unsigned int Number = 0;
    unsigned int Sum = 0;

    printf("The first 10 natural number is :\n");

    for (Number = 1; Number <= 10; Number++)
    {
        printf("%u ", Number);
        Sum = Sum + Number;
    }

    printf("\nThe Sum is : %u\n", Sum);

    return 0;
}