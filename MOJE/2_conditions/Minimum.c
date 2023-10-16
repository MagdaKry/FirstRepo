#include <stdio.h>

int main(void){

    float number1 = 12.999;
    float number2 = -13.1;
    
    //printf("Type two numbers: \n"); 

    //scanf("%f %f", &number1, &number2);
  
    if (number1<number2)
    {
        printf("Number %g is smaller than %g\n", number1, number2);
    }
    else if (number2<number1)
    {
        printf("Number %g is smaller than %g\n", number2, number1);
    }
    else
    {
        printf("Numbers %g and %g are the same\n", number1, number2);
    }
    
    return 0;
    
}