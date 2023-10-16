#include<stdio.h>
#include<stdlib.h>

int main(){
    int n1,n2,n3;
    /*printf("Give me a first number\n");
    scanf("%d",&n1);
    printf("give me a second number\n");
    scanf("%d",&n2);
    printf("Give me a third number\n");
    scanf("%d",&n3);*/

    printf("Give me 3 numbers\n");
    scanf("%d%d%d",&n1,&n2,&n3);
    float mean= (float)(n1+n2+n3)/3;
    printf("The mean is:%f\n",mean);

    return 0;
}