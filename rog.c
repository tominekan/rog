#define _GNU_SOURCE
// Import stuff
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Error definitions
#define ROG_ERROR -1

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

const char ALPHABET[27] = {
    'a',
    'b',
    'c',
    'e',
    'f',
    'g',
    'h',
    'i',
    'j',
    'k',
    'l',
    'm',
    'n',
    'o',
    'p',
    'q',
    'r',
    's',
    't',
    'u',
    'v',
    'w',
    'x',
    'y',
    'z',
    '\0'
};

u_int8_t process_num(char *line) {
    size_t length = strlen(line);
    if (length > 10) {
        return ROG_ERROR;
    } else {
        return length - 1; // for zero based indexing
    }
}

char process_char(char *line, bool is_upper) {
    size_t length = strlen(line) - 1; // for null terminator
    if (length > 26) { // There cannot be more than 26 letters in the english alphabet
        return ROG_ERROR;
    } else {
        return ALPHABET[length-1]; // accounting for zero based indexing
    }
}

int main() {
    FILE *file_pointer;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    bool is_upper = false;

    file_pointer = fopen("hello_world.rg", "r");

    // Error handling
    if (file_pointer == NULL) {
        printf("Failed to read file.\n");
        return EXIT_FAILURE;
    }

    // Read the file line by line and print it out
    while ((read = getline(&line, &len, file_pointer) != EOF)) {
        printf("%s", line);

        if (strchr(line, '+') != NULL) { // If it defines a string
            // TODO: Implement parsing for both upper and lower case symbols
            printf("Here I need to implement some of the above");
        }
    }

    fclose(file_pointer);

    if (line) {
        free(line);
    }
}