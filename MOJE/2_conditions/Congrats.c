#include <stdio.h>
#include <ctype.h>

int main(void){

    float average=12.34;
    char gender='M';
    
    printf ("Give your gender and average e.g. M:12.34 \n");
    scanf("%c:%f", &gender,&average);
    
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