SRCDIR=src
OBJDIR=obj
CC=gcc
CFLAGS=-Wall -g -lrt -lm
OBJS=$(OBJDIR)/main.o $(OBJDIR)/rog.o $(OBJDIR)/test_rog.o

$(SRCDIR)%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJS)