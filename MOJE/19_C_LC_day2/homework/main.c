/*
+ Create folder homework
+ Create three files:  header.h, main.c lib.c
+ in header.h create a struct letting you define a Linked List name Node
+ Create a function add_node_at_end_of_list which lets you add a node to the end of a linked list
+ in your main.c, create a One node linked list and use your function add element to it
+ display the result
+ compile the files using gcc header.h main.c lib.c command in your terminal
+ make everything work
bonus : do a real unit test of add_node_at_end_of_list function
*/

#include "header.h"
#include <stdlib.h>
#include <stdio.h>

void print_SLL(Node* head)
{
    Node* iterator=head;

    if (head==NULL)
    {
        printf("empty list");
    }
    else if(head->next==NULL)
    {
        printf("%d ", iterator->value);
    }
    else
    {
        while(iterator!=NULL)
        {
            printf("%d ", iterator->value);
            iterator=iterator->next;
        }
    }
}

int testNode (Node* node_test1, Node* node_test2)
{
    if(node_test1->value!=node_test2->value)
        return 1;
    else 
        return 0;
}

void test_add_node_at_end_of_list ()
{
    //scenario 1
    Node* myList_test1=NULL;
    myList_test1=add_node_at_end_of_list(myList_test1,18);

    Node* myList_actual1=(Node*)malloc(sizeof(Node));
    myList_actual1->next=NULL;
    myList_actual1->value=17;
    //myList_actual1->value=18;

    if(testNode(myList_test1, myList_actual1)==1)
    {
        printf("\nBUG in line %d", __LINE__); 
    }

    printf("\n test1 SLL: ");
    print_SLL(myList_test1);
    printf("\n actual1 SLL: ");
    print_SLL(myList_actual1);

    //scenario 2
    Node* myList_actual2=(Node*)malloc(sizeof(Node));
    myList_actual2->next=NULL;
    myList_actual2->value=5;

    Node* myList_actual2_current=(Node*)malloc(sizeof(Node));
    myList_actual2_current->next=NULL;
    myList_actual2_current->value=12;

    myList_actual2->next=myList_actual2_current;

    Node* myList_actual2_current2=(Node*)malloc(sizeof(Node));

    myList_actual2_current2->next=NULL;
    myList_actual2_current2->value=211;
    //myList_actual2_current2->value=21;

    myList_actual2->next->next=myList_actual2_current2;

    Node* myList_test2=(Node*)malloc(sizeof(Node));
    myList_test2->next=NULL;
    myList_test2->value=5;

    Node* myList_test2_current=(Node*)malloc(sizeof(Node));
    myList_test2_current->next=NULL;
    myList_test2_current->value=12;

    myList_test2->next=myList_test2_current;

    myList_test2=add_node_at_end_of_list(myList_test2,21);

    if(testNode(myList_test2, myList_actual2)==1)
    {
        printf("\nBUG in line %d", __LINE__); 
    }
    if(testNode(myList_test2->next, myList_actual2->next)==1)
    {
        printf("\nBUG in line %d", __LINE__); 
    }
    if(testNode(myList_test2->next->next, myList_actual2->next->next)==1)
    {
        printf("\nBUG in line %d", __LINE__); 
    }

    printf("\n test2 SLL: ");
    print_SLL(myList_test2);
    printf("\n actual2 SLL: ");
    print_SLL(myList_actual2);
}

int main()
{
    Node* myList=(Node*)malloc(sizeof(Node));

    myList->next=NULL;
    myList->value=5;

    printf("before: ");
    print_SLL(myList);

    printf("\n---adding node---");
    myList=add_node_at_end_of_list(myList, 8);

    printf("\nafter: ");
    print_SLL(myList);

    test_add_node_at_end_of_list ();

    return 0;
}