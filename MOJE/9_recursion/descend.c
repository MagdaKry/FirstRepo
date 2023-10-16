#include <stdio.h>

void descend(int n);

int main(){ 
    int n=5;
    descend(n);
    return 0;
}

void descend(int n)
{
    /*
    if (n==1)
    {
        printf("%d", n);
    }
    */

    if (n==0)
    {
        return;
    }
    else
    {
        printf("%d ", n);
        descend(n-1);
    }
}