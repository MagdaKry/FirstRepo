#include <stdio.h>
#include <stdlib.h>
// Implementation of a Doubly Linked list
struct node {
	struct node* prev;
	int data;
	struct node* next;
};

// Inserting a node in an empty list
struct node* addToEmpty(struct node* head, int data);
// Inserting a node at the beginning of a doubly linked list
struct node* addAtBeg(struct node* head, int data);
// Inserting a node at the end of a doubly linked list
struct node* addAtEnd(struct node* head, int data);
// Inserting a node in between nodes of a doubly linked list
struct node* addAfterPos(struct node* head, int data, int position);
// Inserting a node in between nodes of a doubly linked list
struct node* addBeforePos(struct node* head, int data, int position);
// Create an entire DLL
struct node* create_DLL(struct node* head);
// Deleting the first node of a DLL
struct node* delFirst(struct node* head);
// Deleting the last node of a DLL
struct node* delLast(struct node* head);
// Deleting the intermediate node of a DLL
struct node* delInter(struct node* head, int position);
// Reversing a DLL
struct node* reverse_DLL(struct node* head);
// Printing a Doubly linked List
void print_DLL(struct node* head);

int main()
{
    printf("\n\n\n");
	struct node* head = NULL;
    struct node* ptr;
    head = create_DLL(head);
    print_DLL(head);
    head = reverse_DLL(head);
    print_DLL(head);

    head = delInter(head, 1);
    print_DLL(head);
    head = delInter(head, 5);
    print_DLL(head);
    head = delInter(head, 3);
    print_DLL(head);

	/*
    head = addToEmpty(head, 45);
    head = addAtBeg(head, 34);
    head = addAtEnd(head, 9);
    head = addAfterPos(head, 777, 3);
    head = addBeforePos(head, 333, 4);
    head = addBeforePos(head, 456, 1);

    head = delFirst(head);
    print_DLL(head);

    head = delLast(head);
    print_DLL(head);
    */    
    printf("\n\n\n");
    return 0;
}

// Inserting a node in an empty list
struct node* addToEmpty(struct node* head, int data)
{
    printf("Inserting a node in an empty list\n");
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	head = temp;
	return head;
}

// Inserting a node at the beginning of a doubly linked list
struct node* addAtBeg(struct node* head, int data)
{
    printf("Inserting a node at the beginning of a Doubly Linked List\n");
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
    temp->next = head;
    head->prev = temp;
	head = temp;
	return head;
}

// Inserting a node at the end of a doubly linked list
struct node* addAtEnd(struct node* head, int data)
{
    printf("Inserting a node at the beginning of a Doubly Linked List\n");
	struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
    tp = head;
    while(tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
	return head;
}


// Inserting a node in between nodes of a doubly linked list
struct node* addAfterPos(struct node* head, int data, int position)
{
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;
    newP = addToEmpty(newP, data);

    while(position != 1)
    {
        temp = temp->next;
        position--;
    }

    temp2 = temp->next;
    
    if (temp->next == NULL)
        { // in case the position is that of the last node
            temp->next = newP;
            newP->prev = temp;
        }
        else
        {
                {
            temp->next = newP;
            newP->prev = temp;
            temp2->prev = newP;
            newP->next = temp2;
        }
    }
    return head;
}

// Inserting a node in between nodes of a doubly linked list
struct node* addBeforePos(struct node* head, int data, int position)
{
    struct node* newP = NULL;
    struct node* temp = head;
    struct node* temp2 = NULL;
    newP = addToEmpty(newP, data);

    while(position > 2)
    {
        temp = temp->next;
        position--;
    }
    if(position == 1)
        head = addAtBeg(head, data);
    else
        {
        temp2 = temp->next;
        temp->next = newP;
        newP->prev = temp;
        temp2->prev = newP;
        newP->next = temp2;
        }      
    return head;
}

// Create an entire DLL
struct node* create_DLL(struct node* head)
{
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n == 0)
        return head;
    
    printf("Enter the element for node 1: ");
    scanf("%d", &data);
    head = addToEmpty(head, data);

    for (i=1; i<n; i++)
    {
        printf("Enter the element for the node %d: ", i+1);
        scanf("%d", &data);
        head = addAtEnd(head, data);
    }
    return head;
}

// Deleting the first node of a DLL
struct node* delFirst(struct node* head)
{
    printf("Deleting the first node\n");
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

// Deleting the last node of a DLL
struct node* delLast(struct node* head)
{
    printf("Deleting the last node\n");
    struct node* ptr;
    ptr = head;
    if(ptr->next == NULL)
    {
        free(ptr);
        ptr = NULL;
        return ptr;
    }
    else
    {
        while(ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
        free(ptr->next);
        ptr->next = NULL;
        return head;
    }    
}

// Deleting the intermediate node of a DLL
struct node* delInter(struct node* head, int position)
{
    printf("Deleting an intermediate node\n");
    struct node* temp = head;
    struct node* temp2 = NULL;
    if (position == 1)
        {
            head = delFirst(head);
            return head;
        }
    while(position > 1)
    {
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL)
        head = delLast(head);
    else 
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
    return head;
}

// Reversing a DLL
struct node* reverse_DLL(struct node* head)
{
    struct node* ptr1 = head;
    struct node* ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

// Printing a Doubly linked List
void print_DLL(struct node* head)
{
    printf("Printing the Doubly Linked List\n");
    struct node* ptr;
    ptr = head;
    if(ptr == NULL)
        printf("List is empty!");
        else
        {
            while(ptr != NULL)
            {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        printf("\n"); // new line
    
}

