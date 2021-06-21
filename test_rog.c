// Import stuff
#include <stdbool.h>
#include <stdio.h>
#include "minunit.h"
#include "rog.h"


static char* test_process_num() {
    u_int8_t equal_to_zero = process_num("*");
    u_int8_t equal_to_nine = process_num("**********");
    u_int8_t equal_to_five = process_num("******");
    printf("Testing process_num(); ...\n");
    mu_assert("    Error! process_num(\"*\") != 9\n", equal_to_zero == 0);
    mu_assert("    Error! process_num(\"**********\") != 9\n", equal_to_nine == 9);
    mu_assert("    Error! process_num(\"******\") != 5\n", equal_to_five == 5);
}

static char* test_process_char() {
    // Test for capital letters
    char equal_to_a = process_char("+", false);
    char equal_to_b = process_char("++", false);
    char equal_to_z = process_char("++++++++++++++++++++++++++", false);
    // Test for lowercase letters
    char equal_to_A = process_char("+", true); // equivalent to c+
    char equal_to_B = process_char("++", true); // equivalent to c++, but we don't do that here
    char equal_to_Z = process_char("++++++++++++++++++++++++++", true); // equivalent to c++++++++++++++++++++++++++
    printf("Testing process_char(); ...\n");
    printf("lower_case ...");
    mu_assert("    Error! process_char(\"+\", is_upper=false) != a", equal_to_a == 'a');
    mu_assert("    Error! process_char(\"++\", is_upper=false) != a", equal_to_b == 'b');
    mu_assert("    Error! process_char(\"++++++++++++++++++++++++++\", is_upper=false) != a", equal_to_z == 'z');

    printf("UPPER_CASE ...");
    mu_assert("    Error! process_char(\"+\", is_upper=true) != a", equal_to_A == 'A');
    mu_assert("    Error! process_char(\"++\", is_upper=true) != a", equal_to_B == 'B');
    mu_assert("    Error! process_char(\"++++++++++++++++++++++++++\", is_upper=true) != a", equal_to_Z == 'Z');
}