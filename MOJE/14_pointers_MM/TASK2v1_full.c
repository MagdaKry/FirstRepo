#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int largest_element(int *A, int size);
void reverse_pointers(int *A, int size);
int sum (int *A, int size);
void swap(int *A, int size, int pos1, int pos2);
void remove_duplicates(int *A, int *size);
void sort_ascending(int *A, int size);
void print_array(int *A, int size);
void inserting_pos(int *A, int *size, int pos, int d);
void inserting_start(int *A, int *size, int d);
void inserting_end(int *A, int *size, int d);
void deleting_pos(int *A, int *size, int pos);
void deleting_start(int *A, int *size);
void deleting_end(int *A, int *size);

int main()
{
    int n=10;
    int *HeapA = (int*)malloc(n*sizeof(int));

    int temp[]={34,5,67,4,37,23,4,8,67,10}; //array for initializing values in A in heap
    for (int i=0; i<n; i++)
    {
        *(HeapA+i)=temp[i];
    }
    print_array(HeapA, n);

    printf("\nMax of HeapA: %d", largest_element(HeapA, n));
    printf("\nSum of HeapA elements: %d", sum(HeapA, n));

    int pos1=0;
    int pos2=0;
    printf("\nGive me first position you want to swap (between %d and %d (included)):", 1, n);
    scanf("%d", &pos1);
    printf("\nGive me second position you want to swap (between %d and %d (included)):", 1, n);
    scanf("%d", &pos2);
    printf("\nHeapA after swapping elements at %d and %d positions\n", pos1, pos2);
    swap(HeapA,n,pos1,pos2);
    print_array(HeapA, n);
    printf("\nSwapped HeapA after reversing elements\n");
    reverse_pointers(HeapA,n);
    print_array(HeapA, n);

    printf("\nSwapped and reversed HeapA in ascending order\n");
    sort_ascending(HeapA, n);
    print_array(HeapA, n);

    printf("\nSwapped and reversed HeapA in ascending order after removing duplicates (resized)\n");
    remove_duplicates(HeapA, &n);
    print_array(HeapA, n);
    /*
    printf("check0: %d\n",*(HeapA+n-1));
    printf("check1: %d\n",*(HeapA+n));
    printf("check2: %d\n",*(HeapA+n+1));
    printf("check3: %d\n",*(HeapA+n+2));
    */

    int pos3=0;
    int data=0;
    printf("\nGive me position at which you want to insert new element between %d and %d (included).", 1, n);
    scanf("%d", &pos3);
    printf("\nGive me the data to insert");
    scanf("%d", &data);
    inserting_pos(HeapA,&n,pos3,data);
    printf("\nNew array:\n");
    print_array(HeapA, n);

    printf("\nGive me the data to insert at the beginning");
    scanf("%d", &data);
    inserting_start(HeapA,&n,data);
    printf("\nNew array:\n");
    print_array(HeapA, n);

    printf("\nGive me the data to insert at the end");
    scanf("%d", &data);
    inserting_end(HeapA,&n,data);
    printf("\nNew array:\n");
    print_array(HeapA, n);
    
    deleting_start(HeapA,&n);
    printf("\nNew array after deleting first element:\n");
    print_array(HeapA, n);
    /*
    printf("check0: %d\n",*(HeapA+n-1));
    printf("check1: %d\n",*(HeapA+n));
    printf("check2: %d\n",*(HeapA+n+1));
    printf("check3: %d\n",*(HeapA+n+2));
    */

    deleting_end(HeapA,&n);
    printf("\nNew array after deleting last element:\n");
    print_array(HeapA, n);

    /*
    printf("check0: %d\n",*(HeapA+n-1));
    printf("check1: %d\n",*(HeapA+n));
    printf("check2: %d\n",*(HeapA+n+1));
    printf("check3: %d\n",*(HeapA+n+2));
    */
   
    int pos4=0;
    printf("\nGive me position at which you want to delete element (between %d and %d (included)):", 1, n);
    scanf("%d", &pos4);
    deleting_pos(HeapA,&n,pos4);
    printf("\nNew array:\n");
    print_array(HeapA, n);

    /*
    printf("check0: %d\n",*(HeapA+n-1));
    printf("check1: %d\n",*(HeapA+n));
    printf("check2: %d\n",*(HeapA+n+1));
    printf("check3: %d\n",*(HeapA+n+2));
    */

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

void remove_duplicates(int *A, int *size)
{
    
    for (int i=0; i<*size; i++)
    {
        for(int j=i+1; j<*size; j++)
        {
            if (*(A+j)==*(A+i))
            {
                *(A+j)=0;
            }
        }
    }
    
    int temp[*size];
    int j=0;
    int k=0;

    for (int i=0; i<*size; i++)
    {
        if (*(A+i)==0)
        { 
            temp[*size-1-k]=0;
            k++;
            continue;
        }
        else
        {
            temp[j]=*(A+i);
            j++;
        }
        
    }
    
    for (int i=0; i<*size; i++)
    {
        *(A+i)=temp[i];
    }

    for (int i=0; i<*size-k; i++)
    {
        *(A+i)=temp[i];
    }
    for (int i=*size-k; i<*size; i++)
    {
        *(A+i)=0;
    }
    A=(int*)realloc(A,(*size-k)*sizeof(int));
    *size=*size-k;

}

void sort_ascending(int *A, int size)
{
    bool change = false;

    while(change==false)
    {
        change=true;
        for (int i=0; i<size-1; i++)
        {
            for (int j=i; j<size-1; j++)
            {
                if(*(A+j)>*(A+j+1))
                {
                    int temp=*(A+j);
                    *(A+j)=*(A+j+1);
                    *(A+j+1)=temp;
                    change=false;
                }
            }
        }
    }
}

void print_array(int *A, int size)
{
    for (int i=0; i<size; i++)
    {
        printf("%d ", *(A+i));
    }
}

void inserting_pos(int *A, int *size, int pos, int d)
{
    //excluding cases os inserting new value at start and at the end
    A=(int*)realloc(A,(*size+1)*sizeof(int));
    for (int i=0; i<*size; i++)
    {   
        if (i==(pos-1))
        {
            for(int j=*size-1; j>=i; j--)
            {
                *(A+j+1)=*(A+j);
            }
            *(A+i)=d;
        }     
    }
    (*size)++;  
}

void inserting_start(int *A, int *size, int d)
{
    A=(int*)realloc(A,(*size+1)*sizeof(int));
    for(int j=*size-1; j>=0; j--)
    {
        *(A+j+1)=*(A+j);
    }
    *A=d;
    (*size)++;
}

void inserting_end(int *A, int* size, int d)
{
    A=(int*)realloc(A,(*size+1)*sizeof(int));
    *(A+*size)=d;
    (*size)++;
}

void deleting_pos(int *A, int *size, int pos)
{
    for (int i=0; i<*size; i++)
    {   
        if (i==(pos-1))
        {
            for(int j=i; j<*size-1; j++)
            {
                *(A+j)=*(A+j+1);
            }
        }     
    }
    *(A+*size-1)=0;
    A=(int*)realloc(A,(*size-1)*sizeof(int));
    (*size)--;
}

void deleting_start(int *A, int *size)
{
    for(int j=0; j<*size-1; j++)
    {
        *(A+j)=*(A+j+1);
    }
    *(A+*size-1)=0;
    A=(int*)realloc(A,(*size-1)*sizeof(int));
    (*size)--;
}

void deleting_end(int *A, int* size)
{
    *(A+*size-1)=0;
    A=(int*)realloc(A,(*size-1)*sizeof(int));
    (*size)--;
}