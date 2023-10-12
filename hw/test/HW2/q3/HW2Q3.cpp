#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <iostream>
#include "HW2Q3.h"

using namespace std;

void find_union (int size, Lists* all_lists) {
    int a_ptr = 0;
    int b_ptr = 0;
    int most_recent = -1;

    while (a_ptr < size && b_ptr < size) {
        if (all_lists->a_vec[a_ptr] == all_lists->b_vec[b_ptr]) {
            if (all_lists->a_vec[a_ptr] > most_recent) {
                all_lists->union_list.push_back(all_lists->a_vec[a_ptr]);
                most_recent = all_lists->a_vec[a_ptr];
            }
            a_ptr++;
            b_ptr++;
        }
        else if (all_lists->a_vec[a_ptr] < all_lists->b_vec[b_ptr]) {
            if (all_lists->a_vec[a_ptr] > most_recent) {
                all_lists->union_list.push_back(all_lists->a_vec[a_ptr]);
                most_recent = all_lists->a_vec[a_ptr];
            }
            a_ptr++;
        }
        else if (all_lists->a_vec[a_ptr] > all_lists->b_vec[b_ptr]) {
            if (all_lists->b_vec[b_ptr] > most_recent) {
                all_lists->union_list.push_back(all_lists->b_vec[b_ptr]);
                most_recent = all_lists->b_vec[b_ptr];
            }
            b_ptr++;
        }
    }

    if (a_ptr == size) {
            for (;b_ptr < size; b_ptr++)
                if (all_lists->a_vec[size - 1] < all_lists->b_vec[b_ptr] && all_lists->b_vec[b_ptr] > most_recent) {
                    all_lists->union_list.push_back(all_lists->b_vec[b_ptr]);
                    most_recent = all_lists->b_vec[b_ptr];
                }
        }

        if (b_ptr == size) {
            for (;a_ptr < size; a_ptr++)
                if (all_lists->a_vec[a_ptr] > all_lists->b_vec[size - 1] && all_lists->a_vec[a_ptr] > most_recent) {
                    all_lists->union_list.push_back(all_lists->a_vec[a_ptr]);
                    most_recent = all_lists->a_vec[a_ptr];
                }
        }

    for (int i : all_lists->union_list) {
        cout << i << "  ";
    }
    cout << endl;
}

void find_intersection (int size, Lists* all_lists) {
    int a_ptr = 0;
    int b_ptr = 0;
    int most_recent = -1;

    while (a_ptr < size && b_ptr < size) {
        if (all_lists->a_vec[a_ptr] == all_lists->b_vec[b_ptr]) {
            if (all_lists->a_vec[a_ptr] != most_recent) {
                all_lists->intersection_list.push_back(all_lists->a_vec[a_ptr]);
                most_recent = all_lists->a_vec[a_ptr];
            }
            a_ptr++;
            b_ptr++;
        }
        else if (all_lists->a_vec[a_ptr] < all_lists->b_vec[b_ptr]) {
            a_ptr++;
        }
        else if (all_lists->a_vec[a_ptr] > all_lists->b_vec[b_ptr]) {
            b_ptr++;
        }
    }

    if (a_ptr == size) {
        for (;b_ptr < size; b_ptr++)
            if (all_lists->a_vec[size - 1] == all_lists->b_vec[b_ptr] && all_lists->b_vec[b_ptr] != most_recent) {
                all_lists->intersection_list.push_back(all_lists->b_vec[b_ptr]);
                most_recent = all_lists->b_vec[b_ptr];
            }
    }

    if (b_ptr == size) {
        for (;a_ptr < size; a_ptr++)
            if (all_lists->a_vec[a_ptr] == all_lists->b_vec[size - 1] && all_lists->a_vec[a_ptr] != most_recent) {
                all_lists->intersection_list.push_back(all_lists->a_vec[a_ptr]);
                most_recent = all_lists->a_vec[a_ptr];
            }
    }

    for (int i : all_lists->intersection_list) {
        cout << i << "  ";
    }
    cout << endl;
}

void find_diff (int size, Lists* all_lists, vector<int>* include, string diff_list) {
    int i_ptr = 0;
    int most_recent = -1;
    list<int>::iterator it = all_lists->intersection_list.begin();

    while (i_ptr < size) {
        if (include->at(i_ptr) < *it || it == all_lists->intersection_list.end()) {
            if (include->at(i_ptr) != most_recent) {
                (all_lists->diff)[diff_list].push_back(include->at(i_ptr));
                most_recent = include->at(i_ptr);
            }
            i_ptr++;
        }
        else if (include->at(i_ptr) > *it) {
            it++;
        }
        else {
            i_ptr++;
        }
    }

    for (int i : (all_lists->diff)[diff_list]) {
        cout << i << "  ";
    }
    cout << endl;
}

int main() {
    vector<int> array_a = {1, 2, 5, 6, 10, 10, 22, 31, 43};
    vector<int> array_b = {2, 2, 7, 8, 10, 15, 17, 22, 31};
    int size = array_a.size();

    Lists* lists = new Lists;
    lists->a_vec = array_a;
    lists->b_vec = array_b;

    find_union(size, lists);
    find_intersection(size, lists);
    find_diff(size, lists, &(lists->a_vec), "a_diff_b");
    find_diff(size, lists, &(lists->b_vec), "b_diff_a");

    array_a.clear();
    array_b.clear();

    (lists->a_vec).clear();
    (lists->b_vec).clear();
    (lists->union_list).clear();
    (lists->intersection_list).clear();
    for (map<string, list<int>>::iterator it = lists->diff.begin(); it != lists->diff.end(); it++) {
        it->second.clear();
    }

    delete lists;
}
