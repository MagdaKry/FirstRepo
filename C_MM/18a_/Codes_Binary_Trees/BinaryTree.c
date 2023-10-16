#include <stdio.h>
#include <stdlib.h>

struct node
{ // Self Referential Structure to represent a node in a Binary Tree
    struct node* left;
    int data;
    struct node* right;
};

struct node* createTree();
void preorder(struct node* root);

void main()
{
    struct node* root = createTree();
    preorder(root);
}

struct node* createTree()
{
    int input, data;
    printf("Add a new node? ( Yes:1 / No:0 ): ");
    scanf("%d", &input);
    if(!input)
        return NULL;
    else
    {
        struct node* newNode = malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);
        newNode->data = data;
        printf("Left child of %d\n", newNode->data);
        newNode->left = createTree();
        printf("Right child of %d\n", newNode->data);
        newNode->right = createTree();
        return newNode;
    }
}

void preorder(struct node* root)
{
    if(root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}