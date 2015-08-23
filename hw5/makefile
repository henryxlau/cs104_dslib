CC=g++
LIB = lib
SRC = source

all: hw5q4 hw5q5 hw5q7

hw5q4: arraylist_test.cpp $(LIB)/ArrayList.h $(LIB)/LinkedList.h $(LIB)/plusonearraylist.h $(LIB)/plustenarraylist.h $(LIB)/doublingarraylist.h
	mkdir -p bin
	$(CC) -g -Wall arraylist_test.cpp -o bin/$@ -I$(LIB)

hw5q5: speed_test.cpp $(LIB)/Ilist.h $(LIB)/ArrayList.h $(LIB)/LinkedList.h $(LIB)/plusonearraylist.h $(LIB)/plustenarraylist.h $(LIB)/doublingarraylist.h
	$(CC) -g -Wall speed_test.cpp -o bin/$@ -I$(LIB)

hw5q7: main.cpp $(LIB)/Ilist.h $(LIB)/LinkedList.h $(LIB)/Stack.h
	$(CC) -g -Wall main.cpp -o bin/$@ -I$(LIB)

.PHONY: clean

clean:
	rm -f *.o *~ bin/hw5q4.exe bin/hw5q5.exe bin/hw5q7.exe
