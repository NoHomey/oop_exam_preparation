CC = g++ -std=c++14 -Wall -Wextra -Wpedantic

all: main

main: Vector.o Set.o Ingredient.o Spice.o Vegetable.o Salad.o
	$(CC) $^ main.cc

Vector.o: ./../Vector/Vector.h ./../Vector/Vector.cc
	$(CC) -c ./../Vector/Vector.cc

Set.o: Vector.o ./../Set/Set.h ./../Set/Set.cc
	$(CC) -c ./../Set/Set.cc

Ingredient.o: Set.o ./../Ingredient/Ingredient.h ./../Ingredient/Ingredient.cc
	$(CC) -c ./../Ingredient/Ingredient.cc

Spice.o: Ingredient.o ./../Spice/Spice.h ./../Spice/Spice.cc
	$(CC) -c ./../Spice/Spice.cc
	
Vegetable.o: Ingredient.o ./../Vegetable/Vegetable.h ./../Vegetable/Vegetable.cc
	$(CC) -c ./../Vegetable/Vegetable.cc

Salad.o: Ingredient.o Set.o Spice.o Vegetable.o ./../Salad/Salad.h ./../Salad/Salad.cc
	$(CC) -c ./../Salad/Salad.cc

clean:
	rm -f *.o
	rm -f a.out