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

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);
        
        int current = numbers[0]; 
        int best = numbers[0];
        for (int j = 1; j < n; ++j) {
            current = max(numbers[j], numbers[j] + current);
            best = max(best, current);
        }

        cout << best << endl;
    }
}