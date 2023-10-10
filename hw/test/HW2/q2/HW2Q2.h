#include <stdlib.h>
#include <vector>

using namespace std;

class Arrays {
    private:
        vector<int> initial_vector;
        int size;
    public:
        Arrays (vector<int>*);
        ~Arrays ();
        void sort_array (int, int);
        void swap (int, int);
        void print_vec ();
};