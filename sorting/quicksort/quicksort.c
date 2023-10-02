#include <stdio.h>
#include <stdlib.h>

void print_array(int*, int);
void swap(int*, int, int);

int partition(int*, int, int);
int partition_textbook(int*, int, int);

void quicksort(int*, int, int);

int main(void){
    int arr[] = {1, 1, 5, 2, 19, 3, 6, 13, 1, 19, 20, 12, 22, 5, 13, 19, 1, 13, 4, 6, 22, 8, 1, 9, 25, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    quicksort(arr, 0, len - 1);
    print_array(arr, len);
}

void print_array(int* a, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");
}

void swap(int* a, int u, int v){
    int t = a[u];
    a[u] = a[v];
    a[v] = t;
}

int partition(int* a, int start, int end){
    int p = a[start];
    
    int l = start + 1, r = end;
    for (; l < r;){
        if (a[l] > p && a[r] <= p){
            swap(a, l, r);
            l++, r--;
        }
        else{
            if (a[l] <= p){
                l++;
            }
            if (a[r] >= p){
                r--;
            }
        }
    }

    if (a[l] < p){
        swap(a, l, start);
        return l;
    }
    else {
        swap(a, l - 1, start);
        return l - 1;
    }
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

void quicksort(int* a, int start, int end){
    if (start < end){
        int p = partition_textbook(a, start, end);
        quicksort(a, start, p - 1);
        quicksort(a, p + 1, end);
    }
}