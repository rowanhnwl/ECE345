#include <stdio.h>
#include <stdlib.h>

void swap(int*, int, int);

void printarr(int*, size_t);
void movezeros_back(int*, size_t);
void movezeros_front(int*, size_t);

int main(void){
    int arr[] = {5, 0, 3, 1, 0, 5, 6, 2, 0, 0, 1, 7};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    movezeros_front(arr, size);
    printarr(arr, size);
}

void swap(int* a, int u, int v){
    int t = a[u];
    a[u] = a[v];
    a[v] = t;
}

void printarr(int* a, size_t s){
    for (int i = 0; i < (int)s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void movezeros_back(int* a, size_t s){
    int i = -1;

    for (int j = 0; j < (int)s; j++){
        if (a[j] > 0){
            i++;
            swap(a, i, j);
        }
    }
}

void movezeros_front(int* a, size_t s){
    int i = s;

    for (int j = (int)(s - 1); j >= 0; j--){
        if (a[j] > 0){
            i--;
            swap(a, i, j);
        }
    }
}