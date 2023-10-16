#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *arr = (int *)calloc(5, sizeof(int));
    // Check if memory allocation was successful
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }

    printf("Original Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    
    printf("\nManual initialization: ");
    for (int i = 0; i < 5; i++) {
        arr[i] = i;
        printf("%d ", arr[i]);
    }
    // Resize the array to 8 elements using realloc
    int *newArr = (int *)realloc(arr, 8 * sizeof(int));
    // Check if realloc was successful
    if (newArr == NULL) {
        printf("Memory reallocation failed.\n");
        free(arr); // Free the original array
        return 1; // Exit with an error code
    }

    printf("\nResized Array elements: ");
    for (int i = 0; i < 8; i++) {
        printf("%d ", newArr[i]);
    }
    
    // Free the dynamically allocated memory when done
    free(newArr);
    return 0;
}