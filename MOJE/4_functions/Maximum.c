#include <stdio.h>

int maximum(int, int);

int main(void){

    int number1 = 12;
    int number2 = -13;

    printf("Maximum of %d and %d is %d \n", number1, number2, maximum(number1, number2));
    
    return 0;
    
}

int maximum(int n1, int n2){
    
    int max;
    
    if (n1<=n2)
    {
        max=n2;
    }
    else
    {
       max=n1;
    }
    
    return max;
}