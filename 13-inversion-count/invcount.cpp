#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

uint64_t count_inversions(vector<int> numbers, uint64_t i, uint64_t j) {
    // base case 1
    if (j - i < 2) {
        return 0;
    }

    // base case 2
    if (j - i == 2) {
        return numbers[i] > numbers[j] ? 1 : 0;
    }

    // divide
    uint64_t m = (j + i) / 2;
    uint64_t lftCount = count_inversions(numbers, i, m);
    uint64_t rgtCount = count_inversions(numbers, m + 1, j);

    // conquer
    uint64_t mrgCount = 0;
    

    return lftCount + rgtCount + mrgCount;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);

    uint64_t t, n;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        cin >> n;
        vector<int> numbers = get_input_sequence<int>(n);
        cout << count_inversions(numbers, 0, n) << endl;
        cout << numbers[0] << endl;
    }
    
    return 0;
}
