#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "MinHeap.h"

/**
* Implementar Compares para todos los tipos. 
*/

struct Node* newNode(void* data) {
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	assert(node != NULL);
	node->data = data;
}


struct MinHeap* newMinHeap(compare compareTo) {
		/* El numero por default de elemntos es 30 */
	struct MinHeap* nuevo = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	assert(nuevo != NULL);
	nuevo->currentSize = 0;
	nuevo->arrayLength = 30;
	/* Aquí construímos los nodos del arrelo de elementos */
	nuevo->array = calloc(30, sizeof(struct Node*));
	int i;
	for (i = 0; i < 30; i++) {
		//printf("newMinHeap-agregué: %d\n", i);
		nuevo->array[i] = newNode(NULL); //Lo llenamos con nuevos Nodos con su data en NULL
	}
	nuevo->hole = 0;
	nuevo->compareTo = compareTo;
	return nuevo;
} 

struct MinHeap* newMinHeapSize(int size, compare compareTo) {
	struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	assert(heap != NULL);
	heap->currentSize = 0;
	heap->arrayLength = size;
	/* Aquí construímos los nodos del arrelo de elementos */
	heap->array = calloc(size, sizeof(struct Node*)); //Hacemos un arreglo temporal
	int i;
	for (i = 0; i < size; i++) {
		heap->array[i] = newNode(NULL); //Lo llenamos con nuevos Nodos con su data en NULL
	}
	heap->hole = 0;
	heap->compareTo = compareTo;
	return heap;
}

struct MinHeap* arrayToMinHeap(void* arr[], int size, compare compareTo) {
	struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
	assert(heap != NULL);
	heap->currentSize = size;
	heap->arrayLength = size*2;
	heap->array = calloc(size*2, sizeof(struct Node*)); //Hacemos un arreglo temporal
	int i;
	for (i = 0; i < size; i++) {
		insert(heap, arr[i]);
	}
	return heap;
}

void insert(void* elemento, struct MinHeap* heap) {
	/* Si ya está por llenarse el arrglo se hace más grande su arreglo */
	if (heap->currentSize == heap->arrayLength-1) {
		int size = heap->arrayLength;
		enlargeArray(size*2 + 1, heap);
	}
	int hole = ++heap->currentSize;
	struct Node* *array = heap->array;
	for (array[0] = elemento; heap->compareTo(elemento,array[hole/2]) < 0; hole /= 2) {
		array[hole] = array[hole/2];
	array[hole] = elemento;
	}
}





void enlargeArray(int newSize, struct MinHeap* heap) {
	struct Node* nuevo[newSize];
	int i;
	for (i = 0; i < heap->arrayLength; i++)
		nuevo[i] = heap->array[i];
	heap->array = nuevo;
}