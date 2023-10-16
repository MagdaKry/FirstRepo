#include <stdio.h>

void multiplicationTable(int n);

int main(void){

    int n=19;

    multiplicationTable(n);
    
}

void multiplicationTable(int n)
{
        for (int i=0; i<=10; i++)
    {
        printf ("%d x %d = %d\n", n, i, n*i);
    }
}