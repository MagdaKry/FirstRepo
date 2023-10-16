#include <stdio.h>

int totals(int n);

int main ()
{
    int n = 6;
    int total = totals(n);
    printf("%d", total);
    return 0;
}

int totals(int n)
{
    if (n == 1)
        return 1;
    else   
        return n + totals(n - 1);
}