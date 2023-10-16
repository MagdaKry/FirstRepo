#include <stdio.h>
#include <ctype.h> // for isspace
#include <string.h>

// Function to trim leading and trailing whitespace from a string
void trim(char str[]) {
    int start = 0, end = strlen(str) - 1;

    // Trim leading whitespace
    while (isspace(str[start])) {
        start++;
    }

    // Trim trailing whitespace
    while (end > start && isspace(str[end])) {
        end--;
    }

    printf("%d",start);
    printf("%d",end);

    // Shift characters to the beginning of the string
    int len = end - start + 1;
    for (int i = 0; i < len; i++) {
        str[i] = str[start + i];
    }
    str[len] = '\0';
}

int main() {
    char str[] = "   Hello,      World!   ";
    printf("Before: '%s'\n", str);

    trim(str);

    printf("After: '%s'\n", str);

    return 0;
}
