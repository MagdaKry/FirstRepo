#include<stdio.h>

void timeSplit(int t);

int main()
{

    int time = 3661;

    timeSplit(time);

    /*  int hours = time / 3600;
      int minutes = (time % 3600) / 60;
      int seconds = time - hours * 3600 - minutes * 60;*/
}

void timeSplit(int t){

    int hours = t / 3600;
    int minutes = (t % 3600) / 60;
    int seconds = t - hours * 3600 - minutes * 60;

    printf("Hours:%d\nMinutes%d\nSeconds:%d", hours, minutes, seconds);
}

