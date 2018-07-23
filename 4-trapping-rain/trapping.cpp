#include <iostream>
#include <vector>
using namespace std;

/**
 * Note: this code assumes no error in input
 * It is only thought for coding competition purposes.
 */

void print_trappings(vector<int>);

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
        
        print_trappings(vect);
    }

    return 0;
}

/**
 * Prints the number of tappings of an elevation map.
 */
void print_trappings(vector<int> vect) {
    if (vect.empty())
        return;

    int traps = 0;
    int current = vect.at(0);

    vector<int>::iterator it;
    for (it = vect.begin(); it != vect.end(); ++it)
        if (current > *it)
            traps += (current - *it);
        else
            current = *it;

    cout << traps << endl;
}