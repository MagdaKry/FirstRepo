#include <stdio.h>

void displayArray(int *arr, int size)
{
    printf("Array elements: ");
    for (int i = 0; i < size; i++)
    {
        //printf("%d ", *(arr + i)); // Use pointer arithmetic to access array elements
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int numbers[] = {12, 34, 56, 23, 9, 87, 45};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    displayArray(numbers, size);

    return 0;
}
