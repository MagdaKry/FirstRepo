#include <stdio.h>

void displayArrayReverse(int *ptr, int size);

int main(){
    
    int tab[] = {1,2,3,4,5};
    int size=sizeof(tab)/sizeof(tab[0]);
    //int* ptr = tab;
    
    displayArrayReverse(tab,size);
    /*
    for (int i=0; i<size; i++)
    {
        printf("%d ", *ptr);
        ptr++;
    }
    */
    return 0;

}

void displayArrayReverse(int *ptr, int size)
{
    for (int i=size-1; i>=0; i--)
    {
        //printf("%d ", *ptr);
        //ptr++;
        printf("%d ", *(ptr+i));
    }
}