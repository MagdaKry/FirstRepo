#include <stdio.h>
#include <stdlib.h>
// Implementation of a Sorted Singly Linked List for Polynomial Arithmetic
struct node {
    float coeff;
	int expo;
	struct node* link;
};

// Creating a polynomial SSLL
struct node* Poly_create(struct node* head);
// Inserting a node in Polynomial SSLL
struct node* Poly_insert(struct node* head, float coeff, int expo);
// Printing the polynomial SSLL
void print_Poly_SSLL(struct node* head);
// Polynomial addition
void polyAdd(struct node* head1, struct node* head2);
// Polynomial multiplication
void polyMult(struct node* head1, struct node* head2);

int main()
{
    printf("\n\n");
    /*
    struct node* head = NULL;
    printf("Enter the polynomial\n ");
    head = Poly_create(head);
    print_Poly_SSLL(head);
    */

    // Polynomial addition
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter the first polynomial\n ");
    head1 = Poly_create(head1);
    printf("Enter the second polynomial\n ");
    head2 = Poly_create(head2);
    polyAdd(head1, head2);
    polyMult(head1, head2);
    return 0;
}

// Creating a polynomial SSLL
struct node* Poly_create(struct node* head)
{
    int n, i;
    float coeff;
    int expo;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter the coefficient for term %d: ", i+1);
        scanf("%f", &coeff);

        printf("Enter the exponent for term %d: ", i+1);
        scanf("%d", &expo);
        head = Poly_insert(head, coeff, expo);
    }
    return head;
}

// Inserting a node in Polynomial SSLL
struct node* Poly_insert(struct node* head, float coeff, int expo)
{
    struct node* temp;
    struct node* newP = malloc(sizeof(struct node));
    newP->coeff = coeff;
    newP->expo = expo;
    newP->link = NULL;

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
    return head;
}

// Polynomial addition
void polyAdd(struct node* head1, struct node* head2)
{
    printf("\n");
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    while(ptr1 != NULL && ptr2 != NULL)
    {
        if(ptr1->expo == ptr2->expo)
        {
            head3 =Poly_insert(head3, ptr1->coeff + ptr2->coeff, ptr1->expo);
            ptr1 = ptr1->link;
            ptr2 = ptr2->link;
        }
        else if(ptr1->expo > ptr2->expo)
        {
            head3 = Poly_insert(head3, ptr1->coeff, ptr1->expo);
            ptr1 = ptr1->link;
        }
        else if(ptr1->expo < ptr2->expo)
        {
            head3 = Poly_insert(head3, ptr2->coeff, ptr2->expo);
            ptr2 = ptr2->link;
        }
    }
    while(ptr1 != NULL)
    {
        head3 = Poly_insert(head3, ptr1->coeff, ptr1->expo);
        ptr1 = ptr1->link;            
    }
    while(ptr2 != NULL)
    {
        head3 = Poly_insert(head3, ptr2->coeff, ptr2->expo);
        ptr2 = ptr2->link;            
    }
    printf("The first polynomial is: ");
    print_Poly_SSLL(head1);
    printf("\n");
    printf("The second polynomial is: ");
    print_Poly_SSLL(head2);
    printf("\n");
    printf("Added polynomial is: ");
    print_Poly_SSLL(head3);
    printf("\n\n\n");
}

// Polynomial multiplication
void polyMult(struct node* head1, struct node* head2)
{
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;

    // Check if first or second polynomial is NULL
    if(head1 == NULL || head2 == NULL)
    {
        printf("Zero polynomial.\n");
        return;
    }
    
    // Multiplication of two polynomials
    float coeff_prod;
    int expo_sum;
    while(ptr1 != NULL)
    {
        while(ptr2 != NULL)
        {
            coeff_prod = ptr1->coeff * ptr2->coeff;
            expo_sum = ptr1->expo + ptr2->expo;
            head3 = Poly_insert(head3, coeff_prod, expo_sum);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
        ptr2 = head2;
    }   

    printf("The first polynomial is: ");
    print_Poly_SSLL(head1);
    printf("\n");
    printf("The second polynomial is: ");
    print_Poly_SSLL(head2);
    printf("\n");

    printf("Before Simplification, Multiplied polynomial is: ");
    print_Poly_SSLL(head3);
    printf("\n");

    // Improvements: Adding the like terms (terms with same exponents) for simplification  
    struct node* ptr3 = head3;
    struct node* temp = NULL;

    while(ptr3->link != NULL)
    {
        if(ptr3->expo == ptr3->link->expo)
        {
            ptr3->coeff = ptr3->coeff + ptr3->link->coeff;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
            temp = NULL;
        }
        else
        {
            ptr3 = ptr3->link;
        }
    }

    printf("After Simplification, Multiplied polynomial is: ");
    print_Poly_SSLL(head3);
    printf("\n\n\n");
    return;
}

// Printing the polynomial SSLL
void print_Poly_SSLL(struct node* head)
{
    if(head == NULL)
        printf("No Polynomial.");
    else 
    {
        struct node* temp = head;
        while(temp != NULL)
        {
            printf("(%.1fx^%d)", temp->coeff, temp->expo);
            temp = temp->link;
            if(temp != NULL)
                printf(" + ");
            else
                printf("\n");
        }
    }
}