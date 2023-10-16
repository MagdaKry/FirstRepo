#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>

const int MAX=100;
const int MIN=1;

int rand_int(int max, int min);
bool check(int rand_i, int guess);

int main()
{
    
    int random_int=rand_int(100,1);
    printf("%d", random_int); 

    int guess=-1;
    bool end=false;
    int noOfGuesses = 0;

    printf("\n-----GAME-----\n");
    while(end!=true && noOfGuesses<10)
    {
        printf("Give me number between 1 and 100\n");
        scanf("%d", &guess);
        end=check(random_int,guess);
        noOfGuesses++;
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

int rand_int(int max, int min)
{
    srand(time(NULL));
    return rand()%(max-min+1)+min;
}

bool check(int rand_i, int guess)
{
        if(guess>100 || guess<1)
        {
            printf("Your number exceeded the limit (1..100). Next trial!\n");
            return false;
        }

        if (guess==rand_i)
        {
            printf("Correct!\n");
            return true;
        }
        else if(guess>rand_i)
        {
            printf("Too high!\n");
            return false;
        }
        else if (guess<rand_i)
        {
            printf("Too low!\n");
            return false;
        }
}