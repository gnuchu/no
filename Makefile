CC?=gcc

all: no

no: no.o
	$(CC) no.o -o no
	rm -rf *.o
	chmod +x ./no

no.o: clean no.c
	$(CC) -c no.c

clean:
	rm -rf *.o no
