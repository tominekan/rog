CC=gcc
DEBUGGER=gdb

all: build run

build: rog.c
	gcc rog.c -o rog

run: rog
	./rog

# Builds and debugs the code
debug: rog.c
	gcc -g rog.c -o rog
	gdb ./rog