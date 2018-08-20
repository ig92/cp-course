#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BIT {
public:
    BIT(int64_t _size) {
        if (_size < 1)
            _size = 10;
        size = _size + 1;
        A = new int[size];
        fill_n(A, size, 0);
    }

    ~BIT() {
        delete [] A;
    }

    void add(int64_t i, int64_t qty) {
        if (i < 1 || i >= size)
            return;
        while (i < size) {
            A[i] += qty;
            i += i & (-i);
        }
    }

    int64_t sum(int64_t i) {
        if (i < 1 || i >= size)
            return 0;
        int64_t sum = 0;
        while (i > 0) {
            sum += A[i];
            i -= i & (-i);
        }
        return sum;
    }
private:
    int64_t size;
    int * A;
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

    int64_t min = 2000000000, max = -2000000000;
    vector<Segment> segments (n);
    for (int64_t id = 0; id < n; ++id) {
        segments[id].id = id;
        cin >> segments[id].i >> segments[id].j;
        segments[id].includes = 0;

        if (min > segments[id].j) {
            min = segments[id].j;
        }

        if (max < segments[id].j) {
            max = segments[id].j;
        }
    }

    // make all ends positive so we can use it in BIT O(nlogn)
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.j < b.j;});
    for (int i = 0; i < n; ++i)
        segments[i].j = i+1;

    // sort according to starts in descending order
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.i > b.i;});

    BIT bit (n);

    for (int64_t i = 0; i < n; ++i) {
        Segment * s = &segments[i];
        s->includes = bit.sum(s->j);
        bit.add(s->j, 1);
    }

    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.id < b.id;});

    for (int64_t i = 0; i < n; ++i)
        // cout << segments[i].id << " from " << segments[i].i << " to " << segments[i].j << " has " << segments[i].includes << endl;
        cout << segments[i].includes << endl;

    return 0;
}