CC=g++

all: hw3q1.o hw3q3.o hw3q5.o

hw3q1.o: testq1.cpp
	$(CC) -g testq1.cpp -o hw3q1

hw3q3.o: List.h ListImpl.hpp test.cpp
	$(CC) -g List.h test.cpp -o hw3q3

hw3q5.o: List.h ListImpl.hpp Map.h MapImpl.hpp main.cpp
	$(CC) -g List.h Map.h main.cpp -o hw3q5

.PHONY: clean

clean:
	rm -f *.o *.exe *~ hw1q1 hw3q3 hw3q5
