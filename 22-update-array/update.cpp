#include <iostream>
#include <vector>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, u;
        cin >> n >> u;

        // process updates
        vector<int64_t> v (n);
        for (int j = 0; j < u; ++j) {
            int l, r, val;
            cin >> l >> r >> val;
            v[l] += val;
            if (r < n-1)
                v[r+1] -= val;
        }

        // inclusive prefix sum
        for (int j = 1; j < n; ++j)
            v[j] += v[j-1];

        // process queries
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