#include <stdio.h>

int calculateSum(int *arr, int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += *(arr + i); // Use pointer arithmetic to access array elements
        // sum+=arr[i];
    }

    return sum;
}

int main()
{
    int numbers[] = {12, 34, 56, 23, 9};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int sum = calculateSum(numbers, size);

    printf("Sum of array elements: %d\n", sum);

    return 0;
}
