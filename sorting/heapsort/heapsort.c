#include <stdio.h>
#include <stdlib.h>

#include <heapsort.h>

int main(void){
    int arr[] = {1, 5, 2, 19, 12, 22, 5, 19, 1, 4, 6, 22, 8, 1, 9, 25};

    Heap* h = (Heap*)malloc(sizeof(Heap));
    (h -> a) = arr;
    (h -> length) = sizeof(arr) / sizeof(arr[0]);

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

void heapsort(Heap* h){
    build_max_heap(h);

    for (int i = (h -> length) - 1; i >= 1; i--){
        swap(h -> a, 0, i);
        (h -> heapsize) = i;

        max_heapify(h, 0);
    }

    printarr(h -> a, h -> length);
}