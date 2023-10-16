#include <stdio.h>

int timeCalculation (int h, int m, int s);

int main(void){

    int hours = 2;
    int minutes = 4;
    int seconds = 25;

    printf ("Total time in seconds: %d", timeCalculation(hours, minutes, seconds));
    
}

int timeCalculation (int h, int m, int s)
{
    int total = s + 60 * m + 60 * 60 * h;
    return total;
}