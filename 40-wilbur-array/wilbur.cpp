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

int main() {
    std::ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;

    vector<int> numbers = get_input_sequence<int>(n);

    uint64_t counter = 0;
    int64_t acc = 0;
    for (int i = 0; i < n; ++i) {
        counter += abs(numbers[i]-acc);
        acc += numbers[i]-acc;
    }

    cout << counter << endl;

    return 0;
}