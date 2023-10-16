#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r;
    printf("Give me a Radius number");
    scanf("%d", &r);
    const float PI = 3.14;
    // int r= 4;

    float area = PI * r * r;
    printf("%f\n", area);

    return 0;
}