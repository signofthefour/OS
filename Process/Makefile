all: process

process: fork.o
	g++ -o process fork.o

fork.o: fork.cpp
	g++ -c fork.cpp

clean:
	rm -r *.o process