#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);

    string sequence;
    getline(cin, sequence);

    vector<int> v (sequence.length());
    
    for (int i = 0; i < sequence.length() - 1; ++i)
        v[i] = (sequence[i] == sequence[i+1]) ? 1 : 0;

    // exclusive prefix sum
    int tmp = v[0];
    v[0] = 0;
    for (int i = 1; i < sequence.length(); ++i) {
        int t = v[i];
        v[i] = v[i-1] + tmp;
        tmp = t;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int l, r;
        cin >> l;
        cin >> r;

        cout << v[r-1] - v[l-1] << endl;
    }

    return 0;
}