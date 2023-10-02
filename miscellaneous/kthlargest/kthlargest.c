#include <stdio.h>
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

void min_heapify(Heap*, int);
void build_min_heap(Heap*);

void kthlargest(Heap*, int);

int main(void){
    int arr[] = {1, 7, 5, 2, 19, 3, 6, 13, 17, 19, 20, 12, 22, 5, 13, 19, 11, 13, 4, 6, 22, 8, 14, 9, 25, 4};
    int k = 26;

    Heap* h = (Heap*)malloc(sizeof(Heap));
    (h -> a) = arr;
    (h -> length) = sizeof(arr) / sizeof(arr[0]);
    
    kthlargest(h, k - 1);

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

void kthlargest(Heap* h, int k){
    if (k < (h -> length) / 2){
        build_max_heap(h);

        for (int i = 0; i < k; i++){
            swap(h -> a, 0, (h -> length) - 1 - i);
            (h -> heapsize) -= 1;

            max_heapify(h, 0);
        }
    }
    else {
        build_min_heap(h);

        for (int i = 0; i < (h -> length) - k - 1; i++){
            swap(h -> a, 0, (h -> length) - 1 - i);
            (h -> heapsize) -= 1;

            min_heapify(h, 0);
        }
    }
    
    printf("%d", *(h -> a));
}