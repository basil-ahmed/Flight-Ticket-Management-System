output: main.o flightticket.o flighthashtable.o
	g++ main.o flightticket.o flighthashtable.o -o output
main.o: main.cpp flightticket.h flighthashtable.h
	g++ -c main.cpp
flightticket.o: flightticket.h flightticket.cpp
	g++ -c flightticket.cpp
flighthashtable.o: flighthashtable.h flighthashtable.cpp
	g++ -c flighthashtable.cpp

clean:
	rm *.o output