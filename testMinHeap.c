#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>
#include "MinHeap.h"

int main(int argc, char const *argv[]) {
	/* Prueba constructores */
	/* Para numeros random */
	time_t t;
	srand((unsigned) time(&t));

	struct MinHeap* test = newMinHeap();
	int ran = (rand() % 200);

	struct MinHeap* testSize = newMinHeapSize(ran);
	/* Probamos si newHeap construye bien */
	int i; 
	for (i = 0; i < test->arrayLength; i++) {
		assert(test->array[i]->data == NULL);
	}
	/* Probamos si newHeapSize construye bien */
	for (i = 0; i < ran; i++) {
		assert(testSize->array[i]->data == NULL);
	}
	
	int a[] = {1, 2, 3, 4};
	arrayToMinHeap(a, 4);

}
