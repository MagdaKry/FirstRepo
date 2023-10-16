#include <stdio.h>

void sumArray(int *ptr, int size, int* sum);

int main(){
    
    int tab[] = {1,2,3,4,5,6,7};
    int size=sizeof(tab)/sizeof(tab[0]);
    int sum=0;
    sumArray(tab,size, &sum);
    printf("sum=%d", sum);

    return 0;

}

void sumArray(int *ptr, int size, int*sum)
{
    for (int i=0; i<size; i++)
    {
        *sum+=*(ptr+i);
    }
}