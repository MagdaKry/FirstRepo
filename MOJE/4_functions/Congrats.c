#include <stdio.h>
#include <ctype.h>

void Congrats (float average, char gender);

int main(void){

    float average=0.34;
    char gender='w';
    
    printf ("Give your gender and average e.g. M:12.34 \n");
    scanf("%c:%f", &gender,&average);

    Congrats(average,gender);
}


void Congrats (float average, char gender)
{
    if (average>10)
    {
        if (toupper(gender) == 'M')
        {
            printf("Congratulations young man :-)");
        }
        else if (toupper(gender) == 'W')
        {
            printf("Congratulations Miss :-)");
         }
        else 
        {
            printf("Unknown character");
        }
    }
    else
    {
        printf(":-(");
    }
    
}