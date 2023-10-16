/*
1. Create a variable str1 container “hello chicken”

2. Create a variable str2 containing “hello hooman”

3. use strlen to compute the str length, store the result in a variable r1

4. use strcmp on str1 and str2 and store the result in a variable r2

5. Display r1 and r2
*/

#include <string.h>

void test_main(){
    //it is like a main for testing !
    char str1[]={"hello chicken"};
    char str2[]={"hello hooman"};
    long r1=strlen(str1);
    int r2=strcmp(str1,str2);
    
    printf("r1=%ld,r2=%d",r1,r2);
    

}


/*
1. Create a variable str1 container “hello chicken”

2. Create a variable str2 containing “hello hooman”

3. Use strcat to concatenate str2 and str1. Display the result. 
*/

#include <string.h>

void test_main(){
    //it is like a main for testing !
    char str1[30]={"hello chicken"};
    char str2[]={"hello hooman"};

    printf("%s", strcat(str1, str2));

}

/*
Without using strcmp, code a function int are_string_equals(char* str1, char* str2) which returns 1 if str is the same as str2 and 0 otherwise
*/

#include <string.h>
int are_string_equals(char* str1, char* str2)
{
    int size1=sizeof(str1);
    int size2=sizeof(str2);
    
    if(str1!=str2)
        return 0;
        
    for (int i=0; i<size1; i++)
    {
        if (str1[i]!=str2[i])
        {
            return 0;
        }
    }
    return 1;
    
}

void test_main(){
    //it is like a main for testing !

}

/*
We have the following struct Position { float x,y}

1. Create the struct using the typedef syntax

2. Code a function Position * average_position(Position* positions, int n_values) which takes an array of Point and returns a Point containing the average of all positions (both for x and y). 

3. Using test_main function to create an array of struct and check your function in a simple setting
*/
typedef struct Position{
    float x,y;
}Position;

Position * average_position(Position* positions, int n_values)
{
    float sumX=0;
    float sumY=0;
    
    for (int i=0; i<n_values; i++)
    {
        sumX+=positions[i].x;
        sumY+=positions[i].y;
    }
    
    Position* averagePoint=(Position *)malloc(sizeof(Position));
    averagePoint->x=sumX/(float)n_values;
    averagePoint->y=sumY/(float)n_values;
    
    return averagePoint;
}

void test_main(){
    //it is like a main for testing !
    Position array[3];
    array[0].x=1;
    array[0].y=2;
    array[1].x=3;
    array[1].y=4;
    array[2].x=5;
    array[2].y=6;
    
    Position* averageTest=(Position *)malloc(sizeof(Position));
    averageTest=average_position(array, 3);
    printf("%f %f", averageTest->x, averageTest->y);
    
}
