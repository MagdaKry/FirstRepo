#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a;
    int *p;
    p=&a;
    printf("p=%p\n",p);
    printf("p=%p\n",p+1);
    char b;
    char *p1;
    p1=&b;
    printf("p=%p\n",p1);
    printf("p=%p",p1+1);

    int c=1025;
    int *p2;
    p2=&c;
    printf ("\nsize of int is %d: ", sizeof(int));
    printf ("\naddress=%p, value=%d ", p2, *p2);
    char *p3;
    p3=(char*)p2;
    printf ("\nsize of char is %d: ", sizeof(char));
    printf ("\naddress=%p, value=%d ", p3, *p3);
    printf ("\naddress p3+1=%p, value p3+1=%d ", p3+1, *(p3+1));
    
    int(*pa)[3];
    int B[3][3] = {
        {1,2,32},
        {46,5,6},
        {8,56,88}
    };
    pa=B;
    printf("\n\nB=%d\n", B); //ADRES=B[0][0]
    printf("*(B+2)=%d\n", *(B+2)); //ADRES=B[2][0]: przesunięcie z wiersza 0 do 2
    printf("*(*B+2)=%d\n", *(*B+2)); //WARTOŚĆ=B[0][2]=3: najpierw adres [0][0], przesunięcie o 2 i wartość z tego
    printf("**(B+2)=%d\n", **(B+2)); //WARTOŚĆ=B[2][0]=8: najpierw przesunięcie z wiersza 0 do 2, adres, a potem wartość
    printf("B[2,1]=%d\n", B[2][1]); //WARTOŚĆ=B[2][1]=56
    printf("B[2,1]=%d\n", *(*(B+2)+1));//WARTOŚĆ=B[2][1]=56: najpierw przesunięcie z wiersza 0 do 2, adres, potem o 1 w prawo i wartość z całości
    printf("B[1,2]=%d\n", *(*(pa+1)+2)); //WARTOŚĆ=B[1][2]=6
    printf("B[1,2]=%d\n", (*(pa+1)+2)); //ADRES=B[1][2]=6
    printf("B[1,2]=%d\n", *(*pa+5)); //WARTOŚĆ=B[1][2]=6

    return 0;
}