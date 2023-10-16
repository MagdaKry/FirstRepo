#include <stdio.h>

int main(void){

    float average=16;
    
    if (average>=0 && average<10)
    {
        printf("Failed");
    }
    else if (average>12 && average <14)
    {
        printf("Fairly good");
    }
    else if (average>14 && average <16)
    {
        printf("Good");
    }
    else if (average>=16 && average <=20)
    {
        printf("Very good");
    }
    else
    {
        printf("-");
    }
    
}