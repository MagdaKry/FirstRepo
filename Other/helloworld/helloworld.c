
#include <stdio.h> //IO library
#include <float.h>
#include <stdbool.h>

/*
main
*/

int main() {
    // Write C code here
    printf("Hello world");
    printf("\nHello world! \t\\ I am \'learning\' \"C\"\n");
    
    printf("Min float: %e\n", FLT_MIN);
    printf("Min float: %e\n", FLT_MAX);
    printf("Min double: %e\n", DBL_MIN);
    printf("Min double: %e\n", DBL_MAX);

    char c = 'a';
    char ac = 65;
        short ac_short = 65;

    printf("\n%c", c);
    printf("\n%c", ac);
    printf("\n%c", ac_short);

    bool isFun=true;
    bool isHealthy = false;

    printf("\n%d", isFun);
    printf("\n%d", isHealthy); 

    /* 
    %d lub %i = integer 
    %f = float
    %c = character
    */
    
    getchar();

    return 0;
}