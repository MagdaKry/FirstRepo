#include <stdio.h>

void ascend(int n);

int main(){ 
    int n=5;
    ascend(n);
    return 0;
}

void ascend(int n)
{
    if (n==0)
    {
        return;
    }
    ascend(n-1);
    printf("%d ", n);
      
}