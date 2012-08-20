all: no

no: no.o
	gcc no.o -o no

no.o: no.c
	gcc -c no.c

clean:
	rm -rf *o no
