#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void add_at_end(struct node *head, int data);
struct node* add_beg(struct node* head, int d);
void add_beg2(struct node** head, int d);
struct node* del_first(struct node* head);
struct node* del_last(struct node* head);
struct node* del_last2(struct node* head);
void add_at_pos(struct node* head, int data, int pos);
void count_of_nodes(struct node *head);
void print_data(struct node *head);

int main(){
    struct node *head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    struct node *current = malloc(sizeof(struct node));
    current->data = 98;
    current->link = NULL;

    head->link = current;

    current = malloc(sizeof(struct node));
    current->data = 3;
    current->link = NULL;

    head->link->link = current;

    count_of_nodes(head);
    print_data(head);
    add_beg2(&head, 777);
    count_of_nodes(head);
    print_data(head);
    add_at_end(head, 555);
    count_of_nodes(head);
    print_data(head);
    /*
    add_beg2(&head, 894);
    count_of_nodes(head);
    print_data(head);
    add_at_end(head, 6733);
    count_of_nodes(head);
    print_data(head);
    */


}

void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked list is empty");
    else 
    {
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            count++;
            ptr = ptr->link;
        }
        printf("Number of nodes = %d\n", count);
    }
}

void print_data(struct node *head)
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

void add_at_end(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data; 
    temp->link = NULL;

    while(ptr->link != NULL){
        ptr = ptr->link;
    }

    ptr->link = temp;
}

struct node* add_beg(struct node* head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = head;
    head = ptr;
    return head; 
}

void add_beg2(struct node** head, int d)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;

    ptr->link = *head;
    *head = ptr;
}

struct node* del_last(struct node* head)
{
    if (head == NULL)
        printf("List is already empty!");
    else if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
    else
    {
        struct node *temp = head;
        struct node *ptr = head;
        while(ptr->link != NULL)
        {
            temp = ptr;
            ptr = ptr->link;
        }
        temp->link = NULL;
        free(ptr);
        ptr = NULL;
    }
    return head;
}

struct node* del_last2(struct node* head)
{
    if (head == NULL)
        printf("List is already empty!");
    else if (head->link == NULL)
        {
            free(head);
            head = NULL;
        }
    else
    {
        struct node *temp = head;
        while(temp->link->link != NULL)
        {
            temp = temp->link;
        }
        free(temp->link);
        temp->link = NULL;
    }
    return head;
}

struct node* del_first(struct node* head)
{
    if (head == NULL)
        printf("List is already empty!");
        else 
        {
            struct node* temp = head;
            head = head->link;
            free(temp);
            temp = NULL;
        }
        return head;
}


void add_at_pos(struct node* head, int data, int pos)
{
    struct node* ptr1 = head;
    struct node* ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while(pos != 1)
    {
        ptr1 = ptr1->link;
        pos--;
    }
    ptr2->link = ptr1->link;
    ptr1->link = ptr2;
}