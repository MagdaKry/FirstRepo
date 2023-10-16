#include <stdio.h>

int main(void){

    int tab1[]={1,2,3,4,5};
    int n = 6;
    
    int nb = sizeof(tab1)/sizeof(tab1[0]);
    int tab2[nb+1];
    
    for (int i=0; i<nb; i++)
    {
        
        tab2[i]=tab1[i];
    }
    
    tab2[nb]=n;
    
    printf ("new array: ");
    
    for (int i=0; i<nb+1; i++)
    {
        printf ("%d",tab2[i]);
    }
}