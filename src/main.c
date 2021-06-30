#include "rog.h"

int main(int argc, char **argv) {
    for (int i=1; i<argc; i++) {
        process_argument(argv[i]);
    }
}