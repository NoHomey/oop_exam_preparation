CC = g++ -std=c++11 -Wall -Wextra -Wpedantic

all: main

main: Timestamp.o Appointment.o
	$(CC) Timestamp.o Appointment.o main.cc

Timestamp.o: Timestamp.h Timestamp.cc
	$(CC) -c Timestamp.cc

Appointment.o: Timestamp.o Appointment.h Appointment.cc
	$(CC) -c Appointment.cc

clean:
	rm -f *.o
	rm -f a.out