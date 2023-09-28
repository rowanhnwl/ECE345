#include <stdio.h>
#include <stdlib.h>

typedef struct heap{
    int* a;
    int length;
    int heapsize;
}Heap;

int parent(int);
int right(int);
int left(int);

void print_heap(Heap*);
void swap(Heap*, int, int);

void max_heapify(Heap*, int);
void build_max_heap(Heap*);
void heapsort(Heap*);

int main(void){
    int arr[] = {1, 5, 2, 19, 12, 22, 5, 19, 1, 4, 6, 22, 8, 1, 9, 25};

    Heap* h = (Heap*)malloc(sizeof(Heap));
    (h -> a) = arr;
    (h -> length) = sizeof(arr) / sizeof(arr[0]);

    heapsort(h);

    free(h);
}

int parent(int i){
    return (int)(i / 2);
}

int right(int i){
    return (2 * i + 1);
}

int left(int i){
    return (2 * i);
}

void print_heap(Heap* h){
    for (int i = 0; i < (h -> length); i++){
        printf("%d ", (h -> a)[i]);
    }
    printf("\n");
}

void swap(Heap* h, int j, int k){
    int t = (h -> a)[j];

    (h -> a)[j] = (h -> a)[k];
    (h -> a)[k] = t; 
}

void max_heapify(Heap* h, int i){
    int l = left(i);
    int r = right(i);

    int largest;

    if ((l < h -> heapsize) && ((h -> a)[l] > (h -> a)[i])){
        largest = l;
    }    
    else {
        largest = i;
    }

    if ((r < h -> heapsize) && ((h -> a)[r] > (h -> a)[largest])){
        largest = r;
    }

    if (largest != i){
        swap(h, i, largest);
        max_heapify(h, largest);
    } 
}

void build_max_heap(Heap* h){
    (h -> heapsize) = (h -> length);

    for (int i = (int)(((h -> length) - 1) / 2); i >= 0; i--){
        max_heapify(h, i);
    }
}

void heapsort(Heap* h){
    build_max_heap(h);

    for (int i = (h -> length) - 1; i >= 1; i--){
        swap(h, 0, i);
        (h -> heapsize) = i;

        max_heapify(h, 0);
    }

    print_heap(h);
}