#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node *link;
};

int main()
{
    /* ---one node---
    struct node *head = NULL;
    head = (struct node*)malloc(sizeof(struct node));
    head -> data = 45;
    head -> link = NULL;
    printf ("%d", head->data);

    free(head);
    head = NULL;
    return 0;
    */

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

   /*
   struct node *current2 = malloc(sizeof(struct node));
   current2->data = 3;
   current2->link = NULL;

   current->link = current2;
   */

   printf ("%d ", head->data);
   printf ("%d ", head->link->data);
   printf ("%d ", (*current).data);
   printf ("%d ", head->link->link->data);
   //printf ("%d ", current->data);
   //printf ("%d ", current2->data);

   free(head);
   head = NULL;
   free(head->link);
   head->link = NULL;
   free(current);
   current = NULL;
   //free(current2);
   //current2 = NULL;

   return 0;

}