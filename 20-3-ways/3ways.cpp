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

    int n;
    cin >> n;

    vector<int64_t> numbers = get_input_sequence<int64_t>(n);

    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += numbers[i];
    }

    if (n < 3 || sum % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    sum = sum / 3;

    // compute number of suffixes that sum to target value
    vector<int64_t> n_suffs (n);
    int64_t acc = 0;
    uint64_t counter = 0;
    for (int i = n-1; i > -1; --i) {
        n_suffs[i] = (numbers[i] + acc == sum) ? ++counter : counter;
        acc += numbers[i];
    }

    // computer the three ways
    acc = 0;
    counter = 0;
    for (int i = 0; i < n-2; ++i) {
        counter = (numbers[i] + acc == sum) ? n_suffs[i+2]+counter : counter;
        acc += numbers[i];
    }   

    cout << counter << endl;

    return 0;
}