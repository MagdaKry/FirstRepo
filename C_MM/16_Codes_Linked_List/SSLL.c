#include <stdio.h>
#include <stdlib.h>
// Implementation of a Sorted Singly Linked List
struct node {
	int data;
	struct node* link;
};

// Inserting a node in Sorted Singly Linked List
struct node* insert(struct node* head, int data);
// Printing the elements of the SSLL
void print_SSLL(struct node *head);

void main()
{
    struct node* head = NULL;
    head = insert(head, 5);
    print_SSLL(head);
    head = insert(head, 10);
    print_SSLL(head);
    head = insert(head, 4);
    print_SSLL(head);
    head = insert(head, 6);
    print_SSLL(head);
    head = insert(head, 19);
    print_SSLL(head);
    head = insert(head, 3);
    print_SSLL(head);

}

// Inserting a node in Sorted Singly Linked List
struct node* insert(struct node* head, int data)
{
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->link = NULL;

    int key = data;
    if(head == NULL || key < head->data)
    {
        newP->link = head;
        head = newP;
    }
    else
    {
        temp = head;
        while(temp->link != NULL && temp->link->data < key)
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}

// Printing the elements of the SSLL
void print_SSLL(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty");
    else
    {
        printf("The data stored in the list:\n");
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}
