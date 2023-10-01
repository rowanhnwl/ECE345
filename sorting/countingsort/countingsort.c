#include <stdio.h>
#include <stdlib.h>

void printarr(int*, size_t);
void initarr(int*, size_t);

int getk(int*, size_t);
void countingsort(int*, size_t);

int main(void){
    int arr[] = {1, 5, 2, 19, 12, 22, 5, 19, 1, 4, 6, 22, 8, 1, 9, 25};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    countingsort(arr, size);
    printarr(arr, size);
}

void printarr(int* a, size_t s){
    for (int i = 0; i < (int)s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void initarr(int* a, size_t s){
    for (int i = 0; i < (int)s; i++){
        a[i] = 0;
    }
}

int getk(int* a, size_t s){
    int max = 0;
    
    for (int i = 0; i < (int)s; i++){
        if (a[i] > max){
            max = a[i];
        }
    }

    return max;
}

void countingsort(int* a, size_t s){
    int k = getk(a, s);
    int* b = (int*)malloc(s*sizeof(int));
    int* c = (int*)malloc((k + 1)*sizeof(int));
    initarr(c, k + 1);

    for (int i = 0; i < (int)s; i++){
        c[a[i]]++;
    }

    for (int i = 1; i <= k; i++){
        c[i] += c[i - 1];
    }
    
    for (int i = s - 1; i >= 0; i--){
        b[c[a[i]] - 1] = a[i];
        c[a[i]]--;
    }

    for (int i = 0; i < (int)s; i++){
        a[i] = b[i];
    }

    free(b);
    free(c);
}