CC = g++ -std=c++14 -Wall -Wextra -Wpedantic

define Component
$(1).o: $(2) ./../$(1)/$(1).h ./../$(1)/$(1).cc
	$(CC) -c ./../$(1)/$(1).cc
endef

all: main

main: Vector.o Set.o Ingredient.o Spice.o Vegetable.o Salad.o
	$(CC) $^ main.cc

$(eval $(call Component,Vector))

$(eval $(call Component,Set,Vector.o))

$(eval $(call Component,Ingredient,Set.o))

$(eval $(call Component,Spice,Ingredient.o))

$(eval $(call Component,Vegetable,Ingredient.o))

$(eval $(call Component,Salad,Ingredient.o Set.o Spice.o Vegetable.o))

clean:
	rm -f *.o
	rm -f a.out