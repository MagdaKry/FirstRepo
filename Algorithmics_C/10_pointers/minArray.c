#include <stdio.h>
#include <stdlib.h>

int arrayMinimum(int t[], int size);
int findMax(int t[], int size);

int main()
{

    int tab[] = {1, 2, 3, 4, 0};


    // int tab[5]= {1,2,3,4,0};

    int size = sizeof(tab) / sizeof(tab[0]);    // Nb of items7

    printf("Nb of elements:%d\n", size);

    int min = arrayMinimum(tab, size);
    int max = findMax(tab, size);
    printf("The minimum of tab is %d\n", min);
    printf("The maximum of tab is %d\n", max);

    /*int min;
    min= tab[0];
    for(int i =1; i<size;i++){
        if(tab[i]<min)
        min=tab[i];
    }*/
    // printf("The minimal value of the array is %d\n", min);

    return 0;
}

int arrayMinimum(int *t, int size)
{

    int min;
    min = *t;
    for (int i = 1; i < size; i++)
    {
        if (*(t+i)< min)
            min = *(t+i);
    }
    return min;
}

int findMax(int *arr, int size)
{
    if (size <= 0)
    {
        // Handle empty array or invalid size
        return -1; // You can choose an appropriate error value
    }

    int max = *arr;     // Initialize max to the first element
    int *ptr = arr + 1; // Start from the second element

    for (int i = 1; i < size; i++)
    {
        if (*ptr > max)
        {
            max = *ptr; // Update max if a larger value is found
        }
        ptr++; // Move to the next element
    }

    return max;
}