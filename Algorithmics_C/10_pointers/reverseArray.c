#include <stdio.h>

/// @brief 
/// @param arr 
/// @param size 
void reverseArray(int *arr, int size)
{
    int *start = arr;          // Pointer to the beginning of the array
    int *end = arr + size - 1; // Pointer to the end of the array

    while (start < end)
    {
        // Swap the elements pointed to by start and end
        int temp = *start;
        *start = *end;
        *end = temp;

        // Move the pointers inward
        start++;
        end--;
    }
}

int main()
{
    int numbers[] = {12, 34, 56, 23, 9, 87, 45};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    printf("Original Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    reverseArray(numbers, size);

    printf("Reversed Array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    return 0;
}
