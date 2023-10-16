#include <stdio.h>
#include <stdlib.h>
// SLL implementation of the Stack
struct node 
{
    int data;
    struct node* link;
};
//} *top = NULL;

// Push() function
void push(int data, struct node** top);
// Pop() function
int pop(struct node** top);
// isEmpty() function
int isEmpty(struct node* top);
// peek() function
int peek(struct node* top);
// Print() function
void print(struct node* top);
void reverse_stack(struct node** top);

void main()
{
    int choice, data;
    struct node *top1=NULL;

    while(1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("6. Reverse\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data, &top1);
            break;
        case 2:
            data = pop(&top1);
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            printf("The topmost element of the stack is %d\n", peek(top1));
            break;
        case 4: 
            print(top1);
            break;
        case 5:
            exit(1);
        case 6:
            reverse_stack(&top1);        
            break;
        default:
            printf("Wrong choice\n");
        }
    }
}

// Push() function
void push(int data, struct node** top)
{
    struct node* newNode;
    newNode = malloc(sizeof(newNode));
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
    temp = *top;
    if(isEmpty(*top))
    {
        printf("Stack Underflow.");
        exit(1);
    }

    int val = temp->data;
    *top = temp->link;
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

// peek() function
int peek(struct node* top)
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

void reverse_stack(struct node** top)
{
    struct node *stack1=NULL;
    struct node *stack2=NULL;

    if (isEmpty(*top))
    {
        printf("Stack underflow!");
        exit(1);
    }

    struct node* temp=NULL;
    while(*top!=NULL)
    {
        temp=*top;
        temp=temp->link;
        push(pop(top),&stack1);
        printf("Step one done\n");
        *top=temp;
        print(stack1);
    }

    while(stack1!=NULL)
    {
        temp=stack1;
        temp=temp->link;
        push(pop(&stack1),&stack2);
        stack1=temp;
        printf("Step two done\n");
        print(stack2);
    } 

    while(stack2!=NULL)
    {
        temp=stack2;
        temp=temp->link;
        push(pop(&stack2),top);
        stack2=temp;
        printf("Step three done\n");
        print(*top);
    } 
}