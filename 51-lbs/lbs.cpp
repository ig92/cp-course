#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

int lis(vector<int> numbers, vector<int> * M, int n) {
    if (n == 0) {
        return 0;
    }

    int m = -1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (numbers[j] < numbers[i]) {
                M->at(i) = max(M->at(i), 1 + M->at(j));
            }
        }
        m = max(m, M->at(i));
    }

    return m;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);

        vector<int> inc (n,1);
        lis(numbers, &inc, n);

        reverse(numbers.begin(), numbers.end());
        
        vector<int> dec (n,1);
        lis(numbers, &dec, n);

        int max = -1;
        for (int i = 0; i < n; ++i) 
            if (max < inc[i]+dec[n-i-1]-1)
                max = inc[i]+dec[n-i-1]-1;
            
        cout << max << endl;
    }
    return 0;
}

