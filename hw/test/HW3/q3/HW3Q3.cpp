#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

#include "HW3Q3.h"

using namespace std;

void print_clients (vector<pair<int, int>>& clients) {
    cout << "| ";
    for (auto client : clients) {
        cout << "(" << client.first << ", " << client.second << ") | ";
    }
    cout << endl;
}

int find_loss (int size, vector<pair<int, int>>& clients) {
    
    int loss = 0;
    int time = 0;
    print_clients(clients);

    for (int i = 0; i < size; i++) {
        time += clients[i].second;
        loss += clients[i].first * time;
    }
    cout << "Loss: " << loss << endl << endl;

    return loss;
}

void greedy_algo (vector<pair<int, int>>& clients) {
    sort(clients.begin(), clients.end(), compare);
}

bool compare (pair<int, int>& a, pair<int, int>& b) {
    return ((double) a.first / a.second) > ((double) b.first / b.second);
}
