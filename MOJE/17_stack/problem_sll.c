#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node* create_by_add_at_end (struct node* head, int data);
void print(struct node* head);
int search (struct node* head, int data);
void delete_at_pos(struct node **head, int position);

void main()
{
    int choice, data, size;
    struct node* head = NULL;

    while(1)
    {
        printf("1. Create SLL\n");
        printf("2. Print\n");
        printf("3. Search for element\n");
        printf("4. Delete at position\n");
        printf("5. Quit\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            /*
            //user input
            printf("How many elements?");
            scanf("%d", &size);
            for (int i=0; i<size; i++)
            {
                printf("%d element?", i+1);
                scanf("%d", &data);
                head=create_by_add_at_end(head, data);
            }
            */
            //predefined list
            head=create_by_add_at_end(head, 34);
            head=create_by_add_at_end(head, 56);
            head=create_by_add_at_end(head, 764);
            head=create_by_add_at_end(head, 24);
            head=create_by_add_at_end(head, 94);
            break;
        case 2:
            printf("Your list:\n");
            print(head);
            printf("\n");
            break;
        case 3:
            printf("What should be searched?");
            scanf("%d", &data);
            if(search(head, data)==-1)
            {
                printf("The element %d not found", data);
            }
            else
            {
                printf("The element %d is at position %d\n", data, search(head, data));
            }
            break;
        case 4: 
            printf("At which position delete?");
            scanf("%d", &data);
            delete_at_pos(&head,data);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}

struct node* create_by_add_at_end (struct node* head, int data)
{
    struct node *ptr, *temp;
    //temp pointer to head
    ptr = head;
    
    //new node
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data; 
    temp->link = NULL;

    if (head==NULL)
    {
        head=temp;
        return head;
    }

    while(ptr->link != NULL)
    {
        ptr = ptr->link;
    }

    ptr->link = temp;
    return head;
}

void print(struct node* head)
{
    struct node *ptr;
    //temp pointer to head
    ptr = head;

    if (head==NULL)
    {
        printf("Empty list");
        return;
    }
        
    while(ptr!= NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->link;
    }
}

int search (struct node* head, int data)
{
    struct node *ptr;
    //temp pointer to head
    ptr = head;

    int position = 1;

    if (head==NULL)
    {
        printf("Empty list");
        return -1;
    }
        
    while(ptr!= NULL)
    {
        if(ptr->data==data)
        {
            return position;
        }
        ptr = ptr->link;
        position=position+1;
    }
    return -1;

}

void delete_at_pos(struct node **head, int position)
{
    struct node *prev=*head;
    struct node *curr=*head;

    if (*head==NULL)
    {
        printf("Empty list");
    }
    else if(position==1)
    {
        *head=curr->link;
        free(curr);
        curr=NULL;
    }
    else
    {
        while(position!=1)
        {
            prev=curr;
            curr=curr->link;
            position--;
        }
        prev->link=curr->link;
        free(curr);
        curr=NULL;
    }  
}