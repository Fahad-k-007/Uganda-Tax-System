#include<stdio.h>

void others(){

    float ID = 0.25;
    float VAT = 0.18;
    float WHT = 0.06;
    int CIF;

    printf("\n\nEnter the CIF of the vehicle: ");
    scanf("%d", &CIF);

    ID *= CIF;
    VAT *= CIF;
    WHT *= CIF;

    //payment list to be paid the importer
    printf("\nRequired to pay the standard taxes below;");
    printf("\nImport Duty of %.2f", ID);
    printf("\nValue Added Tax of %.2f", VAT);
    printf("\nWithholding tax %.2f", WHT);
    printf("\nMandatory to pay SD, FF, ED");
    printf("\nRequired to fit an APS or DPS");

    //determining the mode of transportation and taxes to be imposed
    int mode;
    printf("\n\nSelect the mode of transportation for the vehicle (Enter 1 or 2)");
    printf("\n1. Carrier bed");
    printf("\n2. Driven in the country");
    printf("\nEnter number: ");
    scanf("%d", &mode);

    float i = 0.0;
    switch (mode)
    {
    case 1:
    //0.5% payment of the CIF of its value for Road tolls
    i = 0.005 * CIF;
    printf("Required to pay %.2f for Road tolls", i);
        break;
    case 2:
    //1.5% of the CIF
    i = 0.015 * CIF;
    printf("Required to pay %.2f boarder fee", i);
    break;

    default:
    printf("Invalid input");
        break;
    }

    //calculating amount to be paid basing on the days a vehicle spends in bond
    int bond = 15000;
    int days, x;
    printf("\n\nDays for the vehicle spent in bond: ");
    scanf("%d", &days);

    x = days * bond;
    printf("\nTotal parking fee: %d", x);

    float total;
    total = ID + VAT + WHT + i + x;
    printf("\nTotal taxes to be paid: %.2f", total);
}