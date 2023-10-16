#include <stdbool.h>
#include <stdio.h>

int main(void){

    //ascending
    //int tabA[]={4,2,3,1,5};
    int tabA[]={1,2,3,4,5};
    bool flagA=false;
    
    int nA = sizeof(tabA)/sizeof(tabA[0]);
    //printf ("%d", n);
    
    //for (int i=n-1; i>=0; i--)

    for (int i=0; i<nA; i++)
    {
        if (i>0)
        {
            if (tabA[i]<tabA[i-1])
            {
                flagA = true;
                break;
            }
        }
    }

    if (flagA == false)
    {
        printf ("ascending sorted\n");
    }
    else
    {
        printf ("ascending not sorted\n");
    }
    

    //descending
    //int tabD[]={4,2,3,1,5};
    int tabD[]={5,4,3,2,1};
    bool flagD=false;
    
    int nD = sizeof(tabD)/sizeof(tabD[0]);
    //printf ("%d", n);
    
    //for (int i=n-1; i>=0; i--)

    for (int i=0; i<nD; i++)
    {
        if (i>0)
        {
            if (tabD[i]>tabD[i-1])
            {
                flagD = true;
                break;
            }
        }
    }

    if (flagD == false)
    {
        printf ("descending sorted\n");
    }
    else
    {
        printf ("descending not sorted\n");
    }
}