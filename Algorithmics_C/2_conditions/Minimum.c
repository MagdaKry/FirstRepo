#include <stdio.h>
#include <stdlib.h>

int main()
{

    int n1 = 3;
    int n2 = 5;

    if (n1 < n2)
        printf("The minimum between %d and %d is %d", n1, n2, n1);
    else if (n2 < n1)
        printf("The minimum between %d and %d is %d", n1, n2, n2);
    else
        printf("%d and %d are equals", n1, n2);

    return 0;
}