#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>

#include "HW3Q3.h"

using namespace std;

int main() {

    int loss;
    int min_loss = INT16_MAX;
    vector<pair<int, int>> clients = {{4, 7}, {8, 10}, {3, 12}, {9, 4}, {17, 5}, {1, 2}, {12, 13}, {5, 2}};  // The first number of pair is impatience and the second number is time
    vector<pair<int, int>> best_order;
    sort(clients.begin(), clients.end());

    do {
        loss = find_loss(clients.size(), clients);
        if (loss < min_loss) {
            min_loss = loss;
            best_order.assign(clients.begin(), clients.end());
        }
    } while(next_permutation(clients.begin(), clients.end()));

    cout << "Best order of clients: ";
    print_clients(best_order);
    cout << "Loss: " << min_loss << endl << endl;

    greedy_algo(clients);
    cout << "Best order of clients by greedy algorithm: ";
    print_clients(clients);

    return 0;
}