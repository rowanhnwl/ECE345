#include <stdio.h>
#include <stdlib.h>

#include "structures/adjlist/list.h"

int main(void){
    NodeList* list = init_list();

    list_insert(list, 4);
    list_insert(list, 2);
    list_insert(list, 1);
    list_insert(list, 6);
    list_insert(list, 7);
    list_insert(list, 5);
    list_insert(list, 3);
    list_insert(list, 8);

    print_list(list);

    list_delete(list, 4);
    list_delete(list, 8);
    list_delete(list, 7);

    list_delete(list, 8);

    print_list(list);

    if (list_search(list, 12) != NULL){
        printf("Found 5\n");
    }

    list_dealloc(list);
}