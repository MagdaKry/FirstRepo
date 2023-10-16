#include <stdio.h>
#include <stdlib.h>

void main()
{
    int n;
    printf("Enter size of the array \n");
    scanf("%d", &n);

    //int *A = (int*)malloc(n*sizeof(int)); // dynamically allocated array
    int *A = (int*)calloc(n, sizeof(int));
    for (int i = 0; i<n; i++)
    {
        A[i] = i + 1;
    }
    A = (int*)realloc(A, 2*n*sizeof(int));
    for (int i = 0; i<n; i++)
    //for (int i = 0; i<2*n; i++)
    {
        printf("Block A: %d \n", *(A+i)); // or A[i]
    }
    free(A);
    A = NULL;
}