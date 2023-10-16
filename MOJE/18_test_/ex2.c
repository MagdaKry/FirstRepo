#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* prev;
	int data;
	struct node* next;
};

// Inserting a node in an empty list
struct node* addToEmpty(struct node* head, int data);
// Printing a Doubly linked List
void print_DLL(struct node* head);
// Inserting a node at the end of a doubly linked list
struct node* addAtEnd(struct node* head, int data);

int search(struct node* head, int data);
struct node* del(struct node* head, int position);

void print_CDLL(struct node* head);

struct node* transform(struct node* head);

int main()
{
    struct node* list=NULL;

    list=addToEmpty(list,45);
    list=addAtEnd(list,78);
    list=addAtEnd(list,94);
    list=addAtEnd(list,35);
    list=addAtEnd(list,23);
    print_DLL(list);

    int data, data2;
    printf("Enter the number to search: ");
    scanf("%d", &data);
    data2=search(list,data);

    printf("Enter the position to delete: ");
    scanf("%d", &data);
    list=del(list,data);
    print_DLL(list);

    printf("Transform into CDLL:\n");
    list=transform(list);
    print_CDLL(list);

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

int search(struct node* head, int data)
{
    struct node* ptr;
    ptr = head;
    int pos=0;
    if(ptr == NULL)
    {
        printf("List is empty!");
        return -1;
    }
        else
        {
            while(ptr != NULL)
            {
                pos++;
                if (ptr->data==data)
                {
                    printf("%d found at %d position\n", data, pos);
                    return pos;
                }
                ptr = ptr->next;
            }
            return -1;
        }
        
}


struct node* del(struct node* head, int position)
{
    struct node* temp = head;
    struct node* temp2 = NULL;

    if(temp == NULL) //null
    {
        printf("List is empty!");
        return head;
    }

    if (position == 1) //first
        {
            printf("Deleting the first node\n");
            head = head->next;
            free(head->prev);
            head->prev = NULL;
            return head;
        }

    while(position > 1)
    {
        temp = temp->next;
        position--;
    }

    if(temp->next == NULL) //last
    {
        temp2=temp->prev;
        temp2->next = NULL;
        free(temp);
        return head;
    }
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
    printf("\ntail points to element: %d", tail->data);
    printf("\n");
}

struct node* transform(struct node* head)
{  
    struct node* ptr, *temp;
    ptr = head;
    temp = head;
    if(ptr == NULL)
        printf("List is empty!");
        else
        {
            while(ptr->next!= NULL)
            {
                ptr = ptr->next;
            }
        }
    //declaring tail
    head=ptr;
	ptr->next=temp;
    temp->prev=head;
    printf("CDLL created; return tail\n");
    return head;

}