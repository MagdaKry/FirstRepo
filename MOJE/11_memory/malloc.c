#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int *arr = (int *)malloc(5 * sizeof(int));
    if (arr == NULL) { // Check if memory allocation was successful
        printf("Memory allocation failed.\n");
        return 1; // Exit with an error code
    }
    
    for (int i = 0; i < 5; i++) {
        arr[i] = i * 2; // Initialize with even numbers
    }
    
    printf("Array elements: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // Free the dynamically allocated memory when done
    
    return 0;
}