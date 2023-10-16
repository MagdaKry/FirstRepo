#include <stdio.h>
#include <stdlib.h>
// Implementation of a Circular Doubly Linked List
struct node {
    struct node* prev;
	int data;
	struct node* next;
};

// Creating a node of a Circular Doubly Linked List
struct node* circularDoubly(int data);
// Inserting a node in an empty list
struct node* CDLL_addToEmpty(int data);
// Inserting a node at the beginning of the CDLL
struct node* CDLL_addAtBeg(struct node* tail, int data);
// Inserting a node at the end of the CDLL
struct node* CDLL_addAtEnd(struct node* tail, int data);
// Inserting a node in between nodes of the CDLL
struct node* CDLL_addAfterPos(struct node* tail, int data, int pos);
// Deleting the first node of the CDLL
struct node* CDLL_delFirst(struct node* tail);
// Deleting the last node of the CDLL
struct node* CDLL_delLast(struct node* tail);
// Deleting an intermediate node of the CDLL
struct node* CDLL_delInter(struct node* tail, int pos);

// Printing a Doubly linked List
void print_CDLL(struct node* head);



int main()
{
    printf("\n\n\n");
    /*
    int data = 34;
    struct node* tail;
    tail = circularDoubly(data);
    printf("%d\n", tail->data);
    */
    struct node* tail = NULL;
    tail = CDLL_delFirst(tail);
    tail = CDLL_addToEmpty(45);
    tail = CDLL_addAtBeg(tail, 34);
    tail = CDLL_addAtEnd(tail, 555);
    tail = CDLL_addAtEnd(tail, 444);
    tail = CDLL_addAtEnd(tail, 666);
    print_CDLL(tail);
    tail = CDLL_addAfterPos(tail, 467, 3);
    print_CDLL(tail);
    tail = CDLL_addAfterPos(tail, 745, 6);
    print_CDLL(tail);
    tail = CDLL_delFirst(tail);
    print_CDLL(tail);
    tail = CDLL_delLast(tail);
    print_CDLL(tail);
    tail = CDLL_delInter(tail, 3);
    print_CDLL(tail);
    tail = CDLL_delInter(tail, 4);
    print_CDLL(tail);

    printf("\n\n\n");
    return 0;
}

// Creating a node of a Circular Doubly Linked List
struct node* circularDoubly(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    temp->prev = temp;
    return temp;
}

// Inserting a node in an empty list
struct node* CDLL_addToEmpty(int data)
{
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;
	return temp;
}

// Inserting a node at the beginning of the CDLL
struct node* CDLL_addAtBeg(struct node* tail, int data)
{
    struct node* newP = CDLL_addToEmpty(data);
    if(tail == NULL)
        return newP;
    struct node* temp = tail->next;

    newP->prev = tail;
    newP->next = temp;
    temp->prev = newP;
    tail->next = newP;
    return tail;
}

// Inserting a node at the end of the CDLL
struct node* CDLL_addAtEnd(struct node* tail, int data)
{
    struct node* newP = CDLL_addToEmpty(data);
    if(tail == NULL)
        return newP;
    struct node* temp = tail->next;
    newP->next = temp;
    newP->prev = tail;
    tail->next = newP;
    temp->prev = newP;
    tail = newP;
    return tail;    
}

// Inserting a node in between nodes of the CDLL
struct node* CDLL_addAfterPos(struct node* tail, int data, int pos)
{
    struct node* newP = CDLL_addToEmpty(data);
    if(tail == NULL)
        return newP;
    struct node* temp = tail->next;
    while(pos > 1)
    {
        temp = temp->next;
        pos--;
    }    
    newP->prev = temp;
    newP->next = temp->next;
    temp->next->prev = newP;
    temp->next = newP;
    if(temp == tail)
        tail = tail->next;
    return tail;
}

// Deleting the first node of the CDLL
struct node* CDLL_delFirst(struct node* tail)
{
    if(tail == NULL)
    {
        printf("No nodes in the Linked List.\n");
        return tail;
    }
    struct node* temp = tail->next;
    if(temp == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    tail->next = temp->next;
    temp->next->prev = tail;
    free(temp);
    return tail;
}

// Deleting the last node of the CDLL
struct node* CDLL_delLast(struct node* tail)
{
    struct node* temp = tail->prev;
    if(tail == NULL)
    {
        printf("No nodes in the Linked List.\n");
        return tail;        
    }
    if(temp == tail)
    {
        free(tail);
        tail = NULL;
        return tail;
    }
    temp->next = tail->next;
    tail->next->prev = temp;
    free(tail);
    tail = temp;
    return tail; 
}

// Deleting an intermediate node of the CDLL
struct node* CDLL_delInter(struct node* tail, int pos)
{
    struct node* temp = tail->next;
    while(pos > 1)
    {
        temp = temp->next;
        pos--;
    }
    struct node* temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);
    if(temp == tail)
        tail = temp2;
    return tail;
}

// Printing the elemets of the CDLL
void print_CDLL(struct node* tail)
{
    if(tail == NULL)
    {
        printf("No element in the List.\n");
        return;
    }    
    struct node* temp = tail->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != tail->next);
    printf("\n");
}