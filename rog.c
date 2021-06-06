#define _GNU_SOURCE
// Import stuff
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Error definitions
#define SYNTAX_ERROR -1

// Type definitions, there are literally only three types of strings
// Integers, letters of the alphabet, and special characters (symbol)
#define NUM_T
#define ALPHABET_T
#define SYMBOL_T

// These are a list of all the special characters
const char SPECIAL_CHARS[35] = {
    ' ',
    '\t',
    '\n',
    '~',
    '!',
    '@',
    '#',
    '$',
    '%',
    '$',
    '%',
    '^',
    '&',
    '*',
    '_',
    '+',
    '-',
    '=',
    '{',
    '}',
    '|',
    '[',
    ']',
    ':',
    '"',
    ';',
    '\'',
    '<',
    '>',
    ',',
    '.',
    '?',
    '/',
    '\\',
    '\0'
};

u_int8_t process_num(char *line) {
    size_t length = strlen(line);
    if (length > 10) {
        return SYNTAX_ERROR;
    } else {
        return length - 1;
    }
}

char process_char(char *line) {
    size_t length = strlen(line);

    if (length > 1) {
        void;
    }
}
int main() {
    FILE *file_pointer;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    file_pointer = fopen("hello_world.rg", "r");

    // Error handling
    if (file_pointer == NULL) {
        printf("Failed to read file.\n");
        return EXIT_FAILURE;
    }

    // Read the file line by line and print it out
    while ((read = getline(&line, &len, file_pointer) != EOF)) {
        printf("%s", line);
    }

    fclose(file_pointer);

    if (line) {
        free(line);
    }
}