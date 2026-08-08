#include <stdio.h>

int main()
{
    unsigned int UnitsConsumed = 0;
    double ElectricityBill = 0.0;

    printf("Enter total units consumed: ");
    scanf("%u", &UnitsConsumed);

    if (UnitsConsumed <= 50)
    {
        ElectricityBill = UnitsConsumed * 0.50;
    }
    else if (UnitsConsumed <= 150)
    {
        ElectricityBill = UnitsConsumed * 0.75;
    }
    else if (UnitsConsumed <= 250)
    {
        ElectricityBill = UnitsConsumed * 1.20;
    }
    else
    {
        ElectricityBill = UnitsConsumed * 1.50;
    }

    ElectricityBill = ElectricityBill + (ElectricityBill * 0.20);

    printf("Electricity Bill = Rs. %.2f\n", ElectricityBill);

    return 0;
}