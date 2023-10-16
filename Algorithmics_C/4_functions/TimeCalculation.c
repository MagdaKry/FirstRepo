// Write a function that computes a time in number of seconds from 3 given integer values hours, minutes and seconds.
#include<stdio.h>

int timeCalculation(int h, int m, int s);
int readInt(char t);
void timeSplit(int t);

int main()
{

    int hours=readInt('h');
    int minutes=readInt('m');
    int seconds=readInt('s');


    int result=timeCalculation(hours,minutes,seconds);
    printf("The time in seconds is:%d\n", result);

    timeSplit(result);

    return 0;
}

int timeCalculation(int h, int m,int s){

    int timeSeconds = h * 3600 + m * 60 + s;

 return timeSeconds;
}


int readInt(char t){

 printf("Give me an integer number for %c",t);

 int nb;
 scanf("%d", &nb);

 return nb;
}

void timeSplit(int t)
{

 int hours = t / 3600;
 int minutes = (t % 3600) / 60;
 int seconds = t - hours * 3600 - minutes * 60;

 printf("Hours:%d\nMinutes%d\nSeconds:%d", hours, minutes, seconds);
}
