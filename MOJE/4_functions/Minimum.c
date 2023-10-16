#include <stdio.h>

int minimum(int, int);

int main(void){

    int number1 = 12;
    int number2 = -13;

    printf("Minimum of %d and %d is %d \n", number1, number2, minimum(number1, number2));
    
    return 0;
    
}

int minimum(int n1, int n2){
    
    int min;
    
    if (n1<=n2)
    {
        min=n1;
    }
    else
    {
       min=n2;
    }
    
    return min;
}