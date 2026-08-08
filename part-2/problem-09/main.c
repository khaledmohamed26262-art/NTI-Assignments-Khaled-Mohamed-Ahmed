#include <stdio.h>

int main()
{
    char Operator = '\0';
    double Num1 = 0.0;
    double Num2 = 0.0;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &Operator);

    printf("Enter two operands: ");
    scanf("%lf %lf", &Num1, &Num2);

    switch (Operator)
    {
        case '+':
            printf("%.1f + %.1f = %.1f\n", Num1, Num2, Num1 + Num2);
            break;

        case '-':
            printf("%.1f - %.1f = %.1f\n", Num1, Num2, Num1 - Num2);
            break;

        case '*':
            printf("%.1f * %.1f = %.1f\n", Num1, Num2, Num1 * Num2);
            break;

        case '/':
            if (Num2 != 0)
                printf("%.1f / %.1f = %.1f\n", Num1, Num2, Num1 / Num2);
            else
                printf("Cannot divide by zero.\n");
            break;

        default:
            printf("Invalid operator.\n");
    }

    return 0;
}