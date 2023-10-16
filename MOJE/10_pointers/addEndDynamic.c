#include <stdio.h>
#include <stdlib.h>

int getNumber(char message[]);
void initialize(int *ptr, int size);
void displayArray(int *ptr, int size);
int* addEnd(int* ptr1, int *size, int n);

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
    printf ("\np=%p", arr);

    int n=5;
    arr=addEnd(arr, &size, n);

    displayArray(arr,size);
    printf ("\np=%p\n", arr);

    free(arr);

    //printf ("\np=%p\n", arr);
    //displayArray(arr,size);

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

int* addEnd(int* ptr1, int *size, int n)
{
    int *newArr = (int *)realloc(ptr1, (*size+1) * sizeof(int));
    if (newArr != NULL) {
        *(newArr+*size)=n;
        *size+=1;
        return newArr;
    }
    else
    {
        return NULL;
    }
}

/*
#include <stdio.h>
#include <stdlib.h>

int getNumber(char message[]);
void initialize(int *ptr, int size);
void displayArray(int *ptr, int size);
int* addEnd(int* ptr1, int size, int n);

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

    int n=5;
    int *arr1= addEnd(arr, size, n);

    displayArray(arr1,size+1);

    //free(arr);
    free(arr1);
    
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

int* addEnd(int* ptr1, int size, int n)
{
    
    int *newArr = (int *)realloc(ptr1, (size+1) * sizeof(int));
    if (newArr == NULL) {
        printf("Memory reallocation failed.\n");
        free(ptr1); // Free the original array
        return NULL; // Exit with an error code
    }

    *(newArr+size)=n;

    return newArr;
}
*/