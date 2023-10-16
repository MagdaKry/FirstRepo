#include "header.h"
#include <stdlib.h>

Node* add_node_at_end_of_list (Node* head, int val)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->value=val;

    Node* iterator=head;

    if (head==NULL)
    {
        return newNode;
    }
    else
    {
        while(iterator->next!=NULL)
        {
            iterator=iterator->next;
        }
        iterator->next=newNode;
        return head;
    }
}