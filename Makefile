SRCDIR=src
OBJDIR=obj
BUILDDIR=bin
CC=gcc
COMPILE_FLAGS=-Wall -lrt -lm -c
MAIN_OBJECTS=$(OBJDIR)/main.o $(OBJDIR)/rog.o
TEST_OBJECTS=$(OBJDIR)/tests.o $(OBJDIR)/rog.o

# Build the main and test files (and run the test)
all: build test run_tests

$(OBJDIR)/main.o: $(SRCDIR)/main.c $(SRCDIR)/rog.h
	mkdir -p $(OBJDIR)
	$(CC) $(COMPILE_FLAGS) $(SRCDIR)/main.c -o $(OBJDIR)/main.o

$(OBJDIR)/rog.o: $(SRCDIR)/rog.c
	mkdir -p $(OBJDIR)
	$(CC) $(COMPILE_FLAGS) $(SRCDIR)/rog.c -o $(OBJDIR)/rog.o

$(OBJDIR)/tests.o: $(SRCDIR)/tests.c $(SRCDIR)/minunit.h $(SRCDIR)/rog.h
	mkdir -p $(OBJDIR)
	$(CC) $(COMPILE_FLAGS) $(SRCDIR)/tests.c -o $(OBJDIR)/tests.o

# Build the main files
build: $(MAIN_OBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) -g $(MAIN_OBJECTS) -o $(BUILDDIR)/main

# Build the test files
test: $(TEST_OBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) -g $(TEST_OBJECTS) -o $(BUILDDIR)/tests

run_tests: test
	./bin/tests

clean:
	rm -rfv $(OBJDIR)