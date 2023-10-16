#include <stdio.h>

void timeSplit(int total);

int main(void){

    int secondsGiven = 7465;
    timeSplit(secondsGiven);
    
}

void timeSplit(int total)
{
    int seconds = total%60; // rest - 25 seconds
    int minutesRest = (total-seconds)/60%60; // full - 4 minutes
    int hours = total/3600; // full - 2 hours

    printf ("Hours: %d \n", hours);
    printf ("Minutes: %d \n", minutesRest);
    printf ("Seconds: %d \n", seconds);
}