#include<stdio.h>




int main(){

    int pNb = 5;

    for (int i = 0; i <= 10; i++)
    {
        printf("%d * %d = %d\n", pNb, i, pNb * i);
    }
    
    return 0;
}