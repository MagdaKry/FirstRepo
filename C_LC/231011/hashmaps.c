#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Entry{

    char* key;// pointer !!!name of the value string in C are represented with char pointer ! 
    int   value;


    struct Entry* next; //linked list to handle collisions
} Entry;


//this situation can happen
//hash_function('age') -> 2
//hash_function('city') -> 2
//you do not want losing data in your hashmap
// you need handle collisions so that no data is lost


/**
 *  hash_function compute the hash of key
 *  by summing the characters ASCII code 
 *  and using modulo array_size  
 */
int hash_function(char* key, int array_size){
   

    int sum = 0;
    int i = 0;
    while (key[i] != '\0'){

        sum += (int) key[i];
        i++;
    }

    return sum % array_size; // value -> 0 between array_size
}

/**
 *  hashmap -> Array[Entry]
 */ 
void add_entry(Entry* hashmap, int array_size, char *key, int value){

    int key_index = hash_function(key, array_size);
 
    //if not entry taken we fill it
    if (hashmap[key_index].key == NULL){//no entry 

        hashmap[key_index].key = key;
        hashmap[key_index].value = value;
        hashmap[key_index].next = NULL;
    } 
    else{
        //else we need to loop on all collision entry to add at the end
        Entry* iterator = &hashmap[key_index];

        
        while(iterator->next != NULL){
            iterator = iterator->next;
        }

        Entry* new_entry = (Entry*) calloc(sizeof(Entry), 1);
        iterator->next = new_entry;
        new_entry->key = key;
        new_entry->value = value;
    }
    
}

//no while loop needed to get the entry from hashmap
// much faster for big collection of values!!
Entry* get_entry_by_key(Entry* hashmap, int array_size, char* key){

    int key_index = hash_function(key, array_size);

    if (hashmap[key_index].next == NULL){//no collision 
        return &hashmap[key_index];
    }

    //collisions I need to loop

    Entry* iterator = &hashmap[key_index];
    while(iterator != NULL){

        if (strcmp(iterator->key, key) == 0){ //if key is found return entry
            return iterator;
        }
        iterator = iterator->next;
    }

    return NULL;
}

Entry* create_hashmap(int array_size){

    return (Entry*) calloc(sizeof(Entry), array_size);

}
void test_hashmap_with_collisions(){ //might work need more scenarios
    //idea1 : fill the array 
    //idea2: take an array with size = 1
    //idea3: change the hash function so that it returns always the same value 

    int hashmap_size = 1;
    Entry* hashmap = create_hashmap(hashmap_size); 

    add_entry(hashmap, hashmap_size, "age", 22);
    add_entry(hashmap, hashmap_size, "name", 33); //should collide
    add_entry(hashmap, hashmap_size, "city", 44);  //should collide 


    //printf("k1: %s, v1: %d, k2: %s, v2: %d\n", hashmap[0].key, hashmap[0].value,  hashmap[0].next->key,  hashmap[0].next->value);
    
    //printf("k3: %s, v3: %d\n", hashmap[0].next->next->key, hashmap[0].next->next->value);
    //should print age and name.

    Entry* result = get_entry_by_key(hashmap, hashmap_size, "name");
    printf("entry %p, key: %s, value %d \n", result,result->key, result->value);

}

void test_hashmap_with_bigger_size(){
    int hashmap_size = 5;
    Entry* hashmap = create_hashmap(hashmap_size); 

    add_entry(hashmap, hashmap_size, "age", 22);
    add_entry(hashmap, hashmap_size, "name", 33); //should collide
    add_entry(hashmap, hashmap_size, "city", 44);  //should collide 

    Entry* result = get_entry_by_key(hashmap, hashmap_size, "name");
    printf("entry %p, key: %s, value %d \n", result,result->key, result->value);

}

void main(){
   //test_hashmap_with_collisions();
   test_hashmap_with_bigger_size();
}