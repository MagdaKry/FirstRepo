#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* prev;
	int data;
	struct node* next;
};


void addToEmpty(struct node** head, int data);

void print_DLL(struct node** head);

void addAtEnd(struct node** head, int data);

int search(struct node** head, int data);
void del(struct node** head, int position);

void print_CDLL(struct node** head);

void transform(struct node** head);

void sort_desc(struct node** head);
void insert_desc(struct node** head, int data);

int main()
{
    struct node* list=NULL;
    
    addToEmpty(&list,45);
    addAtEnd(&list,78);
    addAtEnd(&list,64);
    addAtEnd(&list,35);
    addAtEnd(&list,23);
    
    //test
    /*
    addToEmpty(&list,4);
    addAtEnd(&list,7);
    addAtEnd(&list,6);
    addAtEnd(&list,8);
    addAtEnd(&list,3);
    */
    print_DLL(&list);

    int data, data2;
    printf("Enter the number to search: ");
    scanf("%d", &data);
    data2=search(&list,data);
    
    printf("Enter the position to delete: ");
    scanf("%d", &data);
    del(&list,data);
    print_DLL(&list);

    printf("Sorting DLL:\n");
    printf("before:\n");
    sort_desc(&list);
    printf("after:\n");
    print_DLL(&list);

    printf("Transform into CDLL:\n");
    transform(&list);
    print_CDLL(&list);

    return 0;
}


void addToEmpty(struct node** head, int data)
{
    printf("Inserting a node in an empty list\n");
	struct node* temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
	*head = temp;
	//return *head;
}


void addAtEnd(struct node** head, int data)
{
    //printf("Inserting a node at the beginning of a Doubly Linked List\n");
	struct node *temp, *tp;
    temp = malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->data = data;
	temp->next = NULL;
    tp = *head;
    while(tp->next != NULL)
        tp = tp->next;
    tp->next = temp;
    temp->prev = tp;
	//return *head;
}


void print_DLL(struct node** head)
{
    printf("Printing the Doubly Linked List\n");
    struct node* ptr;
    ptr = *head;
    if(ptr == NULL)
        printf("List is empty!");
        else
        {
            while(ptr != NULL)
            {
                printf("%d ", ptr->data);
                ptr = ptr->next;
            }
        }
        printf("\n"); // new line
    
}

int search(struct node** head, int data)
{
    struct node* ptr;
    ptr = *head;
    int pos=0;
    if(ptr == NULL)
    {
        printf("List is empty!");
        return -1;
    }
        else
        {
            while(ptr != NULL)
            {
                pos++;
                if (ptr->data==data)
                {
                    printf("%d found at %d position\n", data, pos);
                    return pos;
                }
                ptr = ptr->next;
            }
            printf("Not found!");
            return -1;
        }
        
}


void del(struct node** head, int position)
{
    struct node* temp = *head;
    struct node* temp2 = NULL;

    if(temp == NULL) //null
    {
        printf("List is empty!");
        return; //*head;
    }

    if (position == 1) //first
        {
            //printf("Deleting the first node\n");
            *head = (*head)->next;
            free((*head)->prev);
            (*head)->prev = NULL;
            return; // *head;
        }

    while(position > 1)
    {
        temp = temp->next;
        position--;
    }
    //printf("After while!");

    if(temp->next == NULL) //last
    {
        temp2=temp->prev;
        temp2->next = NULL;
        free(temp);
        //printf("It was last!");
        return; // *head;
    }
    else 
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
        //printf("Done!");
    }
    return; //*head;
}



void print_CDLL(struct node** tail)
{
    if(*tail == NULL)
    {
        printf("No element in the List.\n");
        return;
    }    
    struct node* temp = (*tail)->next;
    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != (*tail)->next);
    printf("\ntail points to element: %d", (*tail)->data);
    printf("\n");
}

void transform(struct node** head)
{  
    struct node* ptr, *temp;
    ptr = *head;
    temp = *head;
    if(ptr == NULL)
        printf("List is empty!");
        else
        {
            while(ptr->next!= NULL)
            {
                ptr = ptr->next;
            }
        }
    //declaring tail
    *head=ptr;
	ptr->next=temp;
    temp->prev=*head;
    printf("CDLL created; return tail\n");
    return; //*head;

}

void sort_desc(struct node** head)
{
    struct node* temp = NULL;
    struct node* ptr = *head;
    struct node* temp2 = NULL;
    struct node* temp3 = NULL;
    int pos=0;
    int count=0;

    if(*head == NULL)
    {
        printf("List is empty!");
    }
    else
    {
        while(ptr!=NULL)
        {
            count++;
            //printf("start of first while\n");
            insert_desc(&temp2, ptr->data);
            //print_DLL(&temp2);
            //printf("after insert\n");
            ptr=ptr->next;
            //printf("end of first while\n");
        }
    }
    temp3=temp2;
    print_DLL(head);
    for(pos=count;pos>0;pos--)
        {
            //printf("start of first while - copy desc\n");
            del(head, pos);
            //print_DLL(head);
            addAtEnd(head, temp3->data);
            //printf("after insert\n");
            //print_DLL(head);
            temp3=temp3->next;
            //printf("end of first while - copy desc\n");
        }
}

void insert_desc(struct node** head, int data)
{
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->data=data;
    newP->prev = NULL;
    newP->next = NULL;

    int key = data;
    //if(head == NULL || grade <= head->grade)
    if(*head == NULL || data >= (*head)->data)
    {
        newP->prev = *head;
        newP->next = *head;
        *head = newP;
    }
    else
    {
        temp = *head;
        //while(temp->link != NULL && temp->link->grade <= grade)
        while(temp->next != NULL && temp->next->data >= data)
            temp = temp->next;
        if (temp->next==NULL)
        {
            temp->next=newP;
            newP->prev=temp;
            newP->next=NULL;
        }
        else
        {
            newP->next = temp->next;
            newP->prev = temp;
            temp->next->prev=newP;
            temp->next = newP;
        }
    }
}