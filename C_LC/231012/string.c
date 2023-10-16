#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* join(char** strings, int array_size, char glue){
    
    int size = 0;
    
    for (int i = 0; i < array_size; i++){
        
        size += strlen(strings[0]) + 1; //+1 for glue
    }
    
    char* result = (char*) calloc(sizeof(char), size+1);
    
    char* glue_str = (char*) calloc(sizeof(char), 1);
    glue_str[0] = glue;
    
    for (int i = 0; i < array_size -1; i++){
        
        strcat(result, strings[i]);
        strcat(result, glue_str);
    }
    
    strcat(result, strings[array_size-1]);
     
    return result;
}
 
void main(){
    //it is like a main for testing !
    
    char **strings = (char**) calloc(sizeof(char*), 3);
    
    char* str1 = "hello";
    char* str2= "john";
    char* str3 = "john";
    
    strings[0] = str1;
    strings[1] = str2;
    strings[2] = str2;
    
    char* result = join(strings, 3, ' ');
    
    printf("concat: '%s' \n", result);
    
 
}