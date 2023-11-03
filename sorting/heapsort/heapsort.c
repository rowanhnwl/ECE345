#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "heapsort.h"

int main(void){
    int arr[] = {6, 3, 7, 9, 2, 5, 6, 3, 2, 9, 5, 1, 7, 4, 6};

    Heap* h = (Heap*)malloc(sizeof(Heap));
    (h -> a) = arr;
    (h -> length) = sizeof(arr) / sizeof(arr[0]);

    midtermQ2(h, 9);
    heapsort(h);

    free(h);
}

void printarr(int* a, size_t s){
    for (int i = 0; i < (int)s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int* a, int u, int v){
    int t = a[u];
    a[u] = a[v];
    a[v] = t;
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
        swap(h -> a, i, largest);
        max_heapify(h, largest);
    } 
}

void build_max_heap(Heap* h){
    (h -> heapsize) = (h -> length);

    for (int i = (int)(((h -> length) - 1) / 2); i >= 0; i--){
        max_heapify(h, i);
    }
}

void min_heapify(Heap* h, int i){
    int l = left(i);
    int r = right(i);

    int smallest;

    if ((l < h -> heapsize) && ((h -> a)[l] < (h -> a)[i])){
        smallest = l;
    }    
    else {
        smallest = i;
    }

    if ((r < h -> heapsize) && ((h -> a)[r] < (h -> a)[smallest])){
        smallest = r;
    }

    if (smallest != i){
        swap(h -> a, i, smallest);
        min_heapify(h, smallest);
    } 
}

void build_min_heap(Heap* h){
    (h -> heapsize) = (h -> length);

    for (int i = (int)(((h -> length) - 1) / 2); i >= 0; i--){
        min_heapify(h, i);
    }
}

void heapsort(Heap* h){
    build_max_heap(h);

    for (int i = (h -> length) - 1; i >= 1; i--){
        swap(h -> a, 0, i);
        (h -> heapsize) = i;

        max_heapify(h, 0);
    }

    printarr(h -> a, h -> length);
}

void midtermQ2(Heap* h, int k){
    build_min_heap(h);
    int hs = pow(2, (int)(log2(k) + 1)) - 1;

    int count = k;

    (h -> heapsize) = hs;
    for (int i = (h -> length) - 1; count >= 0; i--, count--){
        swap(h -> a, 0, i);

        min_heapify(h, 0);
    }

    for (int i = 0; i < k; i++){
        printf("%d ", (h -> a)[h -> length - 1 - i]);
    }
    printf("\n");
}