CC=gcc
DEBUGGER=gdb

all: build run

build: rog.c
	gcc rog.c -o rog

run: rog
	./rog

# Build and debugs with gdb
debug: rog.c
    gcc rog.c -g -o rog
	./rog