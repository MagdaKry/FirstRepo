#include <stdio.h>

void replaceWithAbsolute (int* p1);

void main(){
    
    int n1 = -9;

    printf("variable with &:\nn1=%d(adres %p)\n", n1, &n1);
    replaceWithAbsolute (&n1);
    printf("absolute value |n1|=%d\n", n1);
    
    int n2 = -13;
    int *pn2 = &n2;
    
    printf("pointer:\nn1=%d (adres %p)\n", n2, pn2);
    replaceWithAbsolute (pn2);
    printf("absolute value |n1|=%d\n", n2);
    
}


void replaceWithAbsolute (int* p1)
{
    if(*p1<00)
    {
        //*p1*=-1;
        *p1=-1**p1;
    }
}