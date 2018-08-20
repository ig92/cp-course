#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

class BIT {
public:
    BIT(uint64_t _size) {
        if (_size < 1)
            _size = 10;
        size = _size + 1;
        A = new uint64_t[size];
        fill_n(A, size, 0);
    }

    ~BIT() {
        delete [] A;
    }
 
    void add(uint64_t i, uint64_t qty) {
        if (i < 1 || i >= size)
            return;
        while (i < size) {
            A[i] += qty;
            i += i & (-i);
        }
    }

    uint64_t sum(uint64_t i) {
        if (i < 1 || i >= size)
            return 0;
        uint64_t sum = 0;
        while (i > 0) {
            sum += A[i];
            i -= i & (-i);
        }
        return sum;
    }
private:
    uint64_t size;
    uint64_t * A;
};

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
    
    unordered_map<int,int> leftmap;
    vector<int> left (n);
    for (int i = 0; i < n; ++i) {
        leftmap[numbers[i]]++;
        left[i] = leftmap[numbers[i]];
    }

    unordered_map<int,int> rightmap;
    vector<int> right (n);
    for (int i = n-1; i > -1; --i) {
        rightmap[numbers[i]]++;
        right[i] = rightmap[numbers[i]];
    }
    
    int max = -1;
    for (int i = 0; i < n; ++i) {
        if (max < left[i])
            max = left[i];
        if (max < right[i])
            max = right[i];
    }

    BIT bit (max);

    uint64_t counter = 0;

    for (int i = n-1; i > -1; --i) {
        bit.add(right[i], 1);
        counter += bit.sum(left[i-1]-1);
    }

    cout << counter << endl;

    return 0;
}