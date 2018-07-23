#include <iostream>
#include <vector>
#include <deque>
using namespace std;

/**
 * Note: this code assumes no error in input
 * It is only thought for coding competition purposes.
 */

/**
 * Prints the maximum among each of k consecutive
 * values in vect.
 */
void print_maximums(vector<int> a, int k) {
    deque <int> q;

    // first max in queue
    int max = 0;
    int i = 1;
    for (; i < k; ++i) {
        if (a[max] < a[i]) {
            max = i;
        }
    }
    i = max;
    for (i = max; i < k; ++i)
        q.push_back(i);

    cout << a[q.front()] << " ";
    
    for (; i < a.size(); ++i) {
        // update sliding window
        q.pop_front();
        q.push_back(i);

        // if max just got out, find the next one
        if (max < i-k+1) {
            while (!q.empty() && a[i] > a[q.front()])
                q.pop_front();
            max = q.front();
        }

        cout << a[q.front()] << " ";
    }
}

int main() {
    // number of cases in input
    int cases;
    cin >> cases;

    // read input data
    for (int i = 0; i < cases; ++i) {
        // dimension of the next array
        int dim, k;
        cin >> dim >> k;

        vector<int> vect;

        // read the array
        for (int j = 0; j < dim; ++j) {
            int num;
            cin >> num;
            vect.push_back(num);
        }
        
        print_maximums(vect, k);
        
        cout << endl;
    }

    return 0;
}