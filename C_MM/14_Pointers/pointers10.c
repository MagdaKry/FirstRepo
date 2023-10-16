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

    int *B = (int*)realloc(A, 2*n*sizeof(int));

    printf("Old block address = %d, new address = %d\n", A, B);

     for (int i = 0; i<n; i++)
    {
        printf("Block A: %d \n", *(A+i)); // or A[i]
    }

    printf("\n");

    for (int i = 0; i<2*n; i++)
    {
        printf("Block B: %d \n", *(B+i)); // or B[i]
    }

    free(A);
    A = NULL;
    free(B);
    B = NULL;
}