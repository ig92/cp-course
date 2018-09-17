#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Number {
    int id;
    int value;
};

bool heap[201];

int main() {
    std::ios_base::sync_with_stdio(false);

    uint64_t n;
    cin >> n;

    vector<int> values = get_input_sequence<int>(2 * n);
    vector<Number> numbers (2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        Number number;
        number.value = values[i];
        number.id = i;
        numbers[i] = number;
    }

    // sort according to numbers values
    sort(numbers.begin(), numbers.end(), [](Number a, Number b) {return a.value < b.value;});
    
    // first heap assignment
    int c1 = 1;
    int c2 = 1;
    queue<int> repeated;
    int heapID = false;
    heap[numbers[0].id] = false;
    heap[numbers[1].id] = true;
    for (int i = 2; i < 2 * n; ++i) {
        if (numbers[i].value == numbers[i-2].value) {
            repeated.push(numbers[i].id);
            continue;
        }
        if (heapID)
            c1++;
        else
            c2++;
        heap[numbers[i].id] = heapID;
        heapID = !heapID;
    }

    cout << c1 * c2 << endl;

    // second heap assignment
    while (!repeated.empty()) {
        heap[repeated.front()] = heapID;
        heapID = !heapID;
        repeated.pop();
    }

    for (int i = 0; i < 2 * n; ++i)
        cout << (heap[i] ? 2 : 1) << " ";
    cout << endl;
}