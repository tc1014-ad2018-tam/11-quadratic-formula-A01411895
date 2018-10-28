/*
 * Your program should:
 * Ask the user for the values of the three constants a, b and c.
 * Validate that a is never 0.
 * Validate that the values received are numeric.
 * Make sure that you are able to compute the square root.
 * If that is not possible, report that to the user.
 * Report the values for x (both values).
 * Make use of the standard library functions to solve this problem.
 */

//Libraries with all the necessary functions.
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Function that receives an array and compares its content to the ascii to figure out wetter the user
//gives us a number or any other value.
int isNumeric(char constant[]){
    for (int i = 0; i < strlen(constant); ++i) {
        if((constant[i]<48 || constant[i]>57) && constant[i] != 46 && constant[i] !=45){
            printf("Please only use numbers.\n\n");
            return 0;
        }
    }
    //Returns a 1 to break the do while loop in case the user only enters numbers.
    return 1;
}

//Functions that solves the quadratic formula from the received constants from the user.
//Has different result depending in the discriminator that is formed.
void quadraticFormula(double a, double b, double c){
    double d= (pow(b,2)-(4*a*c));

    if(d<0){
        printf("The are no results! No real numbers.");
    }
    if(d==0){
        printf("There is only 1 result:");
        double answer= (0-b)/(2*a);
        printf(" x= %lf", answer);
    }
    if(d>0){
        printf("There are 2 results:");
        double answerA= ((0-b)+d)/(2*a);
        double answerB= ((0-b)-d)/(2*a);
        printf(" x = %lf and x = %lf",answerA,answerB);
    }
};

int main() {

    //This variables are used to store the array the user gives us, check it with the function isNumeric and
    //transform it into a double.

    char constantA[10];
    double constantACheck;
    double constantAReal;

    char constantB[10];
    double constantBCheck;
    double constantBReal;

    char constantC[10];
    double constantCCheck;
    double constantCReal;

    printf("This program will help the user solve the quadratic formula.\n\n");

    do{
        //Ask the user for an array of numbers.
        printf("Give the the constant a of your polynomial:");
        //Save the array of numbers
        gets(constantA);
        constantACheck=isNumeric(constantA);

        //compares the array to a 0, and if its true, ask the user to not uses zeros and give another number.
        if(!strcmp(constantA, "0")){
            printf("Constant a cannot be 0! Try again.\n\n");
        }
    }while(constantACheck==0 || !strcmp(constantA, "0"));
    //Transform the array into double.
    constantAReal=atof(constantA);

    do{

        //Ask the user for an array of numbers.
        printf("Give the the constant b of your polynomial:");
        //Save the array of numbers
        gets(constantB);
        constantBCheck=isNumeric(constantB);
    }while(constantBCheck == 0);
    //Transform the array into double.
    constantBReal=atof(constantB);

    do{
        //Ask the user for an array of numbers.
        printf("Give the the constant c of your polynomial:");
        //Save the array of numbers
        gets(constantC);
        constantCCheck=isNumeric(constantC);
    }while(constantCCheck == 0);
    //Transform the array into double.
    constantCReal=atof(constantC);

    //Use the numbers that the user gave us, and use the quadratic formula to obtain the
    quadraticFormula(constantAReal, constantBReal, constantCReal);

    return 0;
}