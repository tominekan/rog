CC=gcc
DEBUGGER=gdb

# Enables all compiler warnings for C
# and enables it to be debugged by gdb
FLAGS=-Wall -g

# -lrt for timer and -lm for math -c for compiling
# and assembling, but not linking
TEST_FLAGS=-lrt -lm -c

all: build run clean

build: rog.c
	gcc $(FLAGS) src/main.c -o rog

run: rog
	./rog

# Build and debug the code
debug: build
	gdb ./rog

# Build and test the code
test: src/test_rog.c src/rog.c
	gcc $(TEST_FLAGS) src/test_rog.c
	gcc $(TEST_FLAGS) src/rog.c
	gcc test_rog.o rog.o -o test_rog
	./test_rog

# Remove all .o files
clean:
	rm -rfv *.o
	rm -rfv test_rog