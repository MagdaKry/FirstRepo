#include <stdio.h>

int main(void){

    const int r=3;
    const int c=4;

    int k=0;
    int matrix[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int array[r*c];
    
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                array[k]=matrix[i][j];
                k++;
            }
        }

        printf("old array:\n");
        
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
               printf("%d \t",matrix[i][j]);
            }
            printf ("\n");
        }
        
        printf("flattened array:\n");
        
        for (int i=0; i<r*c; i++)
        {
            printf("%d \t", array[i]);
        }
    
}