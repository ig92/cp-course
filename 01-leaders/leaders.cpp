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

        // compute leaders
        int max = vect.at(vect.size()-1); 
        vector<int> leaders;
        leaders.push_back(max);
        for (int j = dim-2; j >= 0; --j) {
            if (vect.at(j) > max == 1) {
                leaders.push_back(vect.at(j));
                max = vect.at(j);
            }
        }
        
        // print leaders
        for (int j = leaders.size()-1; j >= 0; --j)
            cout << leaders.at(j) << " ";
        
        cout << endl;
    }

    return 0;
}