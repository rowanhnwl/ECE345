#include <stdlib.h>
#include <vector>

using namespace std;

void print_clients (vector<pair<int, int>>&);
int find_loss (int, vector<pair<int, int>>&);
void greedy_algo (vector<pair<int, int>>&);
bool compare (pair<int, int>&, pair<int, int>&);