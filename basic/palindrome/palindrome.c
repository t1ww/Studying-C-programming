#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100        // Maximum number of lines
#define MAX_LINE_LENGTH 256  // Maximum length of each line

// Palindrome Check Implementations

// My Version
int is_palindrome(char str[]) {
    size_t len = strlen(str);
    for (size_t i = 0; i < len / 2; i++) {
        char left_char = tolower((unsigned char)str[i]);
        char right_char = tolower((unsigned char)str[(len - 1) - i]);

        if (left_char != right_char) {
            return 0;  // Found differing characters
        }
    }
    return 1;  // It's a palindrome
}

// Chat's Version (Two-Pointer Approach)
int better_is_palindrome(char str[]) {
    size_t len = strlen(str);  // Get the length of the input string
    size_t start = 0;
    size_t end = len - 1;

    // Iterate while the start pointer is less than the end pointer
    while (start < end) {
        // Convert characters to lowercase for case-insensitive comparison
        // // Use unsigned char to avoid issues with negative character values
        if (tolower((unsigned char)str[start]) !=
            tolower((unsigned char)str[end])) {
            return 0;  // Not a palindrome if characters do not match
        }
        start++;
        end--;
    }
    return 1;  // It's a palindrome if all characters matched
}

// Notes:
// - The two-pointer approach enhances readability by comparing characters
//   from both ends of the string.
// - This method is efficient, iterating through only half of the string
//   and minimizing comparisons.
// - Case insensitivity is handled by converting characters to lowercase,
//   treating 'A' and 'a' as equal.
// - Using unsigned char in the tolower function prevents undefined behavior
//   from signed characters exceeding 127.

int main() {
    // FILE READING
    FILE *file = fopen("input.txt", "r");  // Open the file for reading
    if (file == NULL) {
        perror("Error opening file");  // Print error if file can't be opened
        return EXIT_FAILURE;
    }

    char string_input[MAX_LINES][MAX_LINE_LENGTH];  // Array to store lines
    int line_count = 0;                             // Number of lines read
    // Read each line from the file
    while (line_count < MAX_LINES &&
           fgets(string_input[line_count], MAX_LINE_LENGTH, file) != NULL) {
        // Optionally remove the newline character
        string_input[line_count][strcspn(string_input[line_count], "\n")] = 0;
        line_count++;
    }
    fclose(file);  // Close the file

    // OUTPUT :
    // Print the lines read from the file
    printf("Lines read from file:\n");
    for (int i = 0; i < line_count; i++) {
        printf("%s\n", string_input[i]);
        if (is_palindrome(string_input[i])) {
            printf(" : is palindrome");
        } else {
            printf(" : is NOT a palindrome");
        }
        printf("\n");
    }

    return 0;
}
