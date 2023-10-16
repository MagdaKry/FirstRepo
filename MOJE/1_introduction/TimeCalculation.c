#include <stdio.h>

int main(void){

    int hours = 2;
    int minutes = 4;
    int seconds = 25;

    int total = seconds + 60 * minutes + 60 * 60 * hours;

    printf ("Total time in seconds: %d", total);
    
}