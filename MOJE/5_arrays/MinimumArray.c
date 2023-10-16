#include <stdio.h>

int main(void){

    int tab[]={4,2,3,1,5};
    
    int n = sizeof(tab)/sizeof(tab[0]);
    //printf ("%d", n);
    
    int min = tab[0];
    
    //for (int i=n-1; i>=0; i--)
    for (int i=0; i<n; i++)
    {
        if (i>0)
        {
            if (tab[i]<tab[i-1])
            {
                min = tab[i];
            }
            
        }
            
    }

    printf ("min: %d", min);

    
}