#include <stdio.h>

void reverseTab(int *p1, int size);
void displayArray(int *ptr, int size);

int main(){

    int tab[] = {1,2,3,4,5};
    int size=sizeof(tab)/sizeof(tab[0]);

    printf("before: ");
    displayArray(tab,size);
    reverseTab(tab,size);
    printf("\nafter: ");
    displayArray(tab,size);

    return 0;
}

void reverseTab(int *p1, int size)
{
    int temp=0;
    
    for (int i=0; i<size/2; i++)
    {
        temp=*(p1+i);
        *(p1+i)=*(p1+size-i-1);
        *(p1+size-i-1)=temp;
    }
}

void displayArray(int *ptr, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", *(ptr+i));
    }
}