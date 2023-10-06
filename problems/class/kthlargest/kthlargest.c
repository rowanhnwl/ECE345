#include <stdio.h>
#include <stdlib.h>

/*
    Find the kth largest element in an array

    Two methods:

    1. Using a min or max heap depending on the value of k O(n*logn)
    2. Using QuickSelect O(n)
*/

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

void kthlargest_heap(Heap*, int);

int partition_textbook(int*, int, int);
void kthlargest_partition(int*, int, size_t);

int main(void){
    int arr[] = {1, 7, 5, 2, 19, 3, 6, 13, 17, 19, 20, 12, 22, 5, 13, 19, 11, 13, 4, 6, 22, 8, 14, 9, 25, 4};
    int k = 26;
    size_t s = sizeof(arr) / sizeof(arr[0]);

    Heap* h = (Heap*)malloc(sizeof(Heap));
    (h -> a) = arr;
    (h -> length) = s;
    
    //kthlargest_heap(h, k - 1);
    kthlargest_partition(arr, k, s);

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

void kthlargest_heap(Heap* h, int k){
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

int partition_textbook(int* a, int l, int r){
    int x = a[r];
    int i = l - 1;

    for(int j = l; j <= r - 1; j++){
        if (a[j] <= x){
            i++;
            swap(a, i, j);
        }
    }
    swap(a, i + 1, r);

    return i + 1;
}

void kthlargest_partition(int* a, int k, size_t s){
    int rev_k = s - k;
    
    int p = 0;
    int l = 1;
    int r = s - 1;

    while (p != rev_k){
        p = partition_textbook(a, l, r);

        if (p < rev_k){
            l = p + 1;
        }
        else{
            r = p - 1;
        }
    }

    printf("%d\n", *(a + p));
}