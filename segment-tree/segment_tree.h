#include <vector>
#include <iostream>
#include <math.h>

#define lft(i) (2*i+1)
#define rgt(i) (2*i+2)
#define par(i) ((i-1)/2)

using namespace std;


class SegmentTree {
public:
    SegmentTree(uint64_t n) {
        // nearest greater or equal power of two
        size = pow(2, ceil(log2(n))) * 2 - 1;
        seg_tree = new int64_t[size];
        for (int i = 0; i < size; ++i)
            seg_tree[i] = 0;
    }

    ~SegmentTree() {
        delete [] seg_tree;
    }

    void increment(uint64_t pos) {
        pos += (size + 1 / 2) - 1;
        while (pos >= 0) {
            seg_tree[pos]++;
            pos = par(pos);
        }
    }

    uint64_t count(uint64_t i) {
        return rec_count(0, i, 0, n-1, 0);
    }

private:
    uint64_t size;
    uint64_t n;
    int64_t * seg_tree;

    uint64_t rec_count(uint64_t qlow, uint64_t qhigh, uint64_t low, uint64_t high, uint64_t pos) {
        // total overlap
        if (qlow <= low && qhigh >= high)
            return seg_tree[pos];
        
        // no overlap
        if (qlow > high || qhigh < low)
            return 0;
        
        uint64_t mid = (low + high) / 2;

        return rec_count(qlow, qhigh, low, mid, lft(pos)) + rec_count(qlow, qhigh, mid+1, high, rgt(pos));
    }
};