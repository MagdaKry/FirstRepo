#include <stdio.h>

int main(void){

    /*
    for (int i=0; i<10; i++)
    {
        printf("loop %d\n", i);
    }
    for (int i=9; i>=0; i--)
    {
        printf("loop %d\n", i);
    }
    */

    int sum=0;
    for (int i=0; i<10; i++)
    {
        sum+=i;
        printf("sum is %d\n", sum);
    }

    return 0;
}