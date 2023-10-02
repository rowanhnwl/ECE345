#include <stdio.h>
#include <stdlib.h>

#include <utils.h>

void printarr(int* a, size_t s){
    for (int i = 0; i < s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int* a, int u, int v){
    int t = a[u];
    a[u] = a[v];
    a[v] = t;
}