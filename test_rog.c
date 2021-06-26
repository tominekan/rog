// Import stuff
#include <stdbool.h>
#include <stdio.h>
#include "minunit.h"
#include "rog.h"

// Generate all the necessary variables with incorrect values
// so that the test fails if something goes wrong with test_setup()
static u_int8_t equal_to_zero = 3;
static u_int8_t equal_to_nine = 3;
static u_int8_t equal_to_five = 3;

// Press f to pay respects
static char equal_to_a = 'f';
static char equal_to_b = 'f';
static char equal_to_z = 'f';

static char equal_to_A = 'F';
static char equal_to_B = 'F';
static char equal_to_Z = 'F';

static char equal_to_underscore = ';';
static char equal_to_space = ';';
static char equal_to_back_slash = ';';

// Applies the functions defined to the variables generated
void test_setup(void) {
    // Process num
    equal_to_zero = process_num("*");
    equal_to_nine = process_num("**********");
    equal_to_five = process_num("******");

    // Test for capital letters
    equal_to_a = process_char("+", false);
    equal_to_b = process_char("++", false);
    equal_to_z = process_char("++++++++++++++++++++++++++", false);

    // Test for lowercase letters
    equal_to_A = process_char("+", true); // equivalent to c+
    equal_to_B = process_char("++", true); // equivalent to c++, but we don't do that here
    equal_to_Z = process_char("++++++++++++++++++++++++++", true); // equivalent to c++++++++++++++++++++++++++

    // Test for special characters (symbols)
    equal_to_underscore = process_symbol("/15");
    equal_to_space = process_symbol("/0");
    equal_to_back_slash = process_symbol("/34");
}
void test_teardown(void) {
    // Nothing
    ;
}

MU_TEST(test_check) {
    // Checks if the process_num returns the right values
    mu_check(equal_to_zero == 0);
    mu_check(equal_to_nine == 9);
    mu_check(equal_to_five == 5);

    // Checks if process_char returns the right values
    mu_check(equal_to_a == 'a');
    mu_check(equal_to_b == 'b');
    mu_check(equal_to_z == 'z');
    mu_check(equal_to_A == 'A');
    mu_check(equal_to_B == 'B');
    mu_check(equal_to_Z == 'Z');

    // Checks if process_symvol returns the right values
    mu_check(equal_to_underscore == '_');
    mu_check(equal_to_space == ' ');
    mu_check(equal_to_back_slash == '\\');
}

MU_TEST_SUITE(test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_check);
}
int main() {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}