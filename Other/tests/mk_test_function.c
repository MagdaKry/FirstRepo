
#include <stdio.h>

float minimum(float, float);

int main(void){

    float number1 = 12.999;
    float number2 = -13.1;

    printf("Minimum of %g and %g is %g \n", number1, number2, minimum(number1, number2));
    
    return 0;
    
}

float minimum(float n1, float n2){
    
    float min;
    
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