#include<stdio.h>

void estate_calc(){

    float ID = 0.25;
    float VAT = 0.18;
    float WHT = 0.06;
    float IL = 150000.0;
    int seating_capacity;
    int CIF;
     

    printf("Enter the CIF: ");
    scanf("%d", &CIF);

    //calculating the ID, VAT, WHT, and IL
    printf("\nRequired to pay;");
    ID = ID * CIF;
    VAT = VAT * CIF;
    WHT = WHT * CIF;
    printf("\nImport Duty of %.2f", ID);
    printf("\nValue Added Tax of %.2f", VAT);
    printf("\nWithholding Tax of %.2f", WHT);
    printf("\nInfrastructure levy of %.2f", IL);
    printf("\nIt is Mandatory to pay SD, FF, ED");

    //plate selection
    int plate_type;
    printf("\n\nAllowed to Select the Plate System of choice;");
    printf("\n1. Digital Plate System");
    printf("\n2. Analoge Plate System");
    printf("\nEnter plate number: ");
    scanf("%d", &plate_type);

    float plate_calc = 0.0;
    switch (plate_type)
    {
    case 1:
    plate_calc = 300000;
        printf("Cost of Analoge Plate System is %.2f", plate_calc);
        break;
    case 2:
    plate_calc = 700000;
       printf("Cost of Digital Plate System is %.2f", plate_calc);
       break;
    default:
    printf("Only two plate types available.");
        break;
    }

    //calculating seating capacity and conditions to be met
    printf("\n\nEnter seating capacity: ");
    scanf("%d", &seating_capacity);

    float seating_cost = 0.0;
    if(seating_capacity > 5){
        
        seating_cost = 250000 * (seating_capacity - 5);
        printf("Required to pay an extra amount of %.2f", seating_cost);
    }else{
        printf("No extra costs incured");
    }

    //calculating the gross weight
    int gross_weight;
    printf("\n\nEnter the Gross weight(in tons): ");
    scanf("%d", &gross_weight);

    float weight_cost = 0.0;
    if(gross_weight >= 1500 && gross_weight <= 2000){
        
        weight_cost = 0.05 * CIF;
        printf("Required to pay %.2f of CIF value", weight_cost);

    }else if(gross_weight > 2000){
        
        weight_cost = 0.1 * CIF;
        printf("Required to pay %.2f of the CIF value", weight_cost);

    }else if(gross_weight < 1500){
        
        weight_cost = 0.02 * CIF;
        printf("Required to pay %.2f of the CIF value", weight_cost);
    }else{
        printf("Invalid");
    }
    
    //calculation for engine capacity
    int engine_capacity;
    printf("\n\nEnter Engine capacity(cc): ");
    scanf("%d", &engine_capacity);

    float engine_cost = 0.0;
    if(engine_capacity > 1800){
        
        engine_cost = 0.05 * CIF;
        printf("Required to pay %.2f", engine_cost);
    }else if(engine_capacity < 1800){
        
        engine_capacity = 0.025 * CIF;
        printf("Required to pay %.2f", engine_cost);
    }else{
        printf("invalid input");
    }

    //calculating age of the car
    int age, current_year, a;
    printf("\n\nEnter year of manufacturer: ");
    scanf("%d", &a);
    printf("\nEnter current year: ");
    scanf("%d", &current_year);

    float age_cost = 0.0;
    age = current_year - a;
    if(age >= 1 && age <= 5){
        age_cost = 0.01 * CIF;
        //payment of 1% of CIF on top of the IL
        age_cost += IL;
        printf("Required to pay a total of %.2f", age_cost);

    }else if(age >= 5 && age <= 10){
        age_cost = 0.05 * CIF;
        age_cost += IL;
        printf("Required to pay a total of %.2f ", age_cost);

    }else if(age > 10){
        
        age_cost = 0.15 * CIF;
        age_cost += IL;
        printf("Required to pay a total of %.2f", age_cost);

    }else{
        printf("Invalid");
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
    float SD = 35000.0, FF = 20000.0, ED = 200000.0;
    float flat_amount = SD + FF + ED;
    total = ID + VAT + WHT + IL + plate_calc + seating_cost + weight_cost + age_cost + engine_cost + transportation_cost + x + flat_amount;

    printf("\nID = %.2f", ID);
    printf("\nVat = %.2f", VAT);
    printf("\nWHT = %.2f", WHT);
    printf("\nIL = %.2f", IL);
    printf("\nplate total = %.2f", plate_calc);
    printf("\nseating cost = %.2f", seating_cost);
    printf("\nweight cost = %.2f", weight_cost);
    printf("\nage cost = %.2f", age_cost);
    printf("\nEngine cost = %.2f", engine_cost);
    printf("\ntransport cost = %.2f", transportation_cost);
    printf("\nbond total = %.2f", x);
    printf("\nflat amount total = %.2f", flat_amount);
    
    printf("\n\nTotal taxes to be paid: %.2f", total);
}