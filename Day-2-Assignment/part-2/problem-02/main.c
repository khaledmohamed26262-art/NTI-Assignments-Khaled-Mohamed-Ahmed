#include <stdio.h>

int main()
{
    signed int Num1 = 0;
    signed int Num2 = 0;
    signed int Num3 = 0;
    signed int Num4 = 0;
    signed int Num5 = 0;

    printf("enter the five number:\n");
    scanf("%d %d %d %d %d", &Num1, &Num2, &Num3, &Num4, &Num5);

    printf("the numbers that is divisable by 3 is :\n");

    if (Num1 % 3 == 0)
        printf("%d\n", Num1);

    if (Num2 % 3 == 0)
        printf("%d\n", Num2);

    if (Num3 % 3 == 0)
        printf("%d\n", Num3);

    if (Num4 % 3 == 0)
        printf("%d\n", Num4);

    if (Num5 % 3 == 0)
        printf("%d\n", Num5);

    return 0;
}