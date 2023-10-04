#include <stdio.h>
#include <stdlib.h>

/*
    Merge n sorted arrays of length m

    Uses a min-heap instead of a linear comparison

    Time complexity: O(mn*log(n))
*/

typedef struct frontheap{
    int** front;
    int length;
    int heapsize;
}FrontHeap;

void printarr(int*, size_t);
void swap(int**, int, int);

int parent(int);
int right(int);
int left(int);

void min_heapify(FrontHeap*, int);
void build_min_heap(FrontHeap*);

void merge_arrays(int a[][11], int, int, int*);

int main(void){
    int arrs[5][11] = {
                        {4, 7, 8, 12, 16, 17, 22, 22, 23, 24, -1}, 
                        {3, 6, 7, 9, 12, 12, 13, 14, 19, 20, -1}, 
                        {11, 12, 17, 19, 25, 26, 29, 30, 33, 34, -1}, 
                        {1, 2, 8, 9, 11, 16, 17, 20, 21, 21, -1}, 
                        {2, 2, 5, 6, 15, 16, 18, 18, 20, 21, -1}
                    };

    int n = (sizeof(arrs)/sizeof(arrs[0]));
    int m = (sizeof(arrs[0])/sizeof(arrs[0][0])) - 1;

    int* output_arr = (int*)malloc(sizeof(arrs));
    merge_arrays(arrs, n, m, output_arr);
    printarr(output_arr, (size_t)(n * m));

    free(output_arr);
}

void printarr(int* a, size_t s){
    for (int i = 0; i < (int)s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int** a, int u, int v){
    int* t = a[u];
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

void min_heapify(FrontHeap* fh, int i){
    int l = left(i);
    int r = right(i);

    int smallest;

    if ((l < fh -> heapsize) && (*((fh -> front)[l]) < *((fh -> front)[i]))){
        smallest = l;
    }    
    else {
        smallest = i;
    }

    if ((r < fh -> heapsize) && (*((fh -> front)[r]) < *((fh -> front)[smallest]))){
        smallest = r;
    }

    if (smallest != i){
        swap(fh -> front, i, smallest);
        min_heapify(fh, smallest);
    } 
}

void build_min_heap(FrontHeap* fh){
    fh -> heapsize = fh -> length;
    
    for (int i = (int)(((fh -> length) - 1) / 2); i >= 0; i--){
        min_heapify(fh, i);
    }
}

void merge_arrays(int arrs[][11], int n, int m, int* out){
    int** front_vals = (int**)malloc(n * sizeof(int*));
    FrontHeap* fh = (FrontHeap*)malloc(sizeof(FrontHeap));

    for (int i = 0; i < n; i++){
        front_vals[i] = arrs[i];
    }

    fh -> front = front_vals;
    fh -> length = n;

    build_min_heap(fh);
    for (int i = 0; i < n * m; i++){
        out[i] = *((fh -> front)[0]);
        (fh -> front)[0]++;

        if (*((fh -> front)[0]) == -1){
            swap(fh -> front, 0, (fh -> heapsize) - 1);
            (fh -> heapsize)--;
        }

        min_heapify(fh, 0);
    }

    free(front_vals);
    free(fh);
}