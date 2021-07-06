# You can change the compiler to something like clang
# by replacing the default value gcc, with something like clang
# e.g.
# CC=clang
CC=gcc
SRCDIR=src
OBJDIR=obj
BUILDDIR=bin
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
	$(CC) -g $(MAIN_OBJECTS) -o $(BUILDDIR)/rog

# Build the test files
test: $(TEST_OBJECTS)
	mkdir -p $(BUILDDIR)
	$(CC) -g $(TEST_OBJECTS) -o $(BUILDDIR)/tests

run_tests: test
	./bin/tests

# Installs to /usr/local/bin by default,
# to change this, replace /usr/local/bin to whatever 
# directory you want to install rog to
install:
	install bin/rog /usr/local/bin

clean:
	rm -rfv $(OBJDIR)