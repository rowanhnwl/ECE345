#include <stdlib.h>

typedef struct chainnode {
    int value;
    struct chainnode* next;
}ChainNode;

typedef struct hashchain {
    struct chainnode* head;
}HashChain;

typedef struct standardcht {
    int m;
    char hf;
    HashChain** table;
}StandardCHT;

void print_ht(StandardCHT*);

int get_m(int*, int);

int hash_divide(int, int);
int hash_multiply(int, int);

HashChain** build_empty_ht_chaining(int);
StandardCHT* create_CHT(int*, int, char);

void hash_at_index(HashChain*, int);
void load_table(int*, int, StandardCHT*);

void free_cht(StandardCHT*);