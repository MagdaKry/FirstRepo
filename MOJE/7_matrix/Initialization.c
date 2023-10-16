#include <stdio.h>

int main(void){

    const int r=5;
    const int c=7;

    int matrix[r][c];
    
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                matrix[i][j]=i+j;
            }
        }

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
               printf("%d \t",matrix[i][j]);
            }
            printf ("\n");
        }
    
}

/*
#include <stdio.h>

void initialize (int r, int c, int matrix[r][c]);

int main(void){

    const int r=5;
    const int c=7;

    int matrix[r][c];
    
    initialize(r,c,matrix);
    
}

void initialize (int r, int c, int matrix[r][c])
{
        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
                matrix[i][j]=i+j;
            }
        }

        for (int i=0; i<r; i++)
        {
            for (int j=0; j<c; j++)
            {
               printf("%d \t",matrix[i][j]);
            }
            printf ("\n");
        }
}
*/
