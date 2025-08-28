CFLAGS = -Wall -Werror -Wpedantic -std=c2x

justify: justify.o word.o line.o
	gcc -o justify justify.o word.o line.o

justify.o: justify.c word.h line.h
	gcc -c $(CFLAGS) justify.c

word.o: word.c word.h
	gcc -c $(CFLAGS) word.c

line.o: line.c line.h
	gcc -c $(CFLAGS) line.c

clean:
	rm justify.o line.o word.o
