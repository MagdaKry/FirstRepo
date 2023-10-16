#include <stdio.h>
#include <stdlib.h>

int * createIntArray(int size)
{
    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return NULL; // Return NULL to indicate failure
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = i * 2; // Example: Initialize with even numbers
    }
    return arr; // Return the pointer to the dynamically allocated array
}
int main()
{
    int *myArray;
    int size = 5;
    myArray = createIntArray(size);
    if (myArray != NULL)
    {
        printf("Array elements: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", myArray[i]);
        }
        printf("\n");
        free(myArray);
    }
    return 0;
}
