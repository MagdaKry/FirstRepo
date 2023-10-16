#include <stdio.h>
#include <stdlib.h>

void main()
{
    int (*p)[4];
    int B[3][4] = {
        {1, 2, 3, 6},
        {4, 5, 6, 43},
        {8, 56, 88, 8}
    };
    p = B;
    printf("B = %d\n", B);
    printf("*(B+2) = %d\n", *(B+2));
    printf("B[2,1] = %d\n", B[2][1]);
    printf("B[2,1] = %d\n", *(*(B+2)+1));

    printf("B[1,2] = %d", *(*(p+1)+2));
}