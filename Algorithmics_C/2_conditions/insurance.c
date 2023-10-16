#include <stdio.h>

int main()
{

    float amount = 4000;

    float deduct = amount * 0.1;

    if (deduct < 10)
    {
        deduct = 10;
    }
    else if (deduct > 500)
    {
        deduct = 500;
    }

    printf("The deductible is equal to %g", deduct);
}