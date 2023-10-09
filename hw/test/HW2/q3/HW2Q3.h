#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

typedef struct new_list {
    vector<int> a_vec;
    vector<int> b_vec;
    list<int> union_list;
    list<int> intersection_list;
    map<string, list<int>> diff;
}Lists;

void find_union (int, Lists*);
void find_intersection (int, Lists*);
void find_diff (int, Lists*, vector<int>*, string);