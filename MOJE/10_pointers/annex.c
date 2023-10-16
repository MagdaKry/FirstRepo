#include <stdlib.h>
#include <stdio.h>

int main(){
    int a = 15;
    printf("adress of a : %p\n", &a);

    int x[5] = {10, 15, 20, 25, 30};
    int *ptr = x;
    printf("&ptr = %p\n", &ptr);
    printf("*ptr = %p\n", ptr);
    printf("address x = %p\n", &x[0]);
    printf("address y = %p\n", &x[1]);
    printf("address y = %p\n", &x[2]);
    printf("address y = %p\n", &x[3]);
    printf("address y = %p\n", &x[4]);

    printf("ptr = %x\n", ptr);
    printf("ptr = %d\n", *ptr);

    ptr = ptr + 3;
    printf("ptr = %x\n", ptr);
    printf("ptr = %d\n", *ptr);

    return 0;
}
