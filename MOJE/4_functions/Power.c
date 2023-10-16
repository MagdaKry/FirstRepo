#include <stdio.h>

int power (int n, int p);

int main(void){

    int n=2;
    int p=10;

    printf ("%d to power %d is %d", n, p, power(n,p));
}

int power (int n, int p)
{
    int result=1;
    
    if (n>0 && p>0)
    {
       for (int i=1; i<=p; i++)
        {
            result*=n;
        } 
    }
    else
    {
        printf ("error\n");
        result=-1;
    }
    
    return result;
}