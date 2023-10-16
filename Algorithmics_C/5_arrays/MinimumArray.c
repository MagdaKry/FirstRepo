#include<stdio.h>
#include<stdlib.h>

int arrayMinimum(int t[], int size);

int main()
{

    int tab[] = {1, 2, 3, 4, 0};

    int tab1[] = {4, 7, 9, 10, 20, 67};

    // int tab[5]= {1,2,3,4,0};

    int size = sizeof(tab) / sizeof(tab[0]); // Nb of items7
    int size1 = sizeof(tab1) / sizeof(tab1[0]); // Nb of items

    printf("Nb of elements:%d\n", size);

    int min = arrayMinimum(tab, size);
    int min1 = arrayMinimum(tab1, size1);
    printf("The minimum of tab is %d\n", min);
    printf("The minimum of tab1 is %d\n", min1);

    /*int min;
    min= tab[0];
    for(int i =1; i<size;i++){
        if(tab[i]<min)
        min=tab[i];
    }*/
    //printf("The minimal value of the array is %d\n", min);

    return 0;
}

int arrayMinimum(int t[], int size){

int min;
min = t[0];
for (int i = 1; i < size; i++)
{
    if (t[i] < min)
        min = t[i];
}
return min;
}