#include<stdio.h>
#include<stdlib.h>

int total;

int square(int x)
{
    return x*x; 
}
int SquareOfSum(int x, int y)
{
    int z = square(x+y);
    return z;
}
int main()
{
    int a = 4, b = 8,
    total = SquareOfSum(a,b);
    printf("Output = %d\n" ,total);
}