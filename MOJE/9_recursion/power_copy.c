#include <stdio.h>

float power(float n, int p);

int main ()
{
    float n=0;
    int p=0;

    printf("Give me numbers:\n");
    scanf("%f %d", &n, &p);
    
   // float n = 2;
   // int p = -2;

    float result = power(n,p);

    printf("%f to %d power is: %f", n,p,result);

    return 0;
}

float power(float n, int p)
{
    float result = 0;
    if (p == 0)
    {
        result= 1;
    }
    else if (p<0)
    {
        result= (1/n) * power(n, p + 1);
    }
    else 
    {
        result= n * power(n, p - 1);
    }  
        

        return result;
}