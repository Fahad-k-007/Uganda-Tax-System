#include<stdio.h>
#include<string.h>

void vehicleInfo(){

   char info[6][35] = {"1. Ambulance", "2. Estate", "3. Sedan", "4. Sports Utility Vehicle(SUV)", "5. Trailer", "6. Trailer"};

    printf("List of Vehicles\n");
    for(int i = 0; i<5; i++){
        puts(info[i]);
    }

    char specification[5][45] = {"1. Cost Insuarance Freight(CIF)", "2. Seating capacity", "3. Gross Weight(Tons)", "4. Engine capacity(CC)", "5. Age of the Car"};
    
    printf("\n");
    printf("Specifications\n");
    for(int j = 0; j < 5; j++){
        puts(specification[j]);
    }

char taxes[10][90] = {"1. Import Duty (ID) = 25% of the CIF ", 
"2. Value Added Tax (VAT) = 18% of the CIF",
"3. Withholding Tax (WHT) = 6% of the CIF",
"4. Infrastructure Levy (IL) = This is a flat amount of 150,000",
"5. Stamp Duty (SD) = This is a flat amount of 35,000",
"6. Form Fees (FF) = This is a flat amount of 20,000",
"7. Excise Duty (ED) = This is a flat amount of 200,000",
"8. Registration(R) = Determined by the type of number plate system issued to the vehicle",
"i)Analog Plate System = flate amount of 300,000",
"ii)Digital Plate System = flat amount 700,000"};

printf("\n");
printf("Tax Rates are as follows;\n");
for(int x = 0; x < 10; x++){
    puts(taxes[x]);
}

}
