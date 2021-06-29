// TODO: implement testing
// TODO: create a stable binary

// Import stuff
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Custom definitions
#define ROG_ERROR -1
#define ROG_VERSION "1.1.0"

// Color sequences 
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

// These are a list of all the special characters
static const char SPECIAL_CHARS[36] = " \t\n~!@#$%^&()`*_+-={}|[]:\";'<>,.?/\\";
static const char ALPHABET[27] = "abcdefghiklmnopqrstuvwxyz";


// Prints the error message in a nice format
void error_print(char *file_name, char *line_content, char *error_message, int line_no) {
    printf(ANSI_COLOR_BLUE "%s:\n" ANSI_COLOR_RED, file_name);
    printf(ANSI_COLOR_YELLOW "    %i |" ANSI_COLOR_RESET, line_no);
    printf(ANSI_COLOR_RED "  %s\n" ANSI_COLOR_RESET, line_content);
    printf(ANSI_COLOR_BLUE "    %s" ANSI_COLOR_RESET, error_message);
}

// Returns the corresponding number based on the 
// number of '*' characters in the line
u_int8_t process_num(char *line) {
    size_t length = strlen(line);
    // -1 for zero based indexing
    return length - 1;
}

// Makes sure there are no errors
int8_t validate_num(char *line, char *file_name, int line_no) {
    // There cannot be two digit numbers (rog only supports digit by digit)
    if (strlen(line) > 10) {
        error_print(file_name, line, "Too many \"*\"'s in this line. Max is 10.\n", line_no);
        return ROG_ERROR;
    }

    // All the supported characters other than 1
    char *rest_of_chars = "~!@#$%^&()_+{}|:\"<>?`1234567890-=[]\\;',./\n\t qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";

    for (int i=0; i<strlen(rest_of_chars); i++) {
        // This means that there are other characters other than "*"
        if (strchr(line, rest_of_chars[i]) != NULL) {
            error_print(file_name, line, "Extra character type, expected only \"*\"\n", line_no);
            return ROG_ERROR;
        }
    }

    return 0;
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


int8_t validate_char(char *line, char *file_name, int line_no, bool is_upper) {
    // There cannot be more than 26 letters letters in the alphabet
    char *rest_of_chars = "~!@#$%^&()_{}|:*\"<>?`1234567890-=[]\\;',./\n\t qwertyuiopasdfghjklzxvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    if (is_upper) {
        if (strlen(line) > 27) { // Account for the c in the beginning
            error_print(file_name, line, "Too many \"+\"'s. Max is 26.\n", line_no);
            return ROG_ERROR;
        }  
    } else if (strlen(line) > 26) {
        error_print(file_name, line, "Too many \"+\"s. Max is 26.\n", line_no);
        return ROG_ERROR;
    }

    for (int i=0; i<strlen(rest_of_chars); i++) {
        // This means that there are other characters other than "c" or "+"
        if (strchr(line, rest_of_chars[i]) != NULL) {
            error_print(file_name, line, "Extra character type, expected only \"c\"'s or \"+\"'s\n", line_no);
            return ROG_ERROR;
        }
    }

    return 0;
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

int8_t validate_symbol(char *line, char *file_name, int line_no) {
    char *rest_of_chars = "~!@#$%^&*()_+{}|:\"<>?`-=[]\\;',.\n\t qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
    for (int i=0; i<strlen(rest_of_chars); i++) {
        // This means that there are other characters other than numeric characters and a "/"
        if (strchr(line, rest_of_chars[i]) != NULL) {
            error_print(file_name, line, "Extra character type, expected only /'s or numeric characters", line_no);
            return ROG_ERROR;
        }
    }

    // There cannot be less than 2 chatacters in a single line
    if (strlen(line) < 2) {
        error_print(file_name, line, "No numbers after the \"/\" symbol", line_no);
        return ROG_ERROR;
    }

    // Indexing starts with 0
    // There are 35 characters supported
    if (atoi(strtok(line, "/")) > 34) {
        error_print(file_name, line, "Number connot be more than 34", line_no);
        return ROG_ERROR;
    }

    return 0;
}

// Runs through and interprets the file line by line
void execute_file(char *file_name) {
    FILE *file_pointer;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    // There cannot be a file with 0 lines
    size_t line_number = 1;


    file_pointer = fopen(file_name, "r");

    // Error handling
    if (file_pointer == NULL) {
        printf("Failed to read file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the file line by line and print it out
    while ((read = getline(&line, &len, file_pointer) != EOF)) {
        line = strtok(line, "\n"); // remove newline character

        // If the line is meant to print a letter of the alphabet
        if (strchr(line, '+') != NULL) {
            // If the given code is upper case, process it as such.
            if (line[0] == 'c') { 
                if (validate_char(line, file_name, line_number, true) == ROG_ERROR) {
                    exit(EXIT_FAILURE);
                }
                printf("%c", process_char(line, true));
            } else { // If lower case, process it as such
                if (validate_char(line, file_name, line_number, false) == ROG_ERROR) {
                    exit(EXIT_FAILURE);
                }
                printf("%c", process_char(line, false));
            }
        }

        // If the line is meant to print a number
        if (strchr(line, '*') != NULL) {
            if (validate_num(line, file_name, line_number) == ROG_ERROR) {
                exit(EXIT_FAILURE);
            }
            process_num(line);
        }

        if (strchr(line, '/') != NULL) {
            if (validate_symbol(line, file_name, line_number) == ROG_ERROR) {
                exit(EXIT_FAILURE);
            }

            printf("%c", process_symbol(line));
        }

        line_number++;
    }

    if (line) {
        free(line);
    }    
}

// Prints help page
void print_help() {
    printf("USAGE: rog [FLAG] or [FILE]\n");
    printf("Possible [FLAGS]:\n");
    printf("--version, -v    --    Prints current rog version\n");
    printf("--help, -h       --    Prints the help page\n\n");
    printf("Raise complaints (cause I know you have them) here: https://github.com/tominekan/rog/issues\n");
    printf("Check out the source code here: https://github.com/tominekan/rog\n");
    printf("Feel free to contribute.\n");
}

// TODO: get rid of this crap
// Im
void process_argument(char *argument) {
    if (!strcmp(argument, "--help") || !strcmp(argument, "-h")) {
        print_help();
        exit(EXIT_SUCCESS);
    } else if (!strcmp(argument, "--version") || !strcmp(argument, "-v")) {
        printf("rog v%s", ROG_VERSION);
        exit(EXIT_SUCCESS);
    } else {
        execute_file(argument);
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char **argv) {
    for (int i=1; i<argc; i++) {
        process_argument(argv[i]);
    }
}