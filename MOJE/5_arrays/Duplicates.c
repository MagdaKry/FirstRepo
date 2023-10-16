#include <stdio.h>

int main(void){

    //int tab1[]={1, 2, 2, 3, 2, 4, 5};
    int tab1[]={-1, -1, 0, 0, -1, 0, -1, -1};
    
    int nb1 = sizeof(tab1)/sizeof(tab1[0]);
    
    int tabIndex[nb1];
    for (int i=0; i<nb1; i++)
    {
        tabIndex[i]=0;
    } 
    
    printf ("old array: ");
    
    for (int i=0; i<nb1; i++)
    {
        printf ("%d",tab1[i]);
    }
    
    for (int i=0; i<nb1; i++)
    {
        for (int j=i-1; j>=0; j--)
        {
            if (tab1[i]==tab1[j])
            {
                tabIndex[i]=1;
            }
        }
        
    } 
    
    printf ("\nindex array: ");
    
    for (int i=0; i<nb1; i++)
    {
        printf ("%d",tabIndex[i]);
    }
    
    int counter=0;
    
    for (int i=0; i<nb1; i++)
    {
        if (tabIndex[i]==1)
        counter+=1;
    }
    
    int tabNew[nb1-counter];
    int j=0;
    
    for (int i=0; i<nb1; i++)
    {
        if (tabIndex[i]!=1)
        {
            tabNew[j]=tab1[i];
            j++;
        }
    } 
    
    
    printf ("\nnew array: ");
    
    for (int i=0; i<nb1-counter; i++)
    {
        printf ("%d",tabNew[i]);
    }
}