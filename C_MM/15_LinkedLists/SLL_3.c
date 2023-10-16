#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
};

void count_of_nodes(struct node *head);
void print_data(struct node *head);

int main(){
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

}

void count_of_nodes(struct node *head)
{
    int count = 0;
    if (head == NULL)
        printf("Linked list is empty");
    else 
    {
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            count++;
            ptr = ptr->link;
        }
        printf("Number of nodes = %d\n", count);
    }
}

void print_data(struct node *head)
{
    if (head == NULL)
        printf("Linked list is empty");
    else
    {
        printf("The data stored in the list:\n");
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            printf("%d ", ptr->data);
            ptr = ptr->link;
        }
    }
}