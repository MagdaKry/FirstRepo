#include<stdio.h>
#include<stdlib.h>

int main(){

int time= 3750;


    int hours= time/3600;
    int minutes= (time%3600)/60;
    int seconds= time-hours*3600-minutes*60;
    printf("%d\n", minutes);
    printf("Hours:%d\nminutes:%d\nseconds:%d\n",hours,minutes,seconds);

    return 0;
}