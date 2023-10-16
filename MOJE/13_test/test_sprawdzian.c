#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int rec(int tab[],int x,int a, int length);

int main()
{
    /*
    int tab[]={0,1,2,3,4};
    int size=sizeof(tab)/sizeof(tab[0]);
    //printf("%d", size);
    printf("%d", rec(tab, 2, 0, size));
    */

    int tab[]={10,5,7,15,20,5,8};
    int size=sizeof(tab)/sizeof(tab[0]);
    //printf("%d", size);
    printf("%d", rec(tab, 5, 2, size));



    return 0;
}

int rec(int tab[], int x, int a, int length)
{
    
    if (a==length)
    {
        return -1;
    }
    if (tab[a]==x)
    {
        return a;
    }
    else
    {
        return rec(tab,x,a+1,length);
    }
    
    
}