CC = g++ -std=c++14 -Wall -Wextra -Wpedantic

all: main

main: Vector.o
	$(CC) Vector.o main.cc

Vector.o: Vector/Vector.h Vector/Vector.cc
	$(CC) -c Vector/Vector.cc

clean:
	rm -f *.o
	rm -f a.out