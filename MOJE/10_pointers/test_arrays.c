#include <stdio.h>

int main()
{
    int tab[]={1,2,3};
    
    int *p1=tab;
    
    printf("&tab[0]=\t%p\n&tab[1]=\t%p\n&tab[2]=\t%p\np1=\t%p\ntab=\t%p", &tab[0], &tab[1], &tab[2], p1, tab);
    
    p1++;
    printf("\np1++=\t%p\n*p1=\t%d\n", p1, *p1);
    
    //int *ptr;
    int *ptr = NULL;
    printf("\nptr=\t%p\n*ptr=\t%d\n", ptr, *ptr);

    return 0;
}