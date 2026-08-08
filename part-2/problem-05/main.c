#include <stdio.h>

int main()
{
    unsigned int CustomerNumber = 0;
    unsigned int UnitsConsumed = 0;
    double Charges = 0.0;

    printf("Enter CUSTOMER NO. and UNITS consumed\n");
    scanf("%u", &CustomerNumber);
    scanf("%u", &UnitsConsumed);

    if (UnitsConsumed <= 200)
    {
        Charges = UnitsConsumed * 0.50;
    }
    else if (UnitsConsumed <= 400)
    {
        Charges = 100.0 + (UnitsConsumed - 200) * 0.65;
    }
    else if (UnitsConsumed <= 600)
    {
        Charges = 230.0 + (UnitsConsumed - 400) * 0.80;
    }
    else
    {
        Charges = 390.0 + (UnitsConsumed - 600) * 1.00;
    }

    printf("Customer No: %u:\n", CustomerNumber);
    printf("Charges = %.2f\n", Charges);

    return 0;
}