#include <stdio.h>


int main(void){

    int tab[]={1,2,3,4,5};
    
    int n = sizeof(tab)/sizeof(tab[0]);
    //printf ("%d", n);
    
    for (int i=n-1; i>=0; i--)
    //for (int i=0; i<n; i++)
    {
        printf ("%d", tab[i]);
    }

}