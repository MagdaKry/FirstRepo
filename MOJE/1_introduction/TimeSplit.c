#include <stdio.h>

int main(void){

    int total = 7465;
    int seconds = total%60; // rest - 25 seconds
    int minutesAll = (total-seconds)/60; // all - 124 minutes
    int minutesRest = minutesAll%60; // rest - 4 minutes
    int hours = (minutesAll-minutesRest)/60; // full 2 hours
    

    printf ("Hours: %d \n", hours);
    printf ("Minutes: %d \n", minutesRest);
    printf ("Seconds: %d \n", seconds);
    
    
}

/*
#include <stdio.h>

int main(void){

    int total = 7465; //7465;
    int seconds = total%60; // rest - 25 seconds
    int minutesRest = (total-seconds)/60%60; // full - 4 minutes
    int hours = total/3600; // full - 2 hours

    printf ("Hours: %d \n", hours);
    printf ("Minutes: %d \n", minutesRest);
    printf ("Seconds: %d \n", seconds);
      
}
*/