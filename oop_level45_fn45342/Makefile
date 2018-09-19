COMPILER = g++ -std=c++14 -Wall -Wextra -Wpedantic

all: InputBuffer.o InputReader.o ConstString.o
	$(COMPILER) main.cc InputBuffer.o InputReader.o ConstString.o

InputBuffer.o: DynamicArray.h InputBuffer/InputBuffer.h InputBuffer/InputBuffer.cc
	$(COMPILER) -c InputBuffer/InputBuffer.cc

InputReader.o: InputBuffer.o InputReader/InputReader.h InputReader/InputReader.cc
	$(COMPILER) -c InputReader/InputReader.cc

ConstString.o: ConstString/ConstString.h ConstString/ConstString.cc
	$(COMPILER) -c ConstString/ConstString.cc

clear:
	rm -rf a.out *.o