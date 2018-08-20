#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#define lft(i) (2*i+1)
#define rgt(i) (2*i+2)
#define par(i) ((i-1)/2)

using namespace std;

class SegmentTree {
public:
    SegmentTree(uint64_t _n) {
        // nearest greater or equal power of two
        size = pow(2, ceil(log2(_n))) * 2 - 1;
        seg_tree = new int64_t[size];
        for (int i = 0; i < size; ++i)
            seg_tree[i] = 0;
        n = _n;
    }

    ~SegmentTree() {
        delete [] seg_tree;
    }

    void increment(uint64_t pos) {
        pos += ((size + 1) / 2) - 1;
        while (1) {
            seg_tree[pos]++;
            if (pos == 0) {
                break;
            }
            pos = par(pos);
        }
    }

    uint64_t count(uint64_t i) {
        return rec_count(0, i, 0, ((size+1) / 2) - 1, 0);
    }

    void print() {
        for (int i = 0; i < size; ++i)
            cout << seg_tree[i] << " ";
        cout << endl;
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

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Segment {
    int64_t id;
    int64_t i;
    int64_t j;
    int64_t includes;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;

    vector<Segment> segments (n);
    for (int64_t id = 0; id < n; ++id) {
        segments[id].id = id;
        cin >> segments[id].i >> segments[id].j;
        segments[id].includes = 0;
    }

    // make all ends positive so we can use it in BIT O(nlogn)
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.j < b.j;});
    for (int i = 0; i < n; ++i)
        segments[i].j = i;

    // sort according to starts in descending order
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.i > b.i;});

    SegmentTree segment_tree (n);

    for (int64_t i = 0; i < n; ++i) {
        Segment * s = &segments[i];
        s->includes = segment_tree.count(s->j);
        segment_tree.increment(s->j);
    }

    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.id < b.id;});

    for (int64_t i = 0; i < n; ++i)
        cout << segments[i].includes << endl;

    return 0;
}