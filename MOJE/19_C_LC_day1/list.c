#include <stdio.h>
#include <stdlib.h>

/*
A Singly Linked List (SLL) is a data structure made up of linked elements (links), with each link represented by a structure containing a value (data) and a pointer to the next link.
A SLL starts from a head (which we'll simply call sll for the following exercises) linked to all subsequent elements. The last element points to 'NULL' to mark the end of the LSC.
1. Create a 'Link'  structure corresponding to a link in an LSC via typedef struct, containing a pointer next to the next 'Link' and an integer, called value.
2. Code a function int sll_length(Link* sll) taking as input the head of an LSC and returning the length of the listwith an iterative algorithm. 
*/

typedef struct Link {
    int value;
    struct Link *next;
} Link;

int sll_length(Link* sll) {
   int length=0;
   Link* temp = NULL;
   temp=sll;
   while(temp!=NULL)
   {
       length++;
       temp=temp->next;
   }
   return length;  
}

/*
Code a function int sll_length_recur(Link* sll) taking as input the root of an LSC and returning the length of the listvia a recursive algorithm. 
*/

int sll_length_recur(Link* sll) 
{
    if (sll==NULL)
        return 0;
    else if (sll!=NULL && sll->next==NULL)
        return 1;
    else
        return 1+sll_length_recur(sll->next);
}

/*
Code a function int sll_indexOf(Link* sll, int value) taking as input the head of an LSC and an integer val, returning the index (position) of the first appearance of val in the list (or -1 if val is not in the list) via an iterative algorithm.

Attention: the initial index is assumed to be 1. 

(Chained lists are represented as follows: < val → val → val → val  > and the return value of a function by =>)

Examples:

sll_indexOf( < >, 12) => -1
sll_indexOf( < 1 → 2 → 3 → 4 >, 1) => 1
sll_indexOf( < 1 → 2 → 3 → 4 >, 6) => -1
sll_indexOf( < 5 → 73 → 14 → -223 >, -223) => 4
sll_indexOf( < 2 → 3 → 3 → 4 → 3 >, 3) => 2
*/

int sll_indexOf(Link* sll, int value) {
    
    int i=1;
    Link *temp=sll;
    if(sll==NULL)
        return -1;
    while(temp!=NULL)
    {
        if(temp->value==value)
            return i;
        else
            temp=temp->next;
            i++;
    }
    return -1;
}

/*
Code a function int sll_indexOf_recur(Link* sll, int value) taking as input the head of an LSC and an integer val and returning the index (position) of val in the list (or -1 if val is not in the list) via a recursive algorithm.

Please note: The initial index is assumed to be 1. 

Examples:

sll_indexOf_recur( < >, 12) => -1
sll_indexOf_recur( < 1 → 2 → 3 → 4 >, 1) => 1
sll_indexOf_recur( < 1 → 2 → 3 → 4 >, 6) => -1
sll_indexOf_recur( < 5 → 73 → 14 → -223 >, -223) => 4
sll_indexOf_recur( < 2 → 3 → 3 → 4 → 3 >, 3) => 2

int getPosition(Node<T>* head, T element)
{
    if (head == nullptr) {
        return -1;
    }
    if (head->data == element) {
        return 1;
    }
    int tailPosition = getPosition(head->next, element);
    return tailPosition < 0 ? -1 : tailPosition + 1;
}

*/

int sll_indexOf_recur(Link* sll, int value) {
    
    if (sll==NULL)
        return -1;
    else if (sll->value==value)
        return 1;
    else
    {
        int pos=sll_indexOf_recur(sll->next, value);
        if (pos<0)
            return -1;
        else
            return 1+pos;
    }   
}

/*
Code a function int sll_nOccs(Link* sll, int val) taking as input the head of an LSC and returning the number of occurrences of an element val via an iterative algorithm.

Examples:

sll_nOccs( < >, 20 ) => 0
sll_nOccs( < 1 → 2 → 3 → 4 >, 3 ) => 1
sll_nOccs( < 1 → 2 → 3 → 4 >, 6 ) => 0
sll_nOccs( < 5 → 73 → 14 → -223 → 14 → 10 → 14 >, 14 ) => 3
*/

int sll_nOccs(Link* sll, int val) {
    
    int i=0;
    Link *temp=sll;
    if(sll==NULL)
        return 0;
    while(temp!=NULL)
    {
        if(temp->value==val)
            i++;
        temp=temp->next;
    }
    return i;
}

/*
Code a function int sll_nOccs_recur(Link* sll, int val) taking as input the head of an LSC and returning the number of occurrences of an element val via a recursive algorithm.

Examples:

sll_nOccs_recur( < >, 20 ) => 0
sll_nOccs_recur( < 1 → 2 → 3 → 4 >, 3 ) => 1
sll_nOccs_recur( < 1 → 2 → 3 → 4 >, 6 ) => 0
sll_nOccs_recur( < 5 → 73 → 14 → -223 → 14 → 10 → 14 >, 14 ) => 3
*/

int sll_nOccs_recur(Link* sll, int val)
{
    if (sll==NULL)
        return 0;
    else if (sll->value==val)
        return 1+sll_nOccs_recur(sll->next, val);
    else if (sll->value!=val)
        return 0+sll_nOccs_recur(sll->next, val);
}

/*
Code a function int sll_sum(Link* sll) taking as input the head of an LSC and returning the sum of the list's elementsvia an iterative algorithmOR recursive algorithm.

Examples:

sll_sum( < 1 → 2 → 3 → 4 > ) => 10
sll_sum( < 5 → 12 → 42 → 55 → 42 > ) => 156
sll_sum( < > ) => 0
*/
int sll_sum(Link* sll) {
    
    int sum=0;
    Link *temp=sll;
    if(sll==NULL)
        return 0;
    while(temp!=NULL)
    {
        sum+=temp->value;
        temp=temp->next;
    }
    return sum;
    
}

int sll_sum(Link* sll) {
    if (sll==NULL)
        return 0;
    else
        return sll->value+sll_sum(sll->next);
}

/*
Code a function int sll_product(Link* sll) taking as input the head of an LSC and returning the product of the list elements via an iterative algorithm ORrecursive.

If the LSC is empty, return 1 (the neutral element of the multiplication).

Examples:

sll_product( < 1 → 2 → 3 → 4 > ) => 24
sll_product( < 5 → 12 → 42 → 55 → 42 > ) => 5821200
sll_product( < 5 → 12 → 0 → 55 → 42 > ) => 0
sll_product( < > ) => 1
*/

int sll_product(Link* sll) {
   
    int product=1;
    Link *temp=sll;
    if(sll==NULL)
        return 1;
    while(temp!=NULL)
    {
        product*=temp->value;
        temp=temp->next;
    }
    return product;
    
}

int sll_product(Link* sll) {
    if (sll==NULL)
        return 1;
    else
        return sll->value*sll_product(sll->next);
}

/*
Code a function int sll_increasing(Link* sll) taking as input the head of an LSC and returning 1 if the values of the LSC are strictly increasing and 0 otherwise.

Examples:

sll_increasing( < > ) => 1
sll_increasing( < 1 > ) => 1
sll_increasing( < 1 → 2 → 3 → 4 > ) => 1
sll_increasing( < 1 → 2 → 2 → 3 > ) => 0
sll_increasing( < -10 → 12 → 22 → 34 > ) => 1
sll_increasing( < -10 → 12 → 11 → 34 → 64 > ) => 0
*/
int sll_increasing(Link* sll) {
    
    Link *temp=sll;
    if(sll==NULL||sll->next==NULL)
        return 1;
    while(temp->next!=NULL)
    {
        if(temp->value>=temp->next->value)
            return 0;
        temp=temp->next;
    }
    return 1;
}

/*
You have at your disposal a void _log(int data) function, allowing you to log values in a precise order.

Code a void log_sll_reverse(Link* sll) function taking as input the head of an LSC, and which will log the values of the LSC in reverse.
*/

void log_sll_reverse(Link* sll) {

    Link* temp, *temp2;
    temp=sll;
    temp2=sll;
    
    int count = 0;
    
    if (sll==NULL)
        printf("null");
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    
    int temp_arr[count];
    
    for(int i=0; i<count; i++)
    {
        temp_arr[i]=temp2->value;
        printf("%d ", temp2->value);
        temp2=temp2->next;
    }
    
    
    for(int i=count-1; i>=0; i--)
    {
        _log(temp_arr[i]);
        printf("%d ", temp_arr[i]);
    }
    
    printf("\n");
}

/*
Code a function Link* sll_reverse(Link* sll) taking as input the head of an LSC and returning the inverse of the list (tail becomes head and head becomes tail).

Attention: pointers must be inverted directly, and no new pointers must be created.

Examples:

sll_reverse( < 1 → 2 → 3 → 4 > ) => < 4 → 3 → 2 → 1 >
sll_reverse( < 5 → 12 → 42 → 55 → 42 > ) => < 42 → 55 → 42 → 12 → 5 >
sll_reverse( < > ) => < >
*/

Link* sll_reverse(Link* sll) {
    
    Link* prev=NULL;
    Link* next=NULL;

    if(sll==NULL||sll->next==NULL)
        return sll;
    
    while(sll!=NULL)
    {
       next=sll->next;
       sll->next=prev;
       prev=sll;
       sll=next;
    }
    sll=prev;
    return sll;

}
