#include <stdio.h>
#include <stdlib.h>
// Queues - Linked List Implementation
struct node 
{
    int priority;
    int data;
    struct node* link;
} *front = NULL, *rear = NULL; // Pointers are declared globally

//Prototypes
void enqueue(int n, int priority);
int dequeue();
int peek();
void print();
int isEmpty();

void main()
{
    
    int choice, data, priority;
    while(1)
    {
        printf("\n\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print the first element\n");
        printf("4. Print all the elements\n");
        printf("5. Quit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the element to be added in the queue: ");
                scanf("%d", &data);
                printf("Enter its priority: ");
                scanf("%d", &priority);
                enqueue(data, priority);
                printf("Element is added in the queue successfully.");
                break;
            case 2:
                data = dequeue();
                printf("Deleted element is: %d", data);
                break;
            case 3:
                printf("The first element of the queue is %d\n", peek());
                break;
            case 4: 
                print();
                break;
            case 5:
                exit(1);
            default:
                printf("Wrong choice.\n");
        }
    }


    printf("\n\n\n");
}

void enqueue(int data, int priority)
{
    struct node* temp = NULL;
    struct node* newNode = malloc(sizeof(struct node));
    if(newNode == NULL)
    {
        printf("No memory space in the heap!");
        exit(1);
    }
    newNode->priority = priority;
    newNode->data = data;
    newNode->link = NULL;
    if(isEmpty())
    {
        front = rear = newNode;
    }
    else if(priority < front->priority)
    {
        newNode->link = front;
        front = newNode;
    }
    else
    {
        temp = front;
        while(temp->link != NULL && temp->link->priority <= priority)
            temp = temp->link;
        if(temp->link == NULL)
        {
            temp->link = newNode;
            rear = newNode;
        }
        else
        {
            newNode->link = temp->link;
            temp->link = newNode;
        }    
    }
}

int dequeue()
{
    int data;
    struct node* temp;
    if(isEmpty())
    {
        printf("Queue Underflow!"); // Queue is empty
        exit(1);
    }
    temp = front;
    data = temp->data;
    front = front->link;
    free(temp);
    temp = NULL; 
    return data;   
}

int peek()
{
    if(isEmpty())
    {
        printf("Queue Underflow!"); // Queue is empty
        exit(1);
    }
    return front->data;
}

int isEmpty()
{
    if(front == NULL)
        return 1;
    else 
        return 0;
}

void print()
{
    struct node* temp;
    temp = front;
    if(isEmpty())
    {
        printf("Queue Underflow."); // Queue is empty
        exit(1);
    }
    printf("Queue: \n");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->link;
    }
    printf("\n");
}