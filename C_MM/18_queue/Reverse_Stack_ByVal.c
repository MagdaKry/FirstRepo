#include <stdio.h>
#include <stdlib.h>
// Example: reverse stack - call by value
struct node 
{
    int data;
    struct node* link;
};

// Push() function
struct node* push(int data, struct node* top);
// Pop() function
struct node* pop(struct node* top);
// isEmpty() function
int isEmpty(struct node* top);
// Tos() function
int Tos(struct node* top);
// Print() function
void print(struct node* top);

void main()
{
    printf("\n\n\n");
    struct node* top = NULL;
    struct node* top1 = NULL;
    struct node* top2 = NULL;
    struct node* temp = NULL;
    top = push(1, top);
    top = push(2, top);
    top = push(3, top);
    print(top);
    temp = pop(top);
    top = temp->link;
    top1 = push(temp->data, top1);
    temp = pop(top);
    top = temp->link;
    top1 = push(temp->data, top1);
    print(top);
    print(top1);

    printf("\n\n\n");
}

// Push() function
struct node*  push(int data, struct node* top)
{
    struct node* newNode;
    newNode = malloc(sizeof(struct node));
    if(newNode == NULL)
    { // malloc function returns NULL when the requested memory cannot be allocated
        printf("Stack Overflow.");
        exit(1); // exit with failure status
    }
    newNode->data = data;
    newNode->link = NULL;

    newNode->link = top;
    top = newNode;
    return top;
}

// Pop() function
struct node* pop(struct node* top)
{
    struct node* temp;
    if(isEmpty(top))
    {
        printf("Stack Underflow.");
        exit(1);
    }
    temp = top;;
    return temp;
}

// isEmpty() function
int isEmpty(struct node* top)
{
    if(top == NULL)
        return 1;
    else 
        return 0;
}

// Tos() function
int Tos(struct node* top)
{
    if(isEmpty(top))
    {
        printf("Stack Underflow.");
        exit(1);
    }
    return top->data;
}

// Print() function
void print(struct node* top)
{
    struct node* temp;
    temp = top;
    if(isEmpty(top))
    {
        printf("Stack Underflow.");
        exit(1);
    }
    printf("The stack elements are: ");
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

