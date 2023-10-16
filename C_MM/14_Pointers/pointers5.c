#include <stdio.h>
void Double(int *A, int size){
    for (int i = 0; i < size; i++)
    {
        A[i] = 2*A[i];
    }
}
void main(){
    int A[] = {1, 2, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
    Double(A, size); // CALL BY REFERENCE
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
}