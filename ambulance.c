#include<stdio.h>

void ambulance_calc(){
    printf("\nExempted from paying ID, VAT, and WHT");
    printf("\nMandatory to pay SD, FF and ED");
    printf("\nA Digital Plate System is to be issued at 300000");

    int a, Y_O_M, current_year;
    int CIF;
    float IL = 150000;

    printf("\n\nEnter CIF: ");
    scanf("%d", &CIF);

    printf("\nEnter year of manufacturer: ");
    scanf("%d", &Y_O_M);

    printf("\nEnter current year: ");
    scanf("%d", &current_year);

    a = current_year - Y_O_M;
    if(a > 10){
        //payment of the IL at 15% of the CIF 
        float a;
        a = 0.15 * CIF;
        IL += a;
        printf("Required to pay %.2f of CIF", IL);
    }else{
        int I_levy = 150000;
        printf("Required to pay flat amount of %d", I_levy);
    }

    //determining the mode of transportation and taxes to be imposed
    int mode;
    printf("\n\nSelect the mode of transportation for the vehicle (Enter 1 or 2)");
    printf("\n1. Carrier bed");
    printf("\n2. Driven in the country");
    printf("\nEnter number: ");
    scanf("%d", &mode);

    float transportation_cost = 0.0;
    switch (mode)
    {
    case 1:
    //0.5% payment of the CIF of its value for Road tolls
    transportation_cost = 0.005 * CIF;
    printf("Required to pay %.2f for Road tolls", transportation_cost);
        break;
    case 2:
    //1.5% of the CIF
    transportation_cost = 0.015 * CIF;
    printf("Required to pay %.2f boarder fee", transportation_cost);
    break;

    default:
    printf("Invalid input");
        break;
    }

    //calculating amount to be paid basing on the days a vehicle spends in bond
    float bond = 15000.0;
    int days;
    float x;
    printf("\n\nDays for the vehicle spent in bond: ");
    scanf("%d", &days);

    x = days * bond;
    printf("\nTotal parking fee: %.2f", x);

    float total;
    float SD = 35000.0, FF = 20000.0, ED = 200000.0, APS = 300000.0;
    float flat_amount = SD + FF + ED + APS;
    total = transportation_cost + x + flat_amount;

    printf("\n\nIL = %.2f", IL);
    printf("\ntransport cost = %.2f", transportation_cost);
    printf("\nbond total = %.2f", x);
    printf("\nflat amount total = %.2f", flat_amount);
    
    printf("\n\nTotal taxes to be paid: %.2f", total);
}
