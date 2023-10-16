#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main()
{
    srand(time(NULL));
    int random_int=rand()%100+1;
    printf("%d", random_int); 

    int guess=-1;
    bool end=false;
    int noOfGuesses = 0;

    printf("\n-----GAME-----\n");
    while(end!=true && noOfGuesses<10)
    {
        printf("Give me number between 1 and 100\n");
        scanf("%d", &guess);
        noOfGuesses++;

        if(guess>100 || guess<1)
        {
            printf("Your number exceeded the limit (1..100). Next trial!\n");
            continue;
        }

        if (guess==random_int)
        {
            printf("Correct!\n");
            end=true;
        }
        else if(guess>random_int)
        {
            printf("Too high!\n");
        }
        else if (guess<random_int)
        {
            printf("Too low!\n");
        }
    }
    
    if(end==true)
    {
        printf("Congratulation!!!\nYour guess is correct: %d. You tried %d times.", guess, noOfGuesses);  
    }
    else if (end==false && noOfGuesses==10)
    {
        printf("END! You are run out of your 10 trials. The number is %d.", random_int); 
    }
     
}