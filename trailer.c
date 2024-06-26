#include<stdio.h>

void trailer_calculation(){

    float ID = 0.25;
    float VAT = 0.18;
    float WHT = 0.06;
    float IL = 150000.0;
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
    printf("\nInfrastructuer Levy of %.2f", IL);
    printf("\nMandatory to pay SD, FF, ED");

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

    printf("\n\nNo taxes imposed on the seating capacity");

    //calculating for gross weight and conditions basing on input
    int gross_weight;
    printf("\n\nEnter the gross weight(tons): ");
    scanf("%d", &gross_weight);

    float weight_cost = 0.0;
    if(gross_weight >= 15000 && gross_weight <= 20000){
        //15% payment of the CIF
        
        weight_cost = 0.15 * CIF;
        printf("Required to pay %.2f", weight_cost);

    }else if(gross_weight > 20000){
        //25% payment of CIF
        weight_cost = 0.25 * CIF;
        printf("Required to pay %.2f", weight_cost);

    }else if(gross_weight < 15000){
        //5% payment of the CIF
        weight_cost = 0.05 * CIF;
        printf("Required to pay %.2f", weight_cost);
    }else{
        printf("Invalid input");
    }

    //calculations for engine capacity and conditions
    int engine_capacity;
    printf("\n\nEnter engine capacity(cc): ");
    scanf("%d", &engine_capacity);

    float engine_cost = 0.0;
    if(engine_capacity > 20000){
        //10% of cif payment required to pay
        engine_cost = 0.1 * CIF;
        printf("Required to pay %.2f", engine_cost);

    }else if(engine_capacity >= 15000 && engine_capacity <= 20000){
    
        engine_cost = 0.05 * CIF;
        printf("Required to pay %.2f", engine_cost);

    }else if(engine_capacity < 15000){
        //2.5% of CIF payment required
        engine_cost = 0.025 * CIF;
        printf("Required to pay %.2f", engine_cost);
    }else{
        printf("Invalid input");
    }

    //calculation for the age of the car derived from year of manufacturer and conditions 
    int age, current_yr, Y_O_M;
    printf("\n\nEnter year of manufacturer: ");
    scanf("%d", &Y_O_M);
    printf("\nEnter current year: ");
    scanf("%d", &current_yr);

    float age_cost = 0.0;
    age = current_yr - Y_O_M;
    if(age > 15){
        printf("The vehicle can not be imported in to the country.");
    }else if(age >= 10 && age <=15){
        //10% payment of cif on top of IL
        age_cost = 0.1 * CIF;
        age_cost += IL;
        printf("Required to pay %.2f", age_cost);
        
        }else if(age >= 5 && age <= 10){
        //5% payment of cif on top of IL
        
        age_cost = 0.05 * CIF;
        age_cost += IL;
        printf("Required to pay %.2f", age_cost);
        }else if(age < 5){
        //1.5% payment of the cif on top of IL
        
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
    float SD = 35000.0, FF = 20000.0, ED = 200000.0;
    float flat_amount = SD + FF + ED;
    total = ID + VAT + WHT + IL + plate_calc + weight_cost + age_cost + engine_cost + transportation_cost + x + flat_amount;

    printf("\n\nID = %.2f", ID);
    printf("\nVat = %.2f", VAT);
    printf("\nWHT = %.2f", WHT);
    printf("\nIL = %.2f", IL);
    printf("\nplate total = %.2f", plate_calc);
    printf("\nweight cost = %.2f", weight_cost);
    printf("\nage cost = %.2f", age_cost);
    printf("\nEngine cost = %.2f", engine_cost);
    printf("\ntransport cost = %.2f", transportation_cost);
    printf("\nbond total = %.2f", x);
    printf("\nflat amount total = %.2f", flat_amount);
    
    printf("\n\nTotal taxes to be paid: %.2f", total);
}