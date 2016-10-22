CC=clang
PERL=/usr/bin/perl

all: version no

no: no.o
	$(CC) no.o -o no
	rm -rf *.o
	chmod +x ./no

no.o: clean no.c
	$(CC) -c no.c

version: 
	$(PERL) version_bumper.pl no.c

clean:
	rm -rf *.o no
