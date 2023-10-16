#include <stdio.h>

int main(void){

    float number = -34;
    
    printf("Type the number: \n"); 

    scanf("%f", &number);
  
    if (number>=0)
    {
        printf("Absolute value of your number is: %f \n", number);
    }
    else
    {
        printf("Absolute value of your number is: %f \n", number*=-1);
    }
    
    return 0;
    
}