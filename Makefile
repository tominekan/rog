CC=gcc
DEBUGGER=gdb

# Enables all compiler warnings for C
# and enables it to be debugged by gdb
# -c for compiling to object files
FLAGS=-Wall -g -c

# -lrt for timer and -lm for math -c for compiling
# and assembling, but not linking
TEST_FLAGS=-lrt -lm -c

all: build

build: src/rog.c src/main.c src/rog.h
	gcc $(FLAGS) src/rog.c -o target/rog.o
	gcc $(FLAGS) src/main.c -o target/main.o
	gcc target/*.o -o rog

# Build and debug the code
debug: build
	gdb ./rog

# Build and test the code
test: src/test_rog.c src/rog.c
	gcc $(TEST_FLAGS) src/test_rog.c -o target/test_rog.o
	gcc $(TEST_FLAGS) src/rog.c -o target/rog.o
	gcc target/*.o -o build/test_rog
	./build/test_rog

# Remove all .o files
clean:
	rm -rfv target/*.o
	rm -rfv test_rog