#include <stdlib.h>
#include <stdio.h>

int main(void){
    int array[] = {5, 4, 8, 6, 12, 2, 14, 19, 3, 11, 6};
    
    int size = sizeof(array)/sizeof(array[0]);
    mergesort(array, 0, size - 1);
    
    for (int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}

void merge(int* a, int l, int m, int r){
    int s = r - l + 1; 
    int* merged = (int*)malloc(s * sizeof(int));

    int i, j, k;

    for (i = l, j = m + 1, k = 0; i <= m && j <= r; k++){
        if (a[i] < a[j]){
            merged[k] = a[i];
            i++;
        }
        else{
            merged[k] = a[j];
            j++;
        }
    }

    if (i > m){
        for(; j <= r; j++, k++){
            merged[k] = a[j];
        }
    }
    else{
        for(; i <= m; i++, k++){
            merged[k] = a[i];
        }
    }

    for (int i = l, k = 0; i <= r; i++, k++){
        a[i] = merged[k];
    }

    free(merged);
}

void mergesort(int* a, int l, int r){
    if (l == r){
        return;
    }
    
    int m = (l + r) / 2;
    mergesort(a, l, m);
    mergesort(a, m + 1, r);
    merge(a, l, m, r);
}