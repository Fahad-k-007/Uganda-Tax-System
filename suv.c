#include<stdio.h>

void suv_calculation(){

    float ID = 0.25;
    float VAT = 0.18;
    float WHT = 0.06;
    float IL = 150000;
    int CIF;
    //prompting user to enter the CIF
    printf("\nEnter the CIF: ");
    scanf("%d", &CIF);

    ID *= CIF;
    VAT *= CIF;
    WHT *= CIF;

    printf("\n\nRequired to pay;");
    printf("\nImport Duty of %.2f", ID);
    printf("\nValue Added Tax of %.2f", VAT);
    printf("\nWithholding Tax of %.2f", WHT);
    printf("\nInfrastructuer Levy at %.2f", IL);
    printf("\nRequired to fit an APS at 300000");
    printf("\nMandatory to pay SD, FF, ED");

    //calculate the seating capacity and conditions basing on the input
    int seating_capacity;
    printf("\n\nEnter Seating capacity: ");
    scanf("%d", &seating_capacity);

    float seating_cost = 0.0;
    if(seating_capacity > 5){
        seating_cost = 350000 * (seating_capacity - 5);
        printf("Required to pay an extra amount of %.2f", seating_cost);
    }else{
        printf("No extra charges imposed");
    }
    
    //calculating for gross weight and conditions based on input
    int gross_weight = 0.0;
    printf("\n\nEnter the gross weight(tons): ");
    scanf("%d", &gross_weight);

    float weight_cost = 0.0;
    if(gross_weight > 5000){
        //15% of the CIF 
    
        weight_cost = 0.15 * CIF;
        printf("Required to pay %.2f", weight_cost);

    }else if(gross_weight < 5000){
        printf("No costs to be paid");
    }else{
        printf("invalid input");
    }

    printf("\nNo taxes imposed on the Engine capacity");
    
    //calculation for the age of the car derived from the year of manufacturer and current yr
    int age, current_yr, Y_O_M;
    printf("\n\nEnter year of manufacturer: ");
    scanf("%d", &Y_O_M);
    printf("\nEnter current year: ");
    scanf("%d", &current_yr);
    age = current_yr - Y_O_M;

    float age_cost = 0.0;
    if(age >= 1 && age <= 5){
        //1% of the CIF to be paid on top of IL
        
        age_cost = 0.01 * CIF;
        age_cost += IL;
        printf("Required to pay %.2f", age_cost);
    }else if(age >= 5 && age <= 10){
        //15% of the CIF on top of IL to be paid
        
        age_cost = 0.15 * CIF;
        age_cost += IL;
        printf("Required to pay %.2f", age_cost);
    }else if(age > 10){
        //25% of the CIF on top of the IL
        age_cost = 0.25 * CIF;
        age_cost += IL;
        printf("Required to pay %.2f", age_cost);
    }else{
        printf("Invalid input");
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
    total = ID + VAT + WHT + IL + weight_cost + age_cost + transportation_cost + x + flat_amount;    

    printf("\n\nID = %.2f", ID);
    printf("\nVat = %.2f", VAT);
    printf("\nWHT = %.2f", WHT);
    printf("\nIL = %.2f", IL);
    printf("\nweight cost = %.2f", weight_cost);
    printf("\nage cost = %.2f", age_cost);
    printf("\ntransport cost = %.2f", transportation_cost);
    printf("\nbond total = %.2f", x);
    printf("\nflat amount total = %.2f", flat_amount);

    printf("\n\nTotal taxes to be paid: %.2f", total);    
}