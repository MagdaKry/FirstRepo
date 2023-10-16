#include <stdio.h>

int main(void){

int n=11; //factorial of 8 is 40320, factorial of 11 is 39916800
int result=1;

if (n>0)
{   
    for (int i=n; i>1; i--)
    {
        result*=i;
    }
    
}

printf ("factorial of %d is %d", n, result);

}
