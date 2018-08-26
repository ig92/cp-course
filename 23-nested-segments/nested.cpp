#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int64_t id;
    int64_t i;
    int64_t j;
};

int A [200000];
int SIZE;
int answer[200000];

void add(int64_t i, int64_t qty) {
    if (i < 1 || i >= SIZE)
        return;
    while (i < SIZE) {
        A[i] += qty;
        i += i & (-i);
    }
}

int64_t sum(int64_t i) {
    if (i < 1 || i >= SIZE)
        return 0;
    int64_t sum = 0;
    while (i > 0) {
        sum += A[i];
        i -= i & (-i);
    }
    return sum;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int64_t n;
    cin >> n;

    vector<Segment> segments (n);
    for (int64_t id = 0; id < n; ++id) {
        segments[id].id = id;
        cin >> segments[id].i >> segments[id].j;
    }

    // make all ends positive so we can use it in BIT O(nlogn)
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.j < b.j;});
    for (int i = 0; i < n; ++i)
        segments[i].j = i+1;

    // sort according to starts in descending order
    sort(segments.begin(), segments.end(), [](Segment a, Segment b) {return a.i > b.i;});

    SIZE = n + 1;

    for (int64_t i = 0; i < n; ++i) {
        Segment * s = &segments[i];
        answer[segments[i].id]= sum(s->j);
        add(s->j, 1);
    }

    for (int64_t i = 0; i < n; ++i)
        cout << answer[i] << endl;

    return 0;
}