#include <stdio.h>

int main()
{
    // Prompt the user for the number of rows
    int num_rows;
    printf("Enter the number of rows: ");
    scanf("%d", &num_rows);

    // Nested loop to print the right-angled triangle pattern
    for (int i = 1; i <= num_rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }

    return 0;
}
