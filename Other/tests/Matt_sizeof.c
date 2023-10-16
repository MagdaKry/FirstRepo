#include <stdbool.h>
int main()
{
    const int size = 5;
    int     iArray[size];
    long    lArray[size];
    short   sArray[size];
    char    cArray[size];
    float   fArray[size];
    double  dArray[size];
    bool    bArray[size];

    printf("int\t%d\n",     sizeof(int));
    printf("long\t%d\n",    sizeof(long));
    printf("short\t%d\n",   sizeof(short));
    printf("char\t%d\n",    sizeof(char));
    printf("float\t%d\n",   sizeof(float));
    printf("double\t%d\n",  sizeof(double));
    printf("bool\t%d\n",    sizeof(bool));

    printf("%d array int\t%d\n",    size, sizeof(iArray));
    printf("%d array long\t%d\n",   size, sizeof(lArray));
    printf("%d array short\t%d\n",  size, sizeof(sArray));
    printf("%d array char\t%d\n",   size, sizeof(cArray));
    printf("%d array float\t%d\n",  size, sizeof(fArray));
    printf("%d array double\t%d\n", size, sizeof(dArray));
    printf("%d array bool\t%d\n",   size, sizeof(bArray));

    getchar();
}