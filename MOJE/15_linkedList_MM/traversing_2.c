#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

void del_at_pos (struct node **head, int position);
struct node* del_list (struct node *head);

struct node* reverse(struct node* head)
{
    struct node* prev=NULL;
    struct node* next=NULL;
    while(head!=NULL)
    {
        next=head->link;
        head->link=prev;
        prev=head;
        head=next;
    }
    head=prev;
    return head;
}

void count_of_nodes(struct node *head)
{
    int count =0;
    if (head==NULL)
        printf ("Linked list is empty");
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL)
        {
            count++;
            ptr=ptr->link;
        }
        printf("count of nodes: %d\n", count);
    }
}

void print_data(struct node *head)
{

    if (head==NULL)
        printf ("Linked list is empty");
    else
    {
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL)
        {
            printf("%d ", ptr->data);
            ptr=ptr->link;
        }
    }
}

void add_at_end(struct node *head, int data)
{
    struct node *ptr, *temp;
    ptr = head;
    
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while (ptr->link!=NULL)
    {
        ptr = ptr->link;
    }
    ptr->link=temp;
}

/*
void delete_at_end(struct node *head)
{
    struct node *ptr, *temp;
    ptr = head;

    while (ptr->link!=NULL)
    {
        temp=ptr;
        ptr = ptr->link;
    }

    free((int*)ptr->data);
    temp->link = NULL; //link do ostatniego
}
*/

struct node* del_last(struct node *head)
{
    if (head==NULL)
        printf ("Linked list is empty");
    else if (head->link==NULL)
    {
            free(head);
            head=NULL;
    }
    else
    {
        struct node *temp = head;
        struct node *ptr = head;
        while(ptr->link !=NULL)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=NULL;
        free(ptr);
        ptr=NULL;
    }

    return head;

}

struct node* del_last2(struct node* head) 
{
    if (head==NULL)
        printf ("Linked list is empty");
    else if (head->link==NULL)
    {
            free(head);
            head=NULL;
    }
    else
    {
        struct node *temp = head;
        while(temp->link->link!=NULL)
        {
            temp=temp->link;
        }
        free(temp->link);
        temp->link=NULL;
    }
    return head;
}

struct node* add_beg(struct node *head, int d)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;
    
    ptr->link = head;
    head = ptr;
    return head;
}

void add_beg2(struct node** head, int d)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data = d;
    ptr->link = NULL;
    
    ptr->link = *head;
    *head = ptr;
}

struct node* del_first(struct node *head)
{
    if (head==NULL)
        printf ("Linked list is empty");
    else
    {
        struct node *temp = head;
        head = head->link;
        free(temp);
        temp=NULL;
    }
    return head;
}

void add_position(struct node *head, int data, int pos)
{
    struct node *ptr1=head;
    struct node *ptr2=(struct node*)malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    /*
    int count=0;
    while(ptr1->link !=NULL)
        {
            if (count==pos)
            {
                ptr2->link=ptr1->link;
                ptr1->link=ptr2;
                break;
            }
            ptr1 = ptr1->link;
            count++;
        }
    */

    pos--;
    while(pos!=1)
    {
        ptr1 = ptr1->link;
        pos--;
    }
    ptr2->link = ptr1->link;
    ptr1->link = ptr2;
}

int main()
{
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
    printf("\n");
    add_beg2(&head, 777);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    add_at_end(head,555);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    //delete_at_end(head);
    
    /*
    head=del_last(head);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    head=del_last2(head);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    head=del_first(head);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    */
    add_position(head, 444, 2);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    del_at_pos(&head, 2);
    count_of_nodes(head);
    print_data(head);
    printf("\n");
    reverse(head);
    count_of_nodes(head);
    print_data(head);
    printf("\n");

    return 0;
}


void del_at_pos (struct node **head, int position)
{
    struct node* current = *head;
    struct node* previous = *head;
    if (*head == NULL)
    {
        printf("List is already empty!");
        return;
    }
    if(position==1)
    {
        *head=current->link;
        free(current);
        current=NULL;
    }
    else
    {
        while(position!=1)
        {
            previous = current;
            current=current->link;
            position--;
        }
        previous->link = current->link;
        free(current);
        current=NULL;
    }
}

struct node*  del_list (struct node *head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        temp = temp->link;
        free(head);
        head=temp;
    }
    return head; //should be pointing to null
}