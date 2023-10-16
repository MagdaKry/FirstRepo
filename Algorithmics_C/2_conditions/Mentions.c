#include <stdio.h>
#include <stdbool.h>

int main()
{

    int average = 22;

    if (average >= 0 && average < 10)
    {
        printf("Failed");
    }
    else if (average >= 10 && average < 14)
    {
        printf("Fairly good");
    }
    else if (average >= 14 && average < 16)
    {
        printf("Good");
    }
    else if (average >= 16 && average <= 20)
    {
        printf("Very good");
    }
    else
    {
        printf("-");
    }

    return 0;
}