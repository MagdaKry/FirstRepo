#include <stdio.h>
#include <stdlib.h>
// Implementation of a Circular Singly Linked List
struct node {
	int data;
	struct node* next;
};

// Creating a node of a Circular Singly Linked List
struct node* circularSingly(int data);
// Adding a node to an empty CSLL
struct node* CSLL_addToEmpty(int data);
// Adding a node at the beginning of a CSLL
struct node* CSLL_addAtBeg(struct node* tail, int data);
// Adding a node at the end of a CSLL
struct node* CSLL_addAtEnd(struct node* tail, int data);
// Adding a node after a certain position of a CSLL
struct node* CSLL_addAfterPos(struct node* tail, int data, int pos);
// Creating a complete CSLL
struct node* CSLL_createList(struct node* tail);
// Deleting the first node of CSLL
struct node* CSLL_delFirst(struct node* tail);
// Deleting the last node of CSLL
struct node* CSLL_delLast(struct node* tail);
// Deleting the intermediate node of CSLL
struct node* CSLL_delInter(struct node* tail, int pos);
// Counting the number of elements of CSLL
void CSLL_countElements(struct node* tail);
// Searching for an element of CSLL
int CSLL_searchElement(struct node* tail, int element);
// Printing the elemets of the CSLL
void print_CSLL(struct node* tail);

int main()
{
    printf("\n\n\n");
    int data = 34;
    struct node* tail; // tail pointer points to the last node of the list
    /*
    tail = CSLL_addToEmpty(data);
    tail = CSLL_addAtBeg(tail, 54);
    print_CSLL(tail);
    tail = CSLL_addAtEnd(tail, 777);
    print_CSLL(tail);
    tail = CSLL_addAfterPos(tail, 555, 3);
    print_CSLL(tail);
    */
    tail = CSLL_createList(tail);
    print_CSLL(tail);

    int element;
    printf("Enter the element to search for: ");
    scanf("%d", &element);

    int index = CSLL_searchElement(tail, element);
    if(index == -1)
        printf("Element not found!");
    else if(index == -2)
        printf("Linked List is empty!");
    else
        printf("Element %d is at index %d", element, index);
    
     
    CSLL_countElements(tail);
    tail = CSLL_delInter(tail, 2);
    print_CSLL(tail);
    CSLL_countElements(tail);
    tail = CSLL_delInter(tail, 3);
    print_CSLL(tail);
    CSLL_countElements(tail);

    tail = CSLL_delFirst(tail);
    print_CSLL(tail);
    tail = CSLL_delLast(tail);
    print_CSLL(tail);
    
    printf("\n\n\n");
    return 0;
}

// Creating a node of a Circular Singly Linked List
struct node* circularSingly(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

// Adding a node to an empty CSLL
struct node* CSLL_addToEmpty(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

// Adding a node at the beginning of a CSLL
struct node* CSLL_addAtBeg(struct node* tail, int data)
{
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    tail->next = newP;
    return tail;
}

// Adding a node at the end of a CSLL
struct node* CSLL_addAtEnd(struct node* tail, int data)
{
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;  
    newP->next = NULL;

    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;  
}

// Adding a node after a certain position of a CSLL
struct node* CSLL_addAfterPos(struct node* tail, int data, int pos)
{
    struct node* ptr = tail->next; // ptr points to the first element of CSLL
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;  
    newP->next = NULL;

    while(pos>1)
    {
        ptr = ptr->next;
        pos--;
    }

    newP->next = ptr->next;
    ptr->next = newP;

    if(ptr == tail)
        tail = tail->next;
    
    return tail;
}

// Creating a complete CSLL
struct node* CSLL_createList(struct node* tail)
{
    int i, n, data;
    printf("Enter the number of nodes of the CSLL: ");
    scanf("%d", &n);

    if(n == 0)
        return NULL;
    printf("Enter the element 1: ");
    scanf("%d", &data);
    tail = CSLL_addToEmpty(data);

    for(i=1; i<n; i++)
    {
        printf("Enter the element %d: ", i+1);
        scanf("%d", &data);
        tail = CSLL_addAtEnd(tail, data);
    }
    return tail;
}

// Deleting the first node of CSLL
struct node* CSLL_delFirst(struct node* tail)
{
    if(tail == NULL)
        return tail;
    if(tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    else{
    struct node* temp = tail->next;
    tail->next = temp->next;
    free(temp);
    temp = NULL;
    return tail;
    }
}

// Deleting the last node of CSLL
struct node* CSLL_delLast(struct node* tail)
{
    if(tail == NULL)
        return tail;
    struct node* temp = tail->next;
    if(tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while(temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
    return tail;
}

// Deleting the intermediate node of CSLL
struct node* CSLL_delInter(struct node* tail, int pos)
{
    if(tail == NULL)
        return tail;
    struct node* temp = tail->next;
    if(tail->next == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    while (pos > 2)
    {
        temp = temp->next;
        pos--;
    }
    struct node* temp2 = temp->next;
    temp->next = temp2->next;

    if(temp2 == tail)
        tail = temp;
    free(temp2);
    temp2 = NULL;
    return tail;
}

// Counting the number of elements of CSLL
void CSLL_countElements(struct node* tail)
{
    struct node* temp = tail->next;
    int count = 0;
    while(temp != tail)
    {
        temp = temp->next;
        count++;
    }    
    count++; // To include the last node pointed by tail
    printf("There are %d elements in the list.\n", count);
}

// Searching for an element of CSLL
int CSLL_searchElement(struct node* tail, int element)
{
    struct node* temp;
    int index = 0;

    if(tail == NULL)
        return -2;

    temp = tail->next;
    do {
        if(temp->data == element)
            return index;
        temp = temp->next;
        index++;
    }   while(temp != tail->next);
    return -1;
}

// Printing the elemets of the CSLL
void print_CSLL(struct node* tail)
{
    if(tail == NULL)
    {
        printf("No node in the List.\n");
        return;
    }    
    struct node* ptr = tail->next;
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    } while (ptr != tail->next);
    printf("\n");
}