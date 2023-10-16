#include <stdio.h>
#include <stdlib.h>

/*
Exercice : Pick any function you want you coded and write a unit test of it ! 
For that : 
1. Création a function test_nameoftestedfunction
2. Create some date which will be used as an input
3. call you function with the inputs
4. Get the result and check that it matches an expected result
5. if not, print "bug in the function"
6. Try to run the tests and check that if the function is bugged, the test detects it ! 
*/

int is_in_array(float* values, int n_values, float needle ) 
{

    for (int i=0; i<n_values; i++)
    {
        if(values[i]==needle)
        {
            return 1;
            //trying bug:
            //return 0;
        }
    }
    return -1;    
}

int test_is_in_array()
{
    
    // test scenario 1
  
    //values -> [1.2, 3.4, 2.6]
    //n_values -> 3 
    //needle -> 2
    //expected result if function works: -1

    int n_values=3;
    float values[n_values];
    values[0] = 1.2;
    values[1] = 3.4;
    values[2] = 2.6;
    float needle = 2.0;
  
    float actual_result = 0;
    actual_result= is_in_array(values, n_values, needle);
    if (actual_result != -1){
        printf("BUGGGGGGGGGGGG SOMEWHERE IN is_in_array\n"); 
    }
    else
        printf("test OK!\n");

    
    // test scenario 2
  
    //values -> [11.2, 33.4, 22.6]
    //n_values -> 3 
    //needle -> 33.4
    //expected result if function works: 1

    values[0] = 11.2;
    values[1] = 33.4;
    values[2] = 22.6;
    needle = 33.4;

    actual_result = is_in_array(values, n_values, needle);
    if (actual_result != 1){
        printf("BUGGGGGGGGGGGG SOMEWHERE IN is_in_array\n"); 
        printf("%d", actual_result);
    }
    else
        printf("test OK!\n");

}

int main()
{
    test_is_in_array();
    return 0;
}