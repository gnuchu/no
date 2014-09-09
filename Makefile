CC?=gcc

all: no

no: no.o
	$(CC) no.o -o no

no.o: no.c
	$(CC) -c no.c

clean:
	rm -rf *o no
