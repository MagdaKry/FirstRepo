#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int A[]={34,5,67,4,37,23,4,8,67,10};
const int size=sizeof(A)/sizeof(int);

int largest_element();
void reverse();
int sum ();
void swap(int pos1, int pos2);
int remove_duplicates();
void sort_ascending();
void print_array();

int main()
{
    print_array();
    printf("\nMax of A: %d", largest_element());
    printf("\nSum of A elements: %d", sum());

    int pos1=0;
    int pos2=0;
    printf("\nGive me first position you want to swap (between %d and %d (included)):", 1, size);
    scanf("%d", &pos1);
    printf("\nGive me second position you want to swap (between %d and %d (included)):", 1, size);
    scanf("%d", &pos2);

    printf("\nA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(pos1,pos2);
    print_array();
    printf("\nSwapped A after reversing elements\n");
    reverse();
    print_array();

    printf("\nSwapped and reversed A in ascending order\n");
    sort_ascending();
    print_array();

    printf("\nSwapped and reversed A in ascending order after removing duplicates\n");
    int size_new=remove_duplicates();
    print_array();
    printf("\nArray B - values from A without zeros\n");
    int B[size_new];
    for (int i=0; i<size_new; i++)
    {
        B[i]=A[i];
        printf("%d ", B[i]);
    }

    return 0;
}

int largest_element()
{
    int max=A[0];
    for (int i=1; i<size; i++)
    {
        if (A[i]>max)
        {
            max=A[i];
        }
    }
    return max;
}

void reverse()
{
    int temp=0;
    
    for (int i=0; i<size/2; i++)
    {
        temp=A[i];
        A[i]=A[size-i-1];
        A[size-i-1]=temp;
    }
}

int sum ()
{
    int sum=A[0];
    for (int i=1; i<size; i++)
    {
        sum+=A[i];
    }
    return sum;
}

void swap(int pos1, int pos2)
{
    //position-1=indexOfArray;
    int temp=A[pos1-1];
    A[pos1-1]=A[pos2-1];
    A[pos2-1]=temp;
}

int remove_duplicates()
{
    //Declared static array can't be resized
    //so I put value zero in place of removed duplicates 
    //and then I move those zeros to the end of array.
    //I return new size to create another array if needed.

    for (int i=0; i<size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if (A[j]==A[i])
            {
                A[j]=0;
            }
        }
    }
    
    int temp[size];
    int j=0;
    int k=0;

    for (int i=0; i<size; i++)
    {
        if (A[i]==0)
        { 
            temp[size-1-k]=0;
            k++;
            continue;
        }
        else
        {
            temp[j]=A[i];
            j++;
        }
        
    }
    for (int i=0; i<size; i++)
    {
        A[i]=temp[i];
    }

    return size-k;
}

void sort_ascending()
{
    bool change = false;

    while(change==false)
    {
        change=true;
        for (int i=0; i<size-1; i++)
        {
            for (int j=i; j<size-1; j++)
            {
                if(A[j]>A[j+1])
                {
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                    change=false;
                }
            }
        }
    }
}

void print_array()
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", A[i]);
    }
}