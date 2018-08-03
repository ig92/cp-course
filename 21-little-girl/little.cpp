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

    int n, q;
    cin >> n >> q;

    vector<int> numbers = get_input_sequence<int>(n);

    sort(numbers.begin(), numbers.end(), [](int a, int b) {return a > b;});

    vector<int64_t> freqs (n);
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        freqs[l-1]++;
        if (r < n)
            freqs[r]--;
    }

    for (int i = 1; i < n; ++i) {
        freqs[i] += freqs[i-1];
    }

    sort(freqs.begin(), freqs.end(), [](int a, int b) {return a > b;});

    uint64_t sum = 0;
    for (int i = 0; i < freqs.size(); ++i) {
        if (freqs[i] == 0) {
            break;
        }

        sum += freqs[i] * numbers[i];
    }

    cout << sum << endl;

    return 0;
}