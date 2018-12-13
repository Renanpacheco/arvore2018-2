CC=gcc
LDFLAGS= -lm
CFLAGS=-Wall -Wextra -Werror -O0 -g -std=c11 -I.. 

.PHONY: all 


all: grade

arvore.o: arvore.h arvore.c
	$(CC) $(CFLAGS) -c arvore.c

# coloque outras dependencias aqui


test: arvore.o test.c
	$(CC) $(CFLAGS) -o test arvore.o test.c $(LDFLAGS)

grade: test
	./test

clean:
	rm -rf *.o test

