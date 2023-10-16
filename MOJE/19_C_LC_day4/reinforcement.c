/*
Create a Struct Position. 

1. In the test_main function create a Position p1 and modify their value. 

2. Create a Position * p_pointer1 and affect it to the adress of p1.

3. Modify p1 value from the p_pointer1 and display the values
*/

#include <stdio.h>

typedef struct Position{
    float x,y;
}Position;


void test_main(){
    //it is like a main for testing !
    Position p1;
    p1.x=1.2;
    p1.y=2.4;
    
    Position *p_pointer1=&p1;
    
    p_pointer1->x=3.6;
    p_pointer1->y=4.8;
    
    printf("x=%g",p_pointer1->x);
    printf(" y=%g",p_pointer1->y);
}

/*
Code a function name char* str_concat(char* str1, char* str2) which returns a news string with the appropriate lenght
*/
#include<string.h>
#include<stdio.h>
#include <stdlib.h>

char* join(char** strings, int array_size, char glue)
{
    //if (strings==NULL)
    //{
    //    return NULL;
    //}
    char* glueP=(char*)malloc(2*sizeof(char));
    glueP[0]=glue;
    glueP[1]='\0';

    int i=0;
    int l=0;
    i=0;
    for(int i=0; i<array_size; i++)
    {
        l+=strlen(*(strings+i))+1;
        //printf("l=%d",l);
    }
    
    //printf("l=%d",l);
    char* joined=(char*)malloc(sizeof(char));
    joined=strcpy(joined,"");

    i=0;
    for(int i=0; i<array_size; i++)
    {
        joined=strcat(joined,*(strings+i));
        if(i!=array_size-1)
            joined=strcat(joined,glueP);
        //printf( " %s\n", joined );
        //printf( " %s\n", *(strings+i) ); vb
    }
    
    return joined;
}

void test_main(){
    //it is like a main for testing !
    char *string1="hello";
    char *string2="world";
    char *string3="again!!!";
    
    char **strings=(char**)malloc(3*sizeof(char*));
    *strings=(char*)malloc(strlen(string1));
    *(strings+1)=(char*)malloc(strlen(string2));
    *(strings+2)=(char*)malloc(strlen(string3));
    //printf( " %s\n", *strings );
    *strings=string1;
    *(strings+1)=string2;
    *(strings+2)=string3;
    //*(strings+3)=NULL;
    //printf( " %s\n", *strings );
    //printf( " %s\n", *(strings+1) );
    //printf( " %s\n", *(strings+2) );
    char glue='_';
   
    char* withGlue=(char*)malloc(sizeof(char));
    withGlue=join(strings, 3, glue);
    printf( "\njoined with glue:%s\n", withGlue );
    
}


/*
Code a function name char* join(char** strings, int array_size, char glue) which combines an array of string into a single string gluing each string with the “glue” char
*/

#include<string.h>
#include<stdio.h>
#include <stdlib.h>

char* join(char** strings, char glue)
{
    //if (strings==NULL)
    //{
    //    return NULL;
    //}
    char* glueP=(char*)malloc(2*sizeof(char));
    glueP[0]=glue;
    glueP[1]='\0';

    int i=0;
    int l=0;
    while(*(strings+i)!=NULL)
    {
        l+=strlen(*(strings+i))+1;
        //printf("l=%d",l);
        i++;
    }
    
    //printf("l=%d",l);
    char* joined=(char*)malloc(sizeof(char));
    joined=strcpy(joined,"");

    i=0;
    while(*(strings+i)!=NULL)
    {
        joined=strcat(joined,*(strings+i));
        if(*(strings+i+1)!=NULL)
            joined=strcat(joined,glueP);
        //printf( " %s\n", joined );
        //printf( " %s\n", *(strings+i) );
        i++;
    }
    
    return joined;
}

void test_main(){
    //it is like a main for testing !
    char *string1="hello";
    char *string2="world";
    char *string3="again!!!";
    
    char **strings=(char**)malloc(3*sizeof(char*));
    *strings=(char*)malloc(strlen(string1));
    *(strings+1)=(char*)malloc(strlen(string2));
    *(strings+2)=(char*)malloc(strlen(string3));
    //printf( " %s\n", *strings );
    *strings=string1;
    *(strings+1)=string2;
    *(strings+2)=string3;
    *(strings+3)=NULL;
    //printf( " %s\n", *strings );
    //printf( " %s\n", *(strings+1) );
    //printf( " %s\n", *(strings+2) );
    char glue='_';
   
    char* withGlue=(char*)malloc(sizeof(char));
    withGlue=join(strings, glue);
    printf( "\njoined with glue:%s\n", withGlue );
    
}

/*
Using any previous struct you like, create a an array of struct allocated on the heap using malloc or calloc.

Modify data of the first entry of the array and display it
*/
typedef struct Position{
    float x,y;
}Position;

void test_main(){
    //it is like a main for testing !
    Position* array = (Position*) calloc(sizeof(Position), 10); // Array of struct
    array->x = 10.25;
    printf("%g\n", array->x); //data address is first struct value so use ->
    
    printf("%g\n", array[0].x);
}

/*
code the function Node* minimum(Node* head) which return the minimum value of a linked list
*/

typedef struct Node{
    float x;
    struct Node* next;
}Node;

Node* minimum(Node* head)
{
    if (head==NULL)
        return NULL;
    
    float minimum=head->x;
    
    Node* iterator=head;
    while(iterator!=NULL)
    {
        if (iterator->x<minimum)
            minimum=iterator->x;
        iterator->next;
    }
    return NULL;
}

void test_main(){
    //it is like a main for testing !

}
