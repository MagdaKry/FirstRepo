#include<stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#define UNIVERSE 42;
#define log(message) printf("message: %s, line: %d, file: %s\n", message, __LINE__, __FILE__)
#define ASSERT(assertion) ({\
            if (!assertion){\
                log("bug");\
                exit(1);}\
            })

int multiply(int a, int b)
{
    //return a*b;
    return a*b+11;
}

void unit_test_multiply()
{
    bool forAssert=0;
    if (multiply(2,3)==6)
        forAssert=1;

    ASSERT(forAssert);
}

int main()
{
    int v1=UNIVERSE;
    //printf("%d\n",v1);
    //log("hello");

    unit_test_multiply();


    return 0;
}