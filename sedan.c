#include<stdio.h>

void sedan_calculation(){

    float ID = 0.25;
    float VAT = 0.18;
    float WHT = 0.06;
    float IL = 150000;
    int CIF;

    //promting user to enter the CIF
    printf("\n\nEnter the CIF: ");
    scanf("%d", &CIF);

    ID *= CIF;
    VAT *= CIF;
    WHT *= CIF;
    printf("\nRequired to pay;");
    printf("\nImport Duty of %.2f", ID);
    printf("\nValue Added Tax of %.2f", VAT);
    printf("\nWithholding Tax of %.2f", WHT);
    printf("\nInfrastructure Levy of %.2f", IL);
    printf("\nMandatory to pay the SD, FF, ED");
    printf("\nThe vehicle fits a Digital Plate System at 700000");

    printf("\n\nNo taxes imposed on the seating capacity");

    //calculations and conditions that follow for the gross_weight
    int gross_weight;
    printf("\n\nEnter the gross weight(tons): ");
    scanf("%d", &gross_weight);

    float weight_cost = 0.0;
    if(gross_weight >= 1500 && gross_weight <= 2000){
    
        //10% of CIF
        weight_cost = 0.1 * CIF;
        printf("Required to pay %.2f", weight_cost);

    }else if(gross_weight > 2000){
        //15% of CIF
        weight_cost = 0.15 * CIF;
        printf("Required to pay %.2f", weight_cost);

    }else if(gross_weight < 1500){
        //2% of CIF
        weight_cost = 0.02 * CIF;
        printf("Required to pay %.2f", weight_cost);
    }else{
        printf("invalid input");
    }

    //calculations and conditions for engine capacity
    int engine_capacity;
    printf("\n\nEnter Engine capacity(CC): ");
    scanf("%d", &engine_capacity);

    float engine_cost = 0.0;
    if(engine_capacity > 2000){
        //10% of CIF
        engine_cost = 0.1 * CIF;
        printf("Required to pay %.2f", engine_cost);

    }else if(engine_capacity >= 1500 && engine_capacity <= 2000){
        //5% of the CIF
        engine_cost = 0.05 * CIF;
        printf("Required to pay %.2f", engine_cost);

    }else if(engine_capacity < 1500){
        //2.5% of the CIF
        engine_cost = 0.025 * CIF;
        printf("Required to pay %.2f", engine_cost);
    }else{
        printf("invalid input");
    }

    //calculations for the age of car and conditions
    int age, Y_O_M, current_year;
    printf("\n\nEnter Year of manufacturer: ");
    scanf("%d", &Y_O_M);
    printf("\nEnter current year: ");
    scanf("%d", &current_year);

    age = current_year - Y_O_M;
    float age_cost = 0.0;
    if(age > 15){
        printf("This vehicle cannot be imported into the country");
        
    }else if(age >= 10 && age <= 15){
        //10% of CIF on top of IL
        
        age_cost = 0.1 * CIF;
        age_cost += IL;
        printf("Required to pay %.2f", age_cost);

    }else if(age >= 5 && age <= 10){
        //5% of CIF on top of the IL
        
        age_cost = 0.05 * CIF;
        age_cost += IL;
        printf("\nRequired to pay %.2f", age_cost);

    }else if (age < 5){
      //1.5% of CIF on top of IL
      
      age_cost = 0.015 * CIF;
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
    float SD = 35000.0, FF = 20000.0, ED = 200000.0, DPS = 700000.0;
    float flat_amount = SD + FF + ED + DPS;
    total = ID + VAT + WHT + IL + weight_cost + age_cost + engine_cost + transportation_cost + x + flat_amount;    

    printf("\nID = %.2f", ID);
    printf("\nVat = %.2f", VAT);
    printf("\nWHT = %.2f", WHT);
    printf("\nIL = %.2f", IL);
    printf("\nweight cost = %.2f", weight_cost);
    printf("\nage cost = %.2f", age_cost);
    printf("\nEngine cost = %.2f", engine_cost);
    printf("\ntransport cost = %.2f", transportation_cost);
    printf("\nbond total = %.2f", x);
    printf("\nflat amount total = %.2f", flat_amount);

    printf("\n\nTotal taxes to be paid: %.2f", total);
}