#include <stdio.h>
#include <stdlib.h>

int getNumber(char message[]);
void initialize(int *ptr, int size);
void displayArray(int *ptr, int size);

int main() {

    int size=5;
    //printf("Enter the size of array:\n");
    //scanf("%d", &size);

    int *arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL) 
    {
        printf("Memory allocation failed.\n");
        return 1; 
    }
    
    
    //initialize(arr,size);
    for (int i = 0; i < size;i++)
    {
        *(arr+i) = i*3;
    }
    displayArray(arr,size);

    free(arr);

    return 0;
}

int getNumber(char message[])
{
    int nb;
    printf(message);
    scanf("%d", &nb);
    return nb;
}

void initialize(int *ptr, int size)
{
    for (int i = 0; i < size;i++)
    {
        *(ptr+i) = getNumber("Enter element of array ");
    }
}

void displayArray(int *ptr, int size)
{
    printf("\nArray elements: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", *(ptr+i));
    }
}
