/*
We want to store a collection of data using key / value. To start we will do a naive approch using Linked lists. 

In order to do that we will use a struct named Entry with three members : 

char* key
float value
Entry* next
 

1. Create the struct Entry

2. In the test_main function, create a Linked List with two node. Specify the values  and the key of both nodes and connect node 1 to node 2. 
*/

#include <stdlib.h>

typedef struct Entry{
    char* key;
    float value;
    struct Entry* next;
}Entry;

void test_main(){
    //it is like a main for testing !

    Entry* e1=(Entry*)malloc(sizeof(Entry));
    Entry* e2=(Entry*)malloc(sizeof(Entry));
    e1->key="car";
    e1->value=1;
    e2->key="bicycle";
    e2->value=2;
    e1->next=e2;
    e2->next=NULL;
    
}

/*
Reusing the Struct of the previous exercise

Create a function Entry* add_entry_to_the_end(Entry* head, char* key, float value) which add a new entry at the end of the linked list
*/

#include <stdlib.h>

typedef struct Entry{
    char* key;
    float value;
    struct Entry* next;
}Entry;

Entry* add_entry_to_the_end(Entry* head, char* key, float value)
{
    Entry* newEntry=(Entry*)malloc(sizeof(Entry));
    newEntry->key=key;
    newEntry->value=value;
    newEntry->next=NULL;
    
    Entry* iterator=head;
    
    if (head==NULL)
    {
        return newEntry;
    }
    
    while(iterator->next!=NULL)
    {
        iterator=iterator->next;
    }
    

    iterator->next=newEntry;
    return head;
    
}

void test_main(){
    //it is like a main for testing !

}


/*
Reusing the Struct of the previous exercise

Create a function Entry* get_value_by_key(Entry* head, char* key_to_search) which returns the node matching key_to_search if it has been found and null otherwise. 
*/

#include <stdlib.h>
#include <string.h>

typedef struct Entry{
    char* key;
    float value;
    struct Entry* next;
}Entry;

Entry* get_value_by_key(Entry* head, char* key_to_search)
{
    Entry* iterator=head;
    
    if (head==NULL)
    {
        return NULL;
    }
    
    while(iterator!=NULL)
    {
        if(strcmp(iterator->key,key_to_search)==0)
        {
            return iterator;
        }
        iterator=iterator->next;
    }
    
    return NULL;
}


/*
Create a function simple_hash(char* key, int hasmap_size) which computes the hash of a key.

To compute the hash of key, we will simple summing the characters of string and get the modulo of it by the array size
*/

simple_hash(char* key, int hasmap_size)
{
    int sum=0;
    
    for(int i=0; i<strlen(key); i++)
    {
        sum+=key[i];
    }
    
    int hash;
    hash=sum%hasmap_size;
    
}

/*
Create a function new_hash_map(int size) which initialize on the heap a hashmap. It shall return an array of the Entry struct
*/

Entry ** new_hash_map(int size)
{
    Entry** hashMap = (Entry**) malloc(size*sizeof(Entry*));
    return hashMap;
}

/*
Create a function  add_entry_to_hashmap(Entry* hashmap, int array_size, char* key, int value) which add an entry to the hasmap using the hashmap function.

Get the hashmap function from the previous exercise
*/



