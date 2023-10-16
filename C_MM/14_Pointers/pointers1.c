#include <stdio.h>

void main(){
    int a = 4;
    int *p = &a;
    printf("a = %d\n", a);
    printf("&a = %d\n", &a);
    printf("p = %d\n", p);
    printf("p+1 = %d\n", p+1);
    printf("&p = %d\n", &p);
    printf("*p = %d\n", *p);
}