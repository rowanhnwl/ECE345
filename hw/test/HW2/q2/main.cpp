#include "stdlib.h"
#include <vector>
#include "HW2Q2.h"

using namespace std;

int main () {

    vector<int> num_vec = {1, 6, 7, 2, 8, 3, 10, 4};
    Arrays num_array(&num_vec);
    num_array.sort_array(0, num_vec.size() - 1);

    num_vec.clear();

    return 0;
}