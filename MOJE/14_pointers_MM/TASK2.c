#include <stdio.h>
#include <stdlib.h>

int largest_element(int *A, int size);
void reverse_pointers(int *A, int size);
int sum (int *A, int size);
void swap(int *A, int size, int pos1, int pos2);

int main()
{
    int n=10;
    int *A = (int*)malloc(n*sizeof(int));

    int temp[]={34,5,67,4,37,23,4,8,67,10}; //array for initializing values in A in heap
    for (int i=0; i<n; i++)
    {
        *(A+i)=temp[i];
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(A+i));
    }

    printf("\nMax of A: %d", largest_element(A, n));
    printf("\nSum of A elements: %d", sum(A, n));

    int pos1=4;
    int pos2=9;
    printf("\nA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(A,n,pos1,pos2);
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(A+i));
    }
    printf("\nSwapped A after reversing elements\n");
    reverse_pointers(A,n);
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(A+i));
    }

    free(A);
    A = NULL;
    return 0;
}


int largest_element(int *A, int size)
{
    int max=*A;
    for (int i=1; i<size; i++)
    {
        if (*(A+i)>max)
        {
            max=*(A+i);
        }
    }
    return max;
}

void reverse_pointers(int *A, int size)
{
    int *first = A;          
    int *last = A + size - 1;

    while (first < last)
    {
        int temp = *first;
        *first = *last;
        *last = temp;

        first++;
        last--;
    }
}

int sum (int *A, int size)
{
    int sum=*A;
    for (int i=1; i<size; i++)
    {
        sum+=*(A+i);
    }
    return sum;
}

void swap(int *A, int size, int pos1, int pos2)
{
    //position-1=indexOfArray;
    int temp=*(A+pos1-1);
    *(A+pos1-1)=*(A+pos2-1);
    *(A+pos2-1)=temp;
}