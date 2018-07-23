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
        for (int j = 0; j < dim; ++j) {
            int num;
            cin >> num;
            vect.push_back(num);
        }

        vector<int> nextLarger;
        int possibleLarger = vect.at(dim-1);
        nextLarger.push_back(-1);
        for (int j = dim-2; j >= 0; --j) {
            if (vect.at(j) < possibleLarger)
                nextLarger.push_back(possibleLarger);
        }
    }

    return 0;
}