#include <stdio.h>

int main(void){

    int tab1[]={1,2,3,4,5};
    int tab2[]={6,7,8,9};
    
    int nb1 = sizeof(tab1)/sizeof(tab1[0]);
    int nb2 = sizeof(tab2)/sizeof(tab2[0]);
    
    int tab3[nb1+nb2];
    
    for (int i=0; i<nb1; i++)
    {
        tab3[i]=tab1[i];
    }

    for (int i=0; i<nb2; i++)
    {
        tab3[i+nb1]=tab2[i];
    }
    
    printf ("new array: ");
    
    for (int i=0; i<nb1+nb2; i++)
    {
        printf ("%d",tab3[i]);
    }
}