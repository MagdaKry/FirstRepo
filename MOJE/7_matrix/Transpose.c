/*

#include <stdio.h>

int main(void){

    const int r=2;
    const int c=3;

    int matrix[2][3]={{1,2,3},{4,5,6}};
    int matrixT[c][r];
    
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                matrixT[j][i]=matrix[i][j];
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
        
        printf("transposed array:\n");
        
        for (int i=0; i<c; i++)
        {
            for (int j=0; j<r; j++)
            {
               printf("%d \t",matrixT[i][j]);
            }
            printf ("\n");
        }
    
    
}
*/

#include <stdio.h>

#include <stdio.h>

const int r=2;
const int c=3;

void transpose(int matrix[r][c]);

int main(void){
    
    int matrixA[2][3]={{1,2,3},{4,5,6}};
    transpose(matrixA);
    
}

void transpose(int matrix[r][c])
{
    int matrixT[c][r];
    for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                matrixT[j][i]=matrix[i][j];
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
        
        printf("transposed array:\n");
        
        for (int i=0; i<c; i++)
        {
            for (int j=0; j<r; j++)
            {
               printf("%d \t",matrixT[i][j]);
            }
            printf ("\n");
        }
}
