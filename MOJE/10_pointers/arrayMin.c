#include <stdio.h>

void minArray(int *ptr, int size, int* min);

int main(){
    
    int tab[] = {2,-3,4,-5,6,7};
    int size=sizeof(tab)/sizeof(tab[0]);
    int min=0;
    minArray(tab,size, &min);
    printf("min=%d", min);

    return 0;

}

void minArray(int *ptr, int size, int* min)
{
    *min=*ptr;
    for (int i=0; i<size; i++)
    {
        if(*(ptr+i)<*min)
        {
            *min=*(ptr+i);
        }
    }
}
