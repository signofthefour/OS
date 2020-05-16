all: test

test: ex1.o main.o
	gcc -o test ex1.o main.o

main.o: main.c
	gcc -c main.c

ex1.o: ex1.c
	gcc -c ex1.c

clean:
	rm *.o test