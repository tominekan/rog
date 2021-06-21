#ifndef ROG_H
#define ROG_H
// Check out the corresponding rog.c file for explanations
#include <stdlib.h>
#include <stdbool.h>

#define ROG_ERROR -1

u_int8_t process_num(char *line);
int8_t validate_num(char *line, char *file_name, int line_no);

char process_char(char *line, bool is_upper);
int8_t validate_char(char *line, char *file_name, int line_no, bool is_upper);

char process_symbol(char *line);
int8_t validate_symbol(char *line, char *file_name, int line_no);
#endif