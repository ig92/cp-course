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

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, u;
        cin >> n >> u;

        vector<int64_t> v (n);

        for (int j = 0; j < u; ++j) {
            int l, r, val;
            cin >> l >> r >> val;

            v[l] += val;
            if (r < n-1)
                v[r+1] -= val;
        }

        for (int j = 0; j < n; ++j) {
            cout << v[j] << " ";
        }
        cout << endl;

        for (int j = 1; j < n; ++j) {
            v[j] += v[j-1];
        }

        int q;
        cin >> q;

        while (q-- > 0) {
            int j;
            cin >> j;
            cout << v[j] << " ";
        }
        cout << endl;
    }

    return 0;
}