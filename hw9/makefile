CC=g++

all: hw9q2 hw9q3 hw9q4

hw9q2: hw9q2.cpp bst.h
	$(CC) -g -Wall hw9q2.cpp -o hw9q2

hw9q3: rb_test.cpp rbbst.h bst.h
	$(CC) -g -Wall rb_test.cpp -o hw9q3

hw9q4: hw9q4.cpp
	$(CC) -g -Wall hw9q4.cpp -o hw9q4 -std=c++11

.PHONY: clean

clean:
	rm -f *.o *~ hw9q2 hw9q3 hw9q4