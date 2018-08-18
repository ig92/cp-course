#include <iostream>
#include <vector>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

int knapsack(vector<int> numbers, int c, int n) {
    short M [n+1][c+1];

    // init
    for (int i = 0; i <= c; ++i)
        M[0][i] = 0;
        
    for (int i = 0; i <= n; ++i)
        M[i][0] = 1;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (M[i-1][j] == 1) {
                M[i][j] = 1;
            }
            else {
                if (j >= numbers[i-1]) {
                    M[i][j] = M[i-1][j-numbers[i-1]];
                }
                else {
                    M[i][j] = 0;
                }
            }
        }
    }
            // M[i][j] = M[i-1][j] || M[i-1][j-numbers[i-1]];

    return M[n][c];
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);

        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += numbers[i];

        if (sum % 2 != 0) {
            cout << "NO" << endl;
            continue;
        }
        
        int target = sum / 2;

        if (knapsack(numbers, target, n) == 0)
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;

        
    }
    
    return 0;
}

