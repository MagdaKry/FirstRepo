#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Entry{
    char* key;
    int value;
    struct Entry* next;
}Entry;

Entry * new_hash_map(int size)
{
    //Entry* hashMap = (Entry*)malloc(size*sizeof(Entry));
    Entry* hashMap = (Entry*)calloc(sizeof(Entry), size);

    return hashMap;
}

int simple_hash(char* key, int hashmap_size)
{
    int sum=0;
    
    for(int i=0; i<strlen(key); i++)
    {
        sum+=(int)key[i];
    }
    
    int hash=sum%hashmap_size;
    return hash;
    
}

void add_entry_to_hashmap(Entry* hashmap, int array_size, char* key, int value)
{
    int index=simple_hash(key, array_size);
    //printf("%d index inside add",index);

    Entry* newEntry = (Entry*) calloc(sizeof(Entry),1);
    newEntry->key = key;
    newEntry->value = value;
    newEntry->next = NULL;

    Entry* iterator=&hashmap[index];

    if (hashmap[index].key==NULL)
    {
        hashmap[index].key=key;
        hashmap[index].value=value;
        hashmap[index].next=NULL;
    }
    else
    {
        while(iterator->next!=NULL)
        {
            iterator=iterator->next;
        }
        iterator->next=newEntry;
    }

}

Entry* get_hashmap_entry(Entry* hashmap, int array_size, char* key_to_search)
{
    int key_index=simple_hash(key_to_search, array_size);

    if (hashmap[key_index].next==NULL)
        return &hashmap[key_index];

    Entry* iterator=&hashmap[key_index];

    while(iterator!=NULL)
    {
        if (strcmp(iterator->key,key_to_search)==0)
            return iterator;
        iterator=iterator->next;
    }
    
    return NULL;
}


int main(){
    //it is like a main for testing !
    
    /*
    Entry* hashmap=new_hash_map(100);
    int CarIndex=simple_hash("car", 100);
    int CatIndex=simple_hash("cat", 100);
    printf("index:%d\n",CarIndex);
    printf("index:%d\n",CatIndex);
    printf("key:%s\n", hashmap[10].key);

    add_entry_to_hashmap(hashmap, 100, "car", 1);
    printf("\nkey:%s\n", hashmap[10].key);
    add_entry_to_hashmap(hashmap, 100, "cat", 2);
    printf("\nkey:%s\n", hashmap[12].key);

    printf("key:%s\n", get_hashmap_entry(hashmap, 100, "car")->key);
    printf("value:%d\n",get_hashmap_entry(hashmap, 100, "car")->value);
    printf("key:%s\n", get_hashmap_entry(hashmap, 100, "cat")->key);
    printf("value:%d\n",get_hashmap_entry(hashmap, 100, "cat")->value);
    */

    //test scenario 1 - collision
    Entry* hashmap=new_hash_map(1);
    add_entry_to_hashmap(hashmap, 1, "cat", 33);
    add_entry_to_hashmap(hashmap, 1, "car", 44);
    add_entry_to_hashmap(hashmap, 1, "cad", 55);

    printf("k1: %s, v1: %d, k2: %s, v2: %d\n", hashmap[0].key, hashmap[0].value,  hashmap[0].next->key,  hashmap[0].next->value);
    printf("k3: %s, v3: %d\n", hashmap[0].next->next->key, hashmap[0].next->next->value);

    //test scenario 2 - collision
    int hashmap_size = 5;
    Entry* hashmap2 = new_hash_map(hashmap_size); 

    add_entry_to_hashmap(hashmap2, hashmap_size, "age", 22);
    add_entry_to_hashmap(hashmap2, hashmap_size, "name", 33); //should collide
    add_entry_to_hashmap(hashmap2, hashmap_size, "city", 44);  //should collide 

    printf("index %d\n", simple_hash("age",hashmap_size));
    Entry* result = get_hashmap_entry(hashmap2, hashmap_size, "age");
    printf("entry %p, entry->next %p, key: %s, value %d \n", result,result->next,result->key, result->value);
    printf("index %d\n", simple_hash("name",hashmap_size));
    result = get_hashmap_entry(hashmap2, hashmap_size, "name");
    printf("entry %p, entry->next %p, key: %s, value %d \n", result,result->next,result->key, result->value);
    printf("index %d\n", simple_hash("city",hashmap_size));
    result = get_hashmap_entry(hashmap2, hashmap_size, "city");
    printf("entry %p, entry->next %p, key: %s, value %d \n", result,result->next,result->key, result->value);

    return 0;
}