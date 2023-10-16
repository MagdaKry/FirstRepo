#include <stdio.h>

void addEnd(int* ptr1, int size, int n, int* ptr2);

int main(void){

    int tab1[]={1,2,3,4,5};
    int n = 6;
    
    int nb = sizeof(tab1)/sizeof(tab1[0]);
    int tab2[nb+1];
    
    addEnd(tab1,nb,n,tab2);

    printf ("new array: ");
    
    for (int i=0; i<nb+1; i++)
    {
        printf ("%d",tab2[i]);
    }
}

void addEnd(int* ptr1, int size, int n, int* ptr2)
{
    for (int i=0; i<size; i++)
    {
        *(ptr2+i)=*(ptr1+i);
    }
    
    *(ptr2+size)=n;
}
    