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

int knapsack(vector<int> wgt, vector<int> val, int n, int w) {
    int M [n+1][w+1];

    // init
    for (int i = 0; i <= n; ++i)
        M[i][0] = 0;
    for (int i = 0; i <= w; ++i)
        M[0][i] = 0;

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= w; ++j)
            M[i][j] = (wgt[i-1] <= j) ? max(M[i-1][j-wgt[i-1]] + val[i-1], M[i-1][j]) : M[i-1][j];

    return M[n][w];
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, w;
        cin >> n >> w;

        vector<int> val = get_input_sequence<int>(n);
        vector<int> wgt = get_input_sequence<int>(n);

        cout << knapsack(wgt,val,n,w) << endl;
    }
    return 0;
}

