//Write a program that inserts an element n at the end of an array of integers tab.
//NB : The result is another array of different dimension.

#include <stdio.h>

//Declaring arrays as global variables - Uncertain how to pass arrays into functions
int tab[5];
int newTab[6];
//Declaring functions
void insertArray(int,int,char);                                         
void loadArray(int,int,int,int,int);
void printArray(int);

int main(){
    int int1,int2,int3,int4,int5,add;                                   //Declaring variables for main function
    char location;
    int lenArray = sizeof(tab)/sizeof(tab[0]);                          //Initializing the length of the array
    printf("Please input the 5 values in the array\n");
    scanf("%d,%d,%d,%d,%d",&int1,&int2,&int3,&int4,&int5);              //Reading the values of the array
    loadArray(int1,int2,int3,int4,int5);                                //Calling loadArray function to load values into the array

    printf("Please input the number that you wish to add to the array\n");
    scanf(" %d", &add);                                                 //Reading the value to add to the arry

    printf("Do you wish to add this number to the start (s) or end (e) of the array");
    printf(" \n");                                                      
    scanf(" %c",&location);                                             //Reading start or end flag
    insertArray(add,lenArray,location);                                 //Calling the insertArray function
    printArray(lenArray+1);                                             //Calling the printArray function; passing the value of 6 (lenArray+1)

}

void insertArray(int add, int lenArray, char location){
    
    if(location == 's' || location =='S'){                              //Process for adding value to start of the array
        newTab[0]=add;
        for (int i=1; i <=lenArray;i++){
            newTab[i]=tab[i-1];
        }
    } else if (location == 'e' || location == 'E'){                     //Process for adding value to end of the array
        newTab[5]=add;
         for (int i=0; i <lenArray;i++){
            newTab[i]=tab[i];
        }       
    }
    return;
}

void loadArray(int int1,int int2,int int3,int int4,int int5){           //Manual loading of array. Not roubust.
    tab[0]=int1;
    tab[1]=int2;
    tab[2]=int3;
    tab[3]=int4;
    tab[4]=int5;
    return;
}

void printArray(int lenArray){                                          //Printing the values of the new array
    int i = 0;  
    for (i=0; i <lenArray; i++){
        printf("%d,",newTab[i]);
    }
}