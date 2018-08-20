#include <iostream>
#include <vector>
using namespace std;

/**
 * Note: this code assumes no error in input
 * It is only thought for coding competition purposes.
 */

int main() {
    // number of cases in input
    int cases;
    cin >> cases;

    // read input data
    for (int i = 0; i < cases; ++i) {
        // dimension of the next array
        int dim;
        cin >> dim;

        vector<int> vect;

        // read the array
        for (int j = 0; j < dim-1; ++j) {
            int num;
            cin >> num;
            vect.push_back(num);
        }

        int gauss = (dim * dim + dim) >> 1;

        for (int j = 0; j < dim-1; ++j)
            gauss -= vect.at(j);
        
        cout << gauss << endl;
    }

    return 0;
}