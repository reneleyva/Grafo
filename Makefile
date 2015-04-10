HEADERS = MinHeap.h

default: testHeap

MinHeap.o: MinHeap.c $(HEADERS)
	gcc -c MinHeap.c -o MinHeap.o

testHeap.o: testMinHeap.c $(HEADERS)
	gcc -c testMinHeap.c -o testHeap.o

testHeap: MinHeap.o testHeap.o
	gcc -o testHeap MinHeap.o testHeap.o