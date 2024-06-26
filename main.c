#include"vehicle_info.c"
#include"vehicles.c"
#include"ambulance.c"
#include"estate.c"
#include"sedan.c"
#include"suv.c"
#include"trailer.c"
#include"others.c"
#include<stdio.h>


int main(){
    //vehicle_info will print out the vehicles, specifications and the tax rates
    vehicleInfo();

    /*We declare the info variable that will capture the user input*/
    int info;
    printf("\nSelect vehicle number: ");
    scanf("%d", &info);

    /*We declare another function func_return assigned with NULL that will fetch the vehicle number file by 
    returning the address of the selected number by the user*/
    void (*func_return)() = NULL;

    /*We perform conditions on user input using a switch statement, within the case
    the func_return is assigned to a file and basing on input the selected vehicle
    will be fetched hence using the return 1 at the end of the switch*/
    switch (info)
    {
    case 1:
       func_return = ambulance_calc;
        break;
    
    case 2:
    func_return = estate_calc;
    break;

    case 3:
    func_return = sedan_calculation;
    break;

    case 4:
    func_return = suv_calculation;
    break;

    case 5:
    func_return = trailer_calculation;
    break;
    
    case 6:
    func_return = others;
    break;
    default:
    printf("Invalid input!! Enter a number from 1 to 6 depending on the type of vehichle to be imported");
        break;
        return 1;
}

/*when the func_return function is not NULL we call it which is assigned to
the files to produce the output from our system*/
if(func_return != NULL){
    func_return();
}
return 0;
}