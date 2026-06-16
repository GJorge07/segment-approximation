CC = gcc
CFLAGS = -Wall -g

programa: main.o ponto.o heap.o
	$(CC) $(CFLAGS) -o programa main.o ponto.o heap.o -lm

main.o: main.c ponto.h heap.h
	$(CC) $(CFLAGS) -c main.c

ponto.o: ponto.c ponto.h
	$(CC) $(CFLAGS) -c ponto.c

heap.o: heap.c heap.h
	$(CC) $(CFLAGS) -c heap.c

guloso.o: guloso.c guloso.h ponto.h heap.h
	$(CC) $(CFLAGS) -c guloso.c

clean:
	rm -f *.o programa