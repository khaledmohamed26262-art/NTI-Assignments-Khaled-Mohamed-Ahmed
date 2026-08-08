#include <stdio.h>

int main()
{
    double BasicSalary = 0.0;
    double HRA = 0.0;
    double DA = 0.0;
    double GrossSalary = 0.0;

    printf("Enter basic salary of an employee: ");
    scanf("%lf", &BasicSalary);

    if (BasicSalary <= 10000)
    {
        HRA = BasicSalary * 0.20;
        DA = BasicSalary * 0.80;
    }
    else if (BasicSalary <= 20000)
    {
        HRA = BasicSalary * 0.25;
        DA = BasicSalary * 0.90;
    }
    else
    {
        HRA = BasicSalary * 0.30;
        DA = BasicSalary * 0.95;
    }

    GrossSalary = BasicSalary + HRA + DA;

    printf("GROSS SALARY OF EMPLOYEE = %.2f\n", GrossSalary);

    return 0;
}