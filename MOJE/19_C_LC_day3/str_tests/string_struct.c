/*
code a function char** split_str(char* str, char separator) which return an array of string where each element in a part of the original string. 
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


#include <string.h>
#include <stdio.h>

int main () {
   char str[80] = "This is - www.tutorialspoint.com - website";
   const char s[2] = "-";
   char *token;
   char *temp=str;

   /* get the first token */
   token = strtok(temp, s);

   char** arrayOfChar=(char**)malloc(3*sizeof(token));

   /* walk through other tokens */
   while( token != NULL ) {
      printf( " %s\n", token );
    
      token = strtok(NULL, s);
   }
   
   return(0);
}