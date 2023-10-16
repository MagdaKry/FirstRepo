#include <stdio.h>

int power(int n, int p);

int main ()
{
    int n = 3;
    int p = 4;
    int result = power(n,p);
    printf("%d to %d power is: %d", n,p,result);
    return 0;
}

int power(int n, int p)
{
    if (p == 0)
        return 1;
    else   
        return n * power(n, p - 1);
}