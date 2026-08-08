#include <stdio.h>

int main()
{
    signed int Num1 = 0;
    signed int Num2 = 0;

    printf("Enter any two numbers: ");
    scanf("%d %d", &Num1, &Num2);

    printf("Original value of num1 = %d\n", Num1);
    printf("Original value of num2 = %d\n", Num2);

    Num1 = Num1 ^ Num2;
    Num2 = Num1 ^ Num2;
    Num1 = Num1 ^ Num2;

    printf("Num1 after swapping = %d\n", Num1);
    printf("Num2 after swapping = %d\n", Num2);

    return 0;
}