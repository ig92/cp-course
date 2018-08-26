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

uint64_t count_inversions(vector<int> * numbers, uint64_t lb, uint64_t ub) {
    // base case
    if (ub - lb + 1 < 2)
        return 0;

    // divide
    uint64_t m = (ub + lb) / 2;
    uint64_t lftCount = count_inversions(numbers, lb, m);
    uint64_t rgtCount = count_inversions(numbers, m + 1, ub);

    // conquer
    uint64_t mrgCount = 0;
    vector<int> tmp (ub-lb+1);

    int u = m + 1;
    int l = lb;
    int i = 0;
    while (l <= m && u <= ub) {
        if ((*numbers)[l] > (*numbers)[u])
            tmp[i++] = (*numbers)[u++];
        else {
            tmp[i++] = (*numbers)[l++];
            mrgCount += u-1-m;
        }
    }

    // count the rest if any
    while (l <= m) {
        tmp[i++] = (*numbers)[l++];
        mrgCount += ub-m;
    }

    // copy the rest
    while (u <= ub)
        tmp[i++] = (*numbers)[u++];

    // copy back to numbers
    for (int i = lb; i <= ub; ++i)
        (*numbers)[i] = tmp[i-lb];

    return lftCount + rgtCount + mrgCount;
}

int main(int argc, char const *argv[])
{
    std::ios_base::sync_with_stdio(false);

    uint64_t t;
    cin >> t;

    while (t-- > 0) {
        uint64_t n;
        cin >> n;
        vector<int> numbers = get_input_sequence<int>(n);
        cout << count_inversions(&numbers, 0, n-1) << endl;
    }
    
    return 0;
}
