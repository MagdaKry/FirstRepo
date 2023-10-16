#include<string.h>
#include<stdio.h>
#include <stdlib.h>

typedef struct Node{
    float x;
    struct Node* next;
}Node;

Node* minimum(Node* head)
{
    if (head==NULL)
        return NULL;
    
    float minimum=head->x;
    Node* minimumNode = head;
    
    Node* iterator=head;
    while(iterator!=NULL)
    {
        if (iterator->x<minimum)
        {
            minimum=iterator->x;
            minimumNode=iterator;
        }
        iterator=iterator->next;
    }
    return minimumNode;
}

void main(){
    //it is like a main for testing !
    Node*head=(Node*)malloc(sizeof(Node));
    head->x=1.2;
    head->next=NULL;
    Node*node2=(Node*)malloc(sizeof(Node));
    node2->x=-3.2;
    node2->next=NULL;
    head->next=node2;
    Node*node3=(Node*)malloc(sizeof(Node));
    node3->next=NULL;
    node3->x=4.3;
    node2->next=node3;
    
    Node* result=minimum(head);
    printf("min=%g", result->x);
}
