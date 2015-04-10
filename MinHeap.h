typedef int (*compare)(void*, void*);

struct Node {
	void* data;
};

struct MinHeap {	
	/* El arreglo genérico con los elementos */
	struct Node* *array;
	/* El numero de elementos en el heap */
	int currentSize;
	/* El tamaño del arrglo */
	int arrayLength;
	/* Función de compare */
	compare compareTo;

	int hole;
};

struct Node* newNode(void* data);
/**
* "Constructor" para min Heaps
* Regresa un apuntador a una estructura MinHeap
*/

struct MinHeap* newMinHeap(compare);

/**
* Construye un MinHeap con el tamaño especificado. 
*/

struct MinHeap* newMinHeapSize(int, compare);

/**
* Construye un MinHeap a partir de un arreglo de elementos
*/

struct MinHeap* arrayToMinHeap(void* *arr, int, compare);

/**
* Inserta un elemento en el Heap
* 
*/

void insert(void*, struct MinHeap*);

/**
* Busca al elemento mínimo en un heap y lo regresa.
* 
*/

void* findMin(struct MinHeap*);

/**
* Elimina el elemento mínimo y lo regresa.
* 
*/

void* deleteMin(struct MinHeap*);

/**
* Nos dice si el heap es vacío 
* 
*/

int isEmpty(struct MinHeap*);

/**
* Hace vacía a un MInHeap y libera su memoria. 
* 
*/

void makeEmpty(struct MinHeap*);

/**
* PRIVADO 
* Hace engrandece al arreglo de elemntos.
*/

void enlargeArray(int, struct MinHeap*);

