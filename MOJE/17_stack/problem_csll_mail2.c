#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create_by_add_at_end (struct node* tail, int data);
void print(struct node* tail);
int search (struct node* tail, int data);
void delete_at_pos(struct node **tail, int position);

void main()
{
    int choice, data, size;
    struct node* tail = NULL;

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
                tail=create_by_add_at_end(tail, data);
            }
            */
            //predefined list
            tail=create_by_add_at_end(tail, 34);
            tail=create_by_add_at_end(tail, 56);
            tail=create_by_add_at_end(tail, 764);
            tail=create_by_add_at_end(tail, 24);
            tail=create_by_add_at_end(tail, 94);
            break;
        case 2:
            printf("Your list:\n");
            print(tail);
            printf("\n");
            break;
        case 3:
            printf("What should be searched?");
            scanf("%d", &data);
            if(search(tail, data)==-1)
            {
                printf("The element %d not found", data);
            }
            else
            {
                printf("The element %d is at position %d\n", data, search(tail, data));
            }
            break;
        case 4: 
            printf("At which position delete?");
            scanf("%d", &data);
            delete_at_pos(&tail,data);
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
}

struct node* create_by_add_at_end (struct node* tail, int data)
{
    struct node *temp;
    
    //new node
    temp = (struct node*) malloc(sizeof(struct node));
    temp->data = data; 
    temp->next = NULL;

    if(tail==NULL)
    {
        temp->data = data;
        temp->next = temp;
        return temp;
    }

    temp->next = tail->next;
    tail->next = temp;
    tail = tail->next;

    return tail;
}

void print(struct node* tail)
{
    struct node *ptr;
    //temp pointer to tail
    ptr = tail->next;

    if (tail==NULL)
    {
        printf("Empty list");
        return;
    }
        
    do
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr!= tail->next);
}

int search (struct node* tail, int data)
{
    struct node *ptr;
    //temp pointer to tail
    ptr = tail->next;

    int position = 1;

    if (tail==NULL)
    {
        printf("Empty list");
        return -1;
    }
        
    do
    {
        if(ptr->data==data)
        {
            return position;
        }
        ptr = ptr->next;
        position=position+1;
    }while(ptr!= tail->next);

    return -1;

}

void delete_at_pos(struct node **tail, int position)
{
    struct node *temp1, *temp2, *ptr;
    //temp pointer to tail
    temp1 = *tail;
    temp2 = *tail;
    ptr = *tail;

    if (*tail==NULL)
    {
        printf("Empty list");
    }
    else if(position==1)
    {
        temp1=temp2->next;
        temp2=temp1->next;
        ptr->next=temp2;
        free(temp1);
        temp1=NULL;
    }
    else
    {
        while(position!=1)
        {
            temp1=temp1->next;
            position--;
        }
        temp2=temp1->next;
        temp1->next=temp2->next;
        if(temp2==*tail)
        {
            *tail=temp1;
        }
        free(temp2);
        temp2=NULL;
    }  
}