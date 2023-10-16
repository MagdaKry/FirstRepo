#include <stdio.h>

int main(void){

    int n=9;
    //printf ("Give the number");
    //scanf("%d", &n);
    if (n>0)
    {
        for (int i=1; i<=n; i++)
        {
            for (int j=1; j<=i; j++)
            {
                printf ("*");
            }
        printf("\n");
        }
    }
}

/*
#include <stdio.h>

int main(void){

    int n=0;
    printf ("Give the number");
    scanf("%d", &n);

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=i; j++)
        {
            printf ("*");
        }
        printf("\n");
    }
    
}
*/