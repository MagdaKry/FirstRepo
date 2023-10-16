typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node* add_node_at_end_of_list (Node* head, int val);