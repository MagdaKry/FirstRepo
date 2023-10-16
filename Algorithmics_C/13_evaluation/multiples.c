#include <stdio.h>

int main()
{

    int a = 5;
    int b = 50;

    int k = 6;

    for (int i = a; i <= b; i++)
    {

        if (i % k == 0)
        {
            printf("%d ", i);
        }
    }
}