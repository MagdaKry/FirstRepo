#include <stdio.h>
#include <stdlib.h>
// SLL implementation of the Stack
struct node 
{
    int data;
    struct node* link;
}*topMain=NULL; 
struct node *stack1=NULL, *stack2=NULL;

// Push() function
struct node* push(struct node* top, int data);
// Pop() function
int pop(struct node** top);
// isEmpty() function
int isEmpty(struct node* top);
// peek() function
int peek(struct node* top);
// Print() function
void print(struct node* top);
void reverse(struct node* top);

void main()
{
    int choice, data;

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
            topMain=push(topMain, data);
            break;
        case 2:
            data=pop(&topMain);
            printf("Deleted element is %d\n, data");
            break;
        case 3:
            printf("The topmost element of the stack is %d\n", peek(topMain));
            break;
        case 4: 
            print(topMain);
            break;
        case 5:
            exit(1);
        case 6:
            reverse(topMain);  
            print(topMain);      
        default:
            printf("Wrong choice\n");
        }
    }
}

// Push() function
struct node* push(struct node* top, int data)
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

    newNode->link = top;
    top = newNode;
    return top;
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

void reverse(struct node* top)
{
    if (isEmpty(top))
    {
        printf("Stack underflow!");
        exit(1);
    }

    while(top!=NULL)
    {
        stack1=push(stack1, pop(&top)); //do stack1
        top=top->link;
    }

    while(stack1!=NULL)
    {
        stack2=push(stack2, pop(&stack1)); //do stack1
        stack1=stack1->link;
    } 

    while(stack2!=NULL)
    {
        top=push(top, pop(&stack2)); //do stack1
        stack2=stack2->link;
    } 

}