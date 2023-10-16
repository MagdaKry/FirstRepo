#include <stdbool.h>
#include <stdio.h>

bool isOdd (int number);

int main(void){

    int number = 3;
    
    //printf("Type the number: \n"); 

    //scanf("%d", &number);
  
    if (!isOdd(number))
    {
        printf("Number %d is even\n", number);
    }
    else
    {
        printf("Number %d is odd\n", number);
    }
    
    return 0;
    
}

bool isOdd (int number)
{
    bool flag = 0;
    
    if (number%2==0)
    {
        flag = 0;
    }
    else
    {
        flag = 1;
    }
    
    return flag;
}