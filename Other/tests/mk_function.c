#include <stdio.h>

int sum(int a, int b);

int main()
{
    int a=0;
    int b=0;

    printf ("your numbers:\n");
    scanf ("%d %d", &a, &b);
    printf ("\n sum: %d (-1 = error)", sum(a,b));
}

int sum(int a, int b)
{
    if (a<0 || b<0)
    {
        printf ("\nnumber below 0\n");
        return -1;
    }
    else 
    {
        return a+b;
    }
}