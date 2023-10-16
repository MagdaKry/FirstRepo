#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
    int no;
    char name[30];
    int grade;
    struct node* link;
};

struct node* list_create(struct node* head);

struct node* list_insert(struct node* head, int no, char name[], int grade);

int list_search(struct node* head, int no);

void print_list(struct node *head);

void del_pos(struct node **head, int position);

//struct node* sort_desc(struct node* head);

struct node* merge(struct node* head1, struct node* head2);

void main()
{
    int choice, data, data2;
    printf("Employee Management System\n");
    printf("Initial List1:\n");
    struct node* list1 = NULL;
    list1=list_insert(list1, 1, "John", 5);
    list1=list_insert(list1, 8, "Adam", 1);
    list1=list_insert(list1, 3, "Anne", 3);
    list1=list_insert(list1, 9, "David", 2);
    list1=list_insert(list1, 5, "Eve", 4);
    print_list(list1);
    struct node* list2 = NULL;
    printf("List2 to be merged with List1:\n");
    list2=list_insert(list2, 11, "John2", 1);
    list2=list_insert(list2, 88, "Adam2", 5);
    list2=list_insert(list2, 33, "Anne2", 3);
    list2=list_insert(list2, 99, "David2", 4);
    list2=list_insert(list2, 55, "Eve2", 2);
    print_list(list2);

    while(1)
    {
        printf("1. Inserting a new entry into the records\n");
        printf("2. Deleting an existing entry from the records by the employee number\n");
        printf("3. Displaying the records\n");
        printf("4. Searching within the records by the employee number\n");
        printf("5. Quit\n");
        printf("6. Sort descending by grades\n");
        printf("7. Merge with List2\n");
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            list_create(list1);
            break;
        case 2:
            printf("Enter the number of employee to delete: ");
            scanf("%d", &data);
            data2=list_search(list1,data);
            if(data2!=-1)
            {
            del_pos(&list1, data2);
            }
            break;
        case 3:
            print_list(list1);
            break;
        case 4: 
            printf("Enter the number to search: ");
            scanf("%d", &data);
            data2=list_search(list1, data);
            printf("Position in list: %d\n", data2);
            break;
        case 5:
            exit(1);
        case 6:
            //list1=sort_desc(list1);
            printf("After sorting by grades: ");
            print_list(list1);
        case 7:
            list1=merge(list1, list2);
            printf("After merge: ");
            print_list(list1);
        default:
            printf("Wrong choice\n");
        }
    }
}

struct node* list_create(struct node* head)
{
    int n, i;
    int no;
    char name[30];
    int grade;

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the Name of %d. employee: (max. 30 characters)", i+1);
        scanf("%s",name);

        printf("Enter the %d. Employee Number: ", i+1);
        scanf("%d", &no);

        printf("Designation/Grade (from 1 to 5) of %d. employee: ", i+1);
        scanf("%d", &grade);
        if (grade>5 || grade<1)
        {
            printf("wrong grade - once again\n");
            i--;
            continue;
        }

        head = list_insert(head, no, name, grade);
    }

    return head;
}

struct node* list_insert(struct node* head, int no, char name[], int grade)
{
    struct node *ptr, *temp;
    ptr = head;
    
    temp = (struct node*) malloc(sizeof(struct node));
    temp->no = no; 
    temp->grade = grade;
    strcpy(temp->name, name);
    temp->link=NULL;

    if (ptr==NULL)
    {
        head = temp;
        return head;
    }
    if(ptr->link==NULL)
    {
        ptr->link=temp;
        return head;
    }
    while(ptr->link != NULL){
        ptr = ptr->link;
    }
    ptr->link = temp;
    return head;
}

void print_list(struct node *head)
{
    if (head == NULL)
        printf("List is empty");
    else
    {
        printf("The list:\n");
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            printf("No: %d. - Name: %s - Grade: %d ", ptr->no, ptr->name, ptr->grade);
            ptr = ptr->link;
            printf("\n");
        }
        printf("\n");
    }
}

int list_search(struct node* head, int no)
{
    int index=0;
    if (head == NULL)
    {
        printf("List is empty");
        return -1;
    }
    else
    {
        printf("Search no: %d\n", no);
        struct node *ptr = NULL;
        ptr = head;
        while(ptr != NULL){
            index++;
            if(ptr->no==no)
            {
                printf("No: %d. - Name: %s - Grade: %d ", ptr->no, ptr->name, ptr->grade);
                return index;
            }            
            ptr = ptr->link;
        }
        printf("Employee not found\n");
    }
    return -1;
}

void del_pos(struct node **head, int position)
{
    struct node* current = *head;
    struct node* previous = *head;

    if(*head == NULL)
    {
        printf("List is empty!");
    }
    else if(position == 1)
    {
        *head = current->link;
        free(current);
        current = NULL;
    }
    else
    {
        while(position != 1)
            {
                previous = current;
                current = current->link;
                position--;
            }
        previous->link = current->link;
        free(current);
        current = NULL;
    }
}

/*
struct node* sort_desc(struct node* head)
{

    struct node *ptr, *temp;
    temp;
    ptr = head;


    temp = (struct node*) malloc(sizeof(struct node));
    temp->no = no; 
    temp->grade = grade;
    strcpy(temp->name, name);
    temp->link=NULL;

    if (ptr==NULL)
    {
        printf("List is empty!");
        return head;
    }

    while(ptr != NULL){
            if(temp==NULL)
            {
                temp=ptr;
                temp->link=NULL;
            }
            else
            {
                if(ptr->link->grade > ptr->expo) // arrange in descending order
    { // for testing the first node
        newP->link = head;
        head = newP;
    }   
                ptr = ptr->link;
            } 
        }

    if(head == NULL || expo > head->expo) // arrange in descending order
    { // for testing the first node
        newP->link = head;
        head = newP;
    }
    else
    { // for the other nodes
        temp = head;
        while(temp->link != NULL && temp->link->expo > expo) // arrange in descending order
            temp = temp->link;
        newP->link = temp->link;
        temp->link = newP;
    }

    temp=head;
    return head;

}

*/

struct node* merge(struct node* head1, struct node* head2)
{
    if (head1 == NULL || head2==NULL)
    {
        printf("One of lists is empty");
        return head1;
    }
    else
    {
        struct node *ptr;
        ptr = head1;

        while(ptr->link != NULL){
            ptr = ptr->link;
        }

        ptr->link = head2;
        
        return head1;
    }
}