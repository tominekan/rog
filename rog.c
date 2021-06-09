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
const char SPECIAL_CHARS[36] = {
    ' ',
    '\t',
    '\n',
    '~',
    '!',
    '@',
    '#',
    '$',
    '%',
    '^',
    '&',
    '(',
    ')',
    '`',
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
    'd',
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

// Returns the corresponding number based on the 
// number of '*' characters in the line
u_int8_t process_num(char *line) {
    size_t length = strlen(line);
    // -1 for zero based indexing
    return length - 1;
}

// Based on the number of +, it returns 
// a specific letter of the English alphabet
char process_char(char *line, bool is_upper) {
    size_t line_length = strlen(line);
    if (is_upper == true) {
        // -1 to account for the c in front of the legion of +'s
        // -1 to account for zero based indexing
        return toupper(ALPHABET[line_length-2]);
    } else {
        // -1 to account for zero based indexing
        return ALPHABET[line_length-1];
    }
}

// Takes the number from the /number and 
// return's it's character representation
char process_symbol(char *line) {
    // Collect the number from the string
    char *char_id = strtok(line, "/"); // Take note of the double quotes " sorrounding the /
    // Convert the the string ID into an integer
    int char_number = atoi(char_id);

    char symbol = SPECIAL_CHARS[char_number];
    return symbol;
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
        line = strtok(line, "\n"); // remove newline character

        // If the line is meant to print a letter of the alphabet
        if (strchr(line, '+') != NULL) {
            // If the given code is upper case, process it as such.
            if (line[0] == 'c') { 
                printf("%c", process_char(line, true));
            } else { // If lower case, process it as such
                printf("%c", process_char(line, false));
            }
        }

        // If the line is meant to print a number
        if (strchr(line, '*') != NULL) {
            process_num(line);
        }

        if (strchr(line, '/') != NULL) {
            printf("%c", process_symbol(line));
        }
    }

    char symbol = process_char("c+++++++++++++++", true);
    printf("This is letter %c\n", symbol);
    fclose(file_pointer);

    if (line) {
        free(line);
    }
}