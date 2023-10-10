#include <stdlib.h>
#include <iostream>
#include <vector>
#include "HW2Q2.h"

using namespace std;

Arrays::Arrays (vector<int>* vec) : initial_vector{*vec}, size{(int) (*vec).size()} { }

Arrays::~Arrays () {
    initial_vector.clear();
}

void Arrays::sort_array (int i, int j) {
    if (i == j)
        return;
    int m = (int) (i + j) / 2;
    sort_array(i, m);
    sort_array(m + 1, j);
    if (initial_vector[m] > initial_vector[j]) {
        print_vec();
        swap(m, j);
        print_vec();
        cout << endl;
    }
    sort_array(i, j - 1);
}

void Arrays::swap (int a, int b) {
    int copy_a = initial_vector[a];
    initial_vector[a] = initial_vector[b];
    initial_vector[b] = copy_a;
}

void Arrays::print_vec () {
    for (int ptr = 0; ptr < size; ptr++) {
        cout << initial_vector[ptr] << "   ";
    }
    cout << endl;
}