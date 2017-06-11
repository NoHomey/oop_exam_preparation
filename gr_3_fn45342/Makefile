CC = g++ -std=c++14 -Wall -Werror -Wpedantic

all: String.o Button.o Password.o Checkbox.o TextField.o main.cc
	$(CC) main.cc String.o Button.o Password.o Checkbox.o TextField.o

String.o: DynamicArray.h String.h String.cc
	$(CC) -c String.cc

Button.o: String.o HTMLElement.h Button.h Button.cc
	$(CC) -c Button.cc

Password.o: String.o HTMLElement.h Password.h Password.cc
	$(CC) -c Password.cc

Checkbox.o: String.o HTMLElement.h Checkbox.h Checkbox.cc
	$(CC) -c Checkbox.cc
TextField.o: String.o HTMLElement.h TextField.h TextField.cc
	$(CC) -c TextField.cc

clean:
	rm *.o a.out