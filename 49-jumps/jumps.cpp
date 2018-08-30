#include <iostream>
#include <vector>

using namespace std;
#define MAX 101

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

int jumps(vector<int> * numbers, vector<int> * dp, int i, int n) {
    if (i >= n-1)
        return 0;

    if (numbers->at(i) == 0)
        return MAX;

    if (dp->at(i) != MAX)
        return dp->at(i);

    for (int j = 1; j <= numbers->at(i); ++j)
        dp->at(i) = min(dp->at(i), 1 + jumps(numbers, dp, i+j, n));

    return dp->at(i);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);
        vector<int> dp (n, MAX);

        int j = jumps(&numbers, &dp, 0, n);
        if (j == MAX)
            cout << -1 << endl;
        else 
            cout << j << endl;
    }
    return 0;
}

