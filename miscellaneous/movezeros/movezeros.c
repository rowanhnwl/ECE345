#include <stdio.h>
#include <stdlib.h>

void swap(int*, int, int);

int printarr(int*, size_t);
int movezeros(int*, size_t);

int main(void){
    int arr[] = {5, 0, 3, 1, 0, 5, 6, 2, 0, 0, 1, 7};
}

int printarr(int* a, size_t s){
    for (int i = 0; i < s; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int movezeros(int* a, size_t s){

}