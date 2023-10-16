#include <stdio.h>
#include <stdlib.h>
// Example: reverse stack - call by reference
struct node 
{
    int data;
    struct node* link;
};

// Push() function
void push(int data, struct node** top);
// Pop() function
int pop(struct node** top);
// isEmpty() function
int isEmpty(struct node* top);
// Tos() function
int Tos(struct node* top);
// Print() function
void print(struct node* top);

void main()
{
    printf("\n\n\n");
    int data;
    struct node* top = NULL;
    struct node* top1 = NULL;
    struct node* top2 = NULL;
    push(1, &top);
    push(2, &top);
    push(3, &top);
    print(top);
    
    // From original stack to stask 1
    data = pop(&top);
    push(data, &top1);
    data = pop(&top);
    push(data, &top1);
    data = pop(&top);
    push(data, &top1);
    print(top);
    print(top1);

    // From stack 1 to stask 2
    data = pop(&top1);
    push(data, &top2);
    data = pop(&top1);
    push(data, &top2);
    data = pop(&top1);
    push(data, &top2);
    print(top1);
    print(top2);

    // From stack 2 to stask 3
    data = pop(&top2);
    push(data, &top);
    data = pop(&top2);
    push(data, &top);
    data = pop(&top2);
    push(data, &top);
    print(top2);
    print(top);

    printf("\n\n\n");
}

// Push() function
void push(int data, struct node** top)
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

    newNode->link = *top;
    *top = newNode;
}

// Pop() function
int pop(struct node** top)
{
    struct node* temp;
    if(isEmpty(*top))
    {
        printf("Stack Underflow.");
        exit(1);
    }
    int val;
    temp = *top;
    val = temp->data;
    *top = (*top)->link;
    free(temp);
    temp = NULL;
    return val;
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
    printf("The stack elements are: ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}

