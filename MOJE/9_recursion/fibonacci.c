#include <stdio.h>

int fibonacci(int n);

int main ()
{
    int n = 19; //fibonacci(19)=4181
    int result = fibonacci(n);
    printf("fibonacci(%d)=%d", n, result);
    return 0;
}

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    else if (n==1)
        return 1;
    else  
        return fibonacci(n-1) + fibonacci(n-2);
}


