#include <stdio.h>

int main()
{
    signed int Number = 0;
    unsigned int Counter = 0;

    printf("Input the number (Table to be calculated) : ");
    scanf("%d", &Number);

    for (Counter = 1; Counter <= 10; Counter++)
    {
        printf("%d X %u = %d\n", Number, Counter, Number * (signed int)Counter);
    }

    return 0;
}