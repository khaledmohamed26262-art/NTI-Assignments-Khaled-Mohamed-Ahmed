#include <stdio.h>

int main()
{
    unsigned int Amount = 0;
    unsigned int Note500 = 0;
    unsigned int Note100 = 0;
    unsigned int Note50 = 0;
    unsigned int Note20 = 0;
    unsigned int Note10 = 0;
    unsigned int Note5 = 0;
    unsigned int Note2 = 0;
    unsigned int Note1 = 0;

    printf("Enter amount: ");
    scanf("%u", &Amount);

    Note500 = Amount / 500;
    Amount = Amount % 500;

    Note100 = Amount / 100;
    Amount = Amount % 100;

    Note50 = Amount / 50;
    Amount = Amount % 50;

    Note20 = Amount / 20;
    Amount = Amount % 20;

    Note10 = Amount / 10;
    Amount = Amount % 10;

    Note5 = Amount / 5;
    Amount = Amount % 5;

    Note2 = Amount / 2;
    Amount = Amount % 2;

    Note1 = Amount;

    printf("Total number of notes =\n");
    printf("500 = %u\n", Note500);
    printf("100 = %u\n", Note100);
    printf("50 = %u\n", Note50);
    printf("20 = %u\n", Note20);
    printf("10 = %u\n", Note10);
    printf("5 = %u\n", Note5);
    printf("2 = %u\n", Note2);
    printf("1 = %u\n", Note1);

    return 0;
}