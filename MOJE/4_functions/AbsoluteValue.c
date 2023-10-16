#include <stdio.h>

int absoluteValue (int number);

int main(void){

    int number = -34;
    
    printf("Absolute value of your number is: %d \n", absoluteValue(number));
    
    return 0;
    
}

int absoluteValue (int number)
{
    int absolute=0;
  
    if (number>=0)
    {
        absolute=number;
    }
    else
    {
        absolute=number*(-1);
    }
    
    return absolute;
}