#include <stdio.h>

int main(void){

    int tab[]={1,2,3,4,5};
    //int n = 3;
    int n = 6;
    
    int nb = sizeof(tab)/sizeof(tab[0]);
    
    int i=0;
    
    for (i=0; i<nb; i++)
    {
        if (tab[i]==n)
        {
            printf ("first position of number %d is %d (index %d)", n, i+1, i);
            break;
        }
    }
    if (i==nb)
    {
        printf ("first position of number %d is %d (not found)", n, -1);
    }
}