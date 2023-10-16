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
        printf("l=%d",l);
        i++;
    }
    
    printf("l=%d",l);
    char* joined=(char*)malloc(sizeof(char));
    joined=strcpy(joined,"");

    i=0;
    while(*(strings+i)!=NULL)
    {
        joined=strcat(joined,*(strings+i));
        if(*(strings+i+1)!=NULL)
            joined=strcat(joined,glueP);
        printf( " %s\n", joined );
        printf( " %s\n", *(strings+i) );
        i++;
    }
    
    return joined;
}

void main(){
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