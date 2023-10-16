#include <stdio.h>

int factorialRecursif(int pNb)
{
    if (pNb == 0)
        return 1;
    else   
        return pNb * factorialRecursif(pNb - 1);
}

int main ()
{
    int factorial = factorialRecursif(5);
    printf("%d", factorial);
    return 0;
}