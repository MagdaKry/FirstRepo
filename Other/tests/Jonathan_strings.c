#include <stdio.h>
#include <string.h>
#include <stdbool.h> // Include ctype.h for tolower function
#include <ctype.h>

void firstLetter(const char*);
bool isVowel(char);
int countVowels(const char*);
int spaceFinder(const char*, char);

int main() {
    char inputString[100];
    char spaces = ' ';

    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    firstLetter(inputString);

    int vowelCount = countVowels(inputString);

    printf("Number of vowels in the string: %d\n", vowelCount);

    int results = spaceFinder(inputString, spaces);

    // There is always 1 more word than spaces so results + 1
    printf("There are %d words in that string.\n", results + 1);

    return 0;
}

// Function to find acronym
void firstLetter(const char* inputString) {
    char acronym[100];
    int acronymIndex = 0;

    int length = strlen(inputString);

    for (int i = 0; i < length; i++) {
        if (inputString[i] != ' ' && (i == 0 || inputString[i - 1] == ' ')) {
            acronym[acronymIndex] = inputString[i];
            acronymIndex++;
        }
    }

    // Null-terminate the acronym to make it a valid C string
    acronym[acronymIndex] = '\0';

    printf("The acronym for: %s is: %s\n", inputString, acronym);
}

bool isVowel(char ch) {
    char lowercaseCh = tolower(ch); // Convert the character to lowercase
    return (lowercaseCh == 'a' || lowercaseCh == 'e' || lowercaseCh == 'i' || lowercaseCh == 'o' || lowercaseCh == 'u');
}

// Function to count vowels in a string
int countVowels(const char* str) {
    int count = 0;
    int strLength = strlen(str);

    for (int i = 0; i < strLength; i++) {
        if (isVowel(str[i])) {
            count++;
        }
    }

    return count;
}

// Declaration of a pointer to the string we are searching
int spaceFinder(const char* inputString, char spaces) {
    // Counter for the number of times spaces are in the string
    int count = 1; // Initialize count to 1 to account for the first word

    // Declare a pointer to a constant character named ptr and initialize it with the address of the first character of the inputString.
    const char* ptr = inputString;

    // This function (strchr) searches for the first occurrence of spaces in the string pointed to by ptr.
    // If it finds the character, it returns a pointer to that character; otherwise, it returns NULL.
    while ((ptr = strchr(ptr, spaces)) != NULL) {
        count++;
        ptr++;
    }

    return count;
}