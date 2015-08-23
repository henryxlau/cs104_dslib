CC=g++

all: hw8q2a hw8q3 hw8q4

hw8q2a: hw8q2a.cpp quicksort.h
	$(CC) -g -Wall hw8q2a.cpp -o hw8q2a

hw8q3: hw8q3.cpp quicksort.h
	$(CC) -g -Wall hw8q3.cpp -o hw8q3

hw8q4: hw8q4.cpp Heap.h
	$(CC) -g -Wall hw8q4.cpp -o hw8q4

.PHONY: clean

clean:
	rm -f *.o *~ hw8q2a hw8q3 hw8q4