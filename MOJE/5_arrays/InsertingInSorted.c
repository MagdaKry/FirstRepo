#include <stdio.h>

int main(void){
    
    int n = 1;
    //int tab1[]={2,3,4,5};
    //int tab1[]={1,3,4,5};
    //int tab1[]={1,2,4,5};
    //int tab1[]={1,2,3,5};
    //int tab1[]={1,2,3,4};

    //int tab1[]={4,3,2,1};
    //int tab1[]={5,3,2,1};
    //int tab1[]={5,4,2,1};
    //int tab1[]={5,4,3,1};
    int tab1[]={5,4,3,2};
    
    int nb1 = sizeof(tab1)/sizeof(tab1[0]);
    
    printf ("old array: ");
    
    for (int i=0; i<nb1; i++)
    {
        printf ("%d",tab1[i]);
    }
    
    int tab2[nb1+1];
    
    int j=0;
    
    if (tab1[0]<tab1[1])
    {
        //ascending
        for (int i=0; i<(nb1+1); i++)
        {
        
        if (i==0 && n<tab1[0])
        {
            tab2[0]=n;
            j--;
        }
        else if (i<nb1 && i>0 && n<tab1[j] && n>tab1[j-1] && tab2[i-1]!=n)
        {
            tab2[i]=n;
            j--;
        }
        else if (i==nb1 && n>tab1[j-1] && tab2[i-1]!=n)
        {
            tab2[i]=n;
            j--;
        }
        else
        {
            tab2[i]=tab1[j];
        }
            j++;
        }
    }
    else
    {
        //descending
        for (int i=0; i<(nb1+1); i++)
        {
        
        if (i==0 && n>tab1[0])
        {
            tab2[0]=n;
            j--;
        }
        else if (i<nb1 && i>0 && n>tab1[j] && n<tab1[j-1] && tab2[i-1]!=n)
        {
            tab2[i]=n;
            j--;
        }
        else if (i==nb1 && n<tab1[j-1] && tab2[i-1]!=n)
        {
            tab2[i]=n;
            j--;
        }
        else
        {
            tab2[i]=tab1[j];
        }
            j++;
        }
    }
    
    
    
    
    printf ("\nnew array: ");
    
    for (int i=0; i<nb1+1; i++)
    {
        printf ("%d",tab2[i]);
    }
    
}