#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{

    bool homme = false;

    int mark = 8;

    if (mark >= 10)
    {
        if (homme)
            printf("congrats mr");
        else
            printf("congrats lady");
    }
    else
    {
        printf("Hard luck :-(");
    }

    return 0;
}