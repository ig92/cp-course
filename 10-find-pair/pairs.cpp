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

    uint64_t n, k;
    cin >> n;
    cin >> k;

    vector<int> numbers = get_input_sequence<int>(n);

    sort(numbers.begin(), numbers.end());

    uint64_t i = (k-1) / n;

    uint64_t l = 0;
    for (; l < n; l++)
        if (numbers[l] == numbers[i])
            break;
            
    uint64_t r = count(numbers.begin(), numbers.end(), numbers[i]);

    uint64_t j = ((k-1) - (l * n)) / r;

    cout << numbers[i] << " " << numbers[j] << endl;
}