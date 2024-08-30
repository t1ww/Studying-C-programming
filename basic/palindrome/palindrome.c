#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100        // Maximum number of lines
#define MAX_LINE_LENGTH 256  // Maximum length of each line

int is_palindrome(char str[]) {
    size_t len = strlen(str);
    // iterate char index
    for (size_t i = 0; i < len / 2; i++) {
        if (str[i] != str[(len - 1) - i]) {
            // found not different char so return false
            return 0;
        }
    }
    // all char are the same (back compared to front) return true
    return 1;
}

int main() {
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
