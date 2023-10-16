#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n = -5;

    if (n >= 0)
        printf("The absolute value of %d is %d", n, n);
    else
        printf("The absolute value of %d is %d", n, -n);

    return 0;
}