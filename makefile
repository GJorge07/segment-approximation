CC = gcc
CFLAGS = -Wall -g

OBJS = main.o ponto.o heap.o guloso.o

programa: $(OBJS)
	$(CC) $(CFLAGS) -o programa $(OBJS) -lm

main.o: main.c ponto.h heap.h guloso.h
	$(CC) $(CFLAGS) -c main.c

ponto.o: ponto.c ponto.h
	$(CC) $(CFLAGS) -c ponto.c

heap.o: heap.c heap.h ponto.h
	$(CC) $(CFLAGS) -c heap.c

guloso.o: guloso.c guloso.h ponto.h heap.h
	$(CC) $(CFLAGS) -c guloso.c

clean:
	rm -f *.o programa
