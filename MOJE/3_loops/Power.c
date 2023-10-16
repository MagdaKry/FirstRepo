#include <stdio.h>

int main(void){

int n=2;
int p=10;
int result=1;

for (int i=1; i<=p; i++)
{
    result*=n;
}
    
    printf ("%d to power %d is %d", n, p, result);
}