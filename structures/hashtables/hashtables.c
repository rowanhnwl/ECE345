#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#include <hashtables.h>

int main(void){
    int arr[] = {27, 1, 35, 5, 16, 2, 45, 36, 19, 31, 3, 43, 6, 13, 28, 20, 37, 12, 22, 38, 4, 8, 9, 25, 51};
    int asize = sizeof(arr) / sizeof(arr[0]);

    StandardCHT* chained_HT = create_CHT(arr, asize, 'd');
    print_ht(chained_HT);

    free_cht(chained_HT);
}

void print_ht(StandardCHT* cht){
    for (int i = 0; i < cht -> m; i++){
        printf("%d: ", i);
        ChainNode* cnode = (cht -> table)[i] -> head;

        while (cnode != NULL){
            printf("%d ", cnode -> value);
            cnode = cnode -> next;
        }
        printf("\n");
    }
}

int get_m(int* a, int s){
    int max = -INT_MAX;
    
    for (int i = 0; i < s; i++){
        if (a[i] > max){
            max = a[i];
        }
    }

    int half = max / 2;
    
    if (half % 2 == 0){
        return half - 1;
    }
    else {
        return half;
    }
}

int hash_divide(int k, int m){
    return (k % m);
}

int hash_multiply(int k, int m){
    float A = 0.31415;
    double t;

    float md = modf(k * A, &t);
    return (int)(m * md);
}

HashChain** build_empty_ht_chaining(int m){
    HashChain** new_table = (HashChain**)malloc(m * sizeof(HashChain*));

    for (int i = 0; i < m; i++){
        new_table[i] = (HashChain*)malloc(sizeof(HashChain));
        new_table[i] -> head = NULL;
    }

    return new_table;
}

void hash_at_index(HashChain* c, int val){
    ChainNode* new_node = (ChainNode*)malloc(sizeof(ChainNode));
    new_node -> value = val;

    new_node -> next = c -> head;
    c -> head = new_node;
}

void load_table(int* a, int s, StandardCHT* cht){
    for (int i = 0; i < s; i++){
        int index;
        if (cht -> hf == 'd'){
            index = hash_divide(a[i], cht -> m);
        }
        else if (cht -> hf == 'm'){
            index = hash_multiply(a[i], cht -> m);
        }

        hash_at_index((cht -> table)[index], a[i]);
    }
}

StandardCHT* create_CHT(int* a, int s, char func){
    int tm = get_m(a, s);
    HashChain** htable = build_empty_ht_chaining(tm);

    StandardCHT* chained_hash_table = (StandardCHT*)malloc(sizeof(StandardCHT));
    chained_hash_table -> m = tm;
    chained_hash_table -> hf = func;
    chained_hash_table -> table = htable;

    load_table(a, s, chained_hash_table);

    return chained_hash_table;
}

void free_cht(StandardCHT* cht){
    // Free each chained node
    for (int i = 0; i < cht -> m; i++){
        while ((cht -> table)[i] -> head != NULL){
            ChainNode* delnode = (cht -> table)[i] -> head;
            (cht -> table)[i] -> head = (cht -> table)[i] -> head -> next;
            
            delnode -> next = NULL;
            free(delnode);
        }

        // Free the chain structure
        free((cht -> table)[i]);
    }

    // Free the full table
    free(cht -> table);
    free(cht);
}