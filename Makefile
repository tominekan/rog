CC=gcc
DEBUGGER=gdb

# Enables all compiler warnings for C
# and enables it to be debugged by gdb
FLAGS=-Wall -g

# -lrt for timer and -lm for math -c for compiling
# and assembling, but not linking
TEST_FLAGS=-lrt -lm -c

all: build run

build: rog.c
	gcc $(FLAGS) rog.c -o rog

run: rog
	./rog

# Build and debug the code
debug: build
	gdb ./rog

test: test_rog.c
	gcc $(TEST_FLAGS) test_rog.c
	gcc $(TEST_FLAGS) rog.c
	gcc test_rog.o rog.o -o test_rog
	./test_rog

# Remove all .o files
clean:
	rm -rfv *.o