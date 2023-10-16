#include <stdio.h>

int main(void){

    int number = 2;
    
    //printf("Type the number: \n"); 

    //scanf("%d", &number);
  
    if (number%2==0)
    {
        printf("Number %d is even\n", number);
    }
    else
    {
        printf("Number %d is odd\n", number);
    }
    
    return 0;
    
}