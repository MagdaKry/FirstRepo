#include <stdio.h>
#include <stdlib.h>

/*
Code a function named absolute_value which returns the absolute value of a number. It must have the following prototype: 
float absolute_value(float number)  
For example:
    absolute_value(-3) must return 3
and absolute_value(2) must return 2
Attention no main function needed!
*/

float absolute_value(float number){
    if (number>=0)
    {
        return number;
    }
    else
    {
        return number*=-1;
    }
}

/*
Create a function with the following prototype: 
long factorial(long n)  
which calculates the factorial of n
Reminder factorial(n) equals
n∗(n−1)∗(n−2)…3∗2∗
No main function needed
*/
long factorial(long n)  
{
    long factorial=1;
    for (int i=1; i<=n; i++)
    {
        factorial*=i;
    }
    return factorial;
}

/*
Create a function with the following prototype: 
long factorial(long n)  
which recursively calculates the factorial of n
No main function needed
*/

long factorial_recursive(long n)  
{
    if (n==0)
        return 1;
    else
        return n*factorial_recursive(n-1);
}

/*
Create a function with the following prototype: 
float weighted_sum(float values[], float weights[], int n_values) 
which returns the weighted sum of values by weights
Example: 
if we take an array of values such as [1, 3, -1]
and take [0.5, 0, 1]
the function must calculate 0.5 * 1 + 0 * 3 + 1 * -1
Note: pno need for main function!
*/

float weighted_sum(float values[], float weights[], int n_values)
{
    float sum=0;
    for (int i=0; i<n_values; i++)
    {
        sum+=values[i]*weights[i];
    }
    return sum;
}

/*
Code the function create_float_array which creates an array of floats. The function must have the following prototype: 
float* create_float_array(int n_values, float initial_value) 
The array must be filled with the value initial_value.
Example:  create_float_array(3, 1.1) will create an array with 3 values all worth 1.1 
Note: no main function needed!
*/

float* create_float_array(int n_values, float initial_value) 
{
    float* array=(float*)malloc(n_values*sizeof(float));
    for (int i=0; i<n_values; i++)
    {
        array[i]=initial_value;
    }
    return array;
}

/*
Create an is_in_array function that checks for the presence of a given value in a float array. It returns 1 if the value is there and -1 otherwise. The function must have the following prototype:
int is_in_array(float* values, int n_values, float needle ) 
Example : is_in_array used on array [1, 1.1, -2] and with needle = -2, must return 1
Note: No main function needed!
*/

int is_in_array(float* values, int n_values, float needle ) 
{
    for (int i=0; i<n_values; i++)
    {
        if(values[i]==needle)
        {
            return 1;
        }
    }
    return -1;    
}

/*
Code a range function that creates an array and fills it with inters. The integer array must contain all integers between min_value (included) and max_value (excluded). The function must have the following prototype: 
int* range(int min_value, int max_value) 
Example: range(3, 7) returns the array [3, 4, 5, 6]
Note: No need for a main function! 
*/

int* range(int min_value, int max_value) 
{
    int n=max_value-min_value;
    int* arr=(int *)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
    {
        arr[i]=min_value+i;
    }
    return arr;
}

/*
Create a function array_threshold that thresholds an array passed as an argument. 
float* array_threshold(float* values, int n_values, float max_value) 
More precisely, the function copies the values[] array but any value greater than max_value is reduced to max_value
Example : array_threshold called with values = [1, 10, 5] and max_value = 5 will return a new array being [1, 5, 5]
Note: no need for main function
*/

float* array_threshold(float* values, int n_values, float max_value) 
{
    for (int i=0; i<n_values; i++)
    {
        if(values[i]>max_value)
        {
            values[i]=max_value;
        }
    }
    return values;
}

/*
Create a function with the following prototype: 
int* array_filter(int *values, int n_values,     int (*callbackfunc)(int v)  ) 
That returns an array that will contain only the values of values for which the function passed by the function pointer will return 1. You sized of the returned array can be of the size of the original one
You don't need to code the main, just the function.
*/
int* array_filter(int *values, int n_values,     int (*callbackfunc)(int v)  ) 
{
    for (int i=0, j=0; i<n_values; i++)
    {
        if(callbackfunc(values[i])!=1)
        {
            values[j]=0;
        }
        else
        {
            values[j]=values[i];
            j++;
        }
    }
    return values;
}

int* array_filter2(int *values, int *n_values)//,     int (*callbackfunc)(int v)  ) 
{
    int j=0;

    for (int i=0; i<*n_values; i++)
    {
        if((values[i])%2!=0)
        {
            values[j]=0;
        }
        else
        {
            values[j]=values[i];
            j++;
        }
    }
    *n_values=j;
    int * newValues=(int*)realloc(values, j*sizeof(int));
    return newValues;

}

int main()
{
    int n=7;
    int* arr=(int *)malloc(n*sizeof(int));
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;
    arr[3]=-1;
    arr[4]=-2;
    arr[5]=3;
    arr[6]=8;

    printf("before: \n");
    for (int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    arr=array_filter2(arr, &n);//, int (*callbackfunc)(int v)) 
    
    printf("after: \n");
    for (int i=0; i<n; i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}