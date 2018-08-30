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

int lis(vector<int> numbers, int n) {
    if (n == 0)
        return 0;

    vector<int> M (n,1);

    int m = -1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j)
            if (numbers[j] < numbers[i])
                M[i] = max(M[i], 1 + M[j]);
        m = max(m, M[i]);
    }

    return m;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;
        vector<int> numbers = get_input_sequence<int>(n);
        cout << lis(numbers, n) << endl;
    }
    
    return 0;
}