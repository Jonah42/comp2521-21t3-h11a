CC=gcc
CFLAGS=-g

q2: q2.o graph.o list.o
	$(CC) q2.o graph.o list.o -o q2

q2.o: q2.c graph.h
	$(CC) $(CFLAGS) q2.c -o q2.o -c

graph.o: graph.c graph.h
	$(CC) $(CFLAGS) graph.c -o graph.o -c

list.o: list.c list.h
	$(CC) $(CFLAGS) list.c -o list.o -c