#include <stdio.h>
#include <stdlib.h>

int largest_element(int *A, int size);
void reverse_pointers(int *A, int size);
int sum (int *A, int size);
void swap(int *A, int size, int pos1, int pos2);

int main()
{
    int n=10;
    int *HeapA = (int*)malloc(n*sizeof(int));

    int temp[]={34,5,67,4,37,23,4,8,67,10}; //array for initializing values in A in heap
    for (int i=0; i<n; i++)
    {
        *(HeapA+i)=temp[i];
    }
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(HeapA+i));
    }

    printf("\nMax of HeapA: %d", largest_element(HeapA, n));
    printf("\nSum of HeapA elements: %d", sum(HeapA, n));

    int pos1=4;
    int pos2=9;
    printf("\nHeapA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(HeapA,n,pos1,pos2);
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(HeapA+i));
    }
    printf("\nSwapped HeapA after reversing elements\n");
    reverse_pointers(HeapA,n);
    for (int i=0; i<n; i++)
    {
        printf("%d ", *(HeapA+i));
    }

    free(HeapA);
    HeapA = NULL;
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