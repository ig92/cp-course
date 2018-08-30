#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>

#define lft(i) (2*i+1)
#define rgt(i) (2*i+2)
#define par(i) ((i-1)/2)

using namespace std;

uint64_t n;
int64_t seg_tree[550000];
int64_t lazy[550000];

void build(vector<int64_t> * array, uint64_t low, uint64_t high, uint64_t pos) {
    if (low == high) {
        seg_tree[pos] = array->at(low);
        lazy[pos] = 0;
        return;
    }

    uint64_t mid = (low + high) / 2;
    build(array, low, mid, lft(pos));
    build(array, mid+1, high, rgt(pos));

    seg_tree[pos] = min(seg_tree[lft(pos)], seg_tree[rgt(pos)]);
    lazy[pos] = 0;
}

int64_t rec_rmq(uint64_t qlow, uint64_t qhigh, uint64_t low, uint64_t high, uint64_t pos) {
    if (lazy[pos] != 0) {
        seg_tree[pos] += lazy[pos];
        if (low != high) {
            lazy[lft(pos)] += lazy[pos];
            lazy[rgt(pos)] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    // total overlap
    if (qlow <= low && qhigh >= high)
        return seg_tree[pos];
    
    // no overlap
    if (qlow > high || qhigh < low)
        return INT_MAX;
    
    uint64_t mid = (low + high) / 2;

    return min(
        rec_rmq(qlow, qhigh, low, mid, lft(pos)),
        rec_rmq(qlow, qhigh, mid+1, high, rgt(pos))
    );
}

void rec_inc(uint64_t qlow, uint64_t qhigh, uint64_t low, uint64_t high, uint64_t pos, int64_t qty) {
    if (lazy[pos] != 0) {
        seg_tree[pos] += lazy[pos];
        if (low != high) {
            lazy[lft(pos)] += lazy[pos];
            lazy[rgt(pos)] += lazy[pos];
        }
        lazy[pos] = 0;
    }

    // total overlap
    if (qlow <= low && qhigh >= high) {
        seg_tree[pos] += qty;
        if (low != high) {
            lazy[lft(pos)] += qty;
            lazy[rgt(pos)] += qty;
        }
        return;
    }
    
    // no overlap
    if (qlow > high || qhigh < low)
        return;
    
    uint64_t mid = (low + high) / 2;

    rec_inc(qlow, qhigh, low, mid, lft(pos), qty);
    rec_inc(qlow, qhigh, mid+1, high, rgt(pos), qty);

    seg_tree[pos] = min(seg_tree[lft(pos)], seg_tree[rgt(pos)]);
}

void inc(uint64_t i, uint64_t j, int64_t qty) {
    if (i <= j) {
        rec_inc(i, j, 0, n-1, 0, qty);
    } else {
        // two ranges
        rec_inc(i, n-1, 0, n-1, 0, qty);
        rec_inc(0, j, 0, n-1, 0, qty);
    }
}

int64_t rmq(uint64_t i, uint64_t j) {
    if (i <= j)
        return rec_rmq(i, j, 0, n-1, 0);
    return min(
        rec_rmq(i, n-1, 0, n-1, 0),
        rec_rmq(0, j, 0, n-1, 0)
    );
}

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    cin >> n;

    vector<int64_t> numbers = get_input_sequence<int64_t>(n);

    build(&numbers, 0, n-1, 0);

    int m;
    cin >> m;
    cin.ignore();
    
    for (int i = 0; i < m; ++i) {
        vector<int> numbers (3);
        
        // line
        string line;
        getline(cin, line);
        stringstream ss (line);
        
        // take numbers
        int n = 0;
        string number;
        while (getline(ss, number, ' '))
            numbers[n++] = stoi(number);
        
        // execute opearation
        if (n == 2) {
            // query
            cout << rmq(numbers[0], numbers[1]) << endl;
        } else {
            // update
            inc(numbers[0], numbers[1], numbers[2]);
        }
    }

}