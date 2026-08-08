#include <stdio.h>

int main()
{
    unsigned int CostPrice = 0;
    unsigned int SellingPrice = 0;

    printf("Enter cost price: ");
    scanf("%u", &CostPrice);

    printf("Enter selling price: ");
    scanf("%u", &SellingPrice);

    if (SellingPrice > CostPrice)
    {
        printf("Profit = %u\n", SellingPrice - CostPrice);
    }
    else if (CostPrice > SellingPrice)
    {
        printf("Loss = %u\n", CostPrice - SellingPrice);
    }
    else
    {
        printf("No profit no loss.\n");
    }

    return 0;
}