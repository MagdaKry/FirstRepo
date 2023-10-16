#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
} *top=NULL;

void push(int data);
int pop();
int isEmpty();
int tos();
void print();

void main()
{
    int choice, data;
    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top of stack (TOS)\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please enter your choice: \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;
            case 2:
                data = pop();
                printf("deleted element is %d\n", data);
                break;
            case 3:
                printf("the top of stack is %d\n", tos());
                break;
            case 4:
                print();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice.");
        }
    }

}

void push(int data)
{
    struct node* newNode;
    newNode = malloc(sizeof(struct node*));
    if(newNode==NULL)
    {
        printf("Stack overflow!");
        exit(1);//exit with failure status
    }
    newNode->data=data;
    newNode->link=NULL;

    newNode->link=top;
    top=newNode; 
}

int pop()
{
    struct node* temp=top;
    if (isEmpty())
    {
        printf("Stack underflow!");
        exit(1);
    }
    int val = temp->data;
    top=top->link;
    free(temp);
    temp=NULL;
    return val;
}

int isEmpty()
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

int tos()
{
    if (isEmpty())
    {
        printf("Stack underflow!");
        exit(1);
    }
    return top->data;
}

void print()
{
    struct node* temp=top;
    while(temp!=NULL)
    {
        printf("%d ", temp->data);
        temp=temp->link;
    }
    printf("\n");
}

void reverse()
{
    struct node* stack1 = NULL;
    struct node* stack2 = NULL;
    if (isEmpty())
    {
        printf("Stack underflow!");
        exit(1);
    }

    struct node* temp=top;
    while(temp!=NULL)
    {
        push(temp->data)
        temp=temp->link;
    }

}