#include <stdio.h>
void main()
{
    int a = 10;
    int *p;
    p = &a;
    printf("p = %d\n", p);
    printf("p+1 = %d\n", p+1);

    char c;
    char *p1;
    p1 = &c;
    printf("p1 = %d\n", p1);
    printf("p1+1 = %d\n", p1+1);
}