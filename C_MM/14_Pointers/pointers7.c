#include <stdio.h>
int main()
{
    int a = 1025;
    int *p;
    p = &a;
    printf("Size of integer is %d\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);

    char *p1;
    p1 = (char*)p; // type casting
    printf("Size of char is %d\n", sizeof(char));
    printf("Address = %d, value = %d\n", p1, *(p1+1));
}