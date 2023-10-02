#include <stdlib.h>

typedef struct heap{
    int* a;
    int length;
    int heapsize;
}Heap;

void printarr(int* a, size_t s);
void swap(int* a, int u, int v);

int parent(int);
int right(int);
int left(int);

void max_heapify(Heap*, int);
void build_max_heap(Heap*);
void heapsort(Heap*);