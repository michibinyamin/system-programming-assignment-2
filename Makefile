# Flags and commands
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean

all: my_graph my_Knapsack

my_graph: my_graph.o libmymat.a
	$(CC) $(CFLAGS) $^ -o $@

my_Knapsack: my_Knapsack.o 
	$(CC) $(CFLAGS) $< -o $@

libmymat.a: my_mat.o
	$(AR) $(AFLAGS) $@ $<

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c $<

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c $<

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o *.a my_graph my_Knapsack