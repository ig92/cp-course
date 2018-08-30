#include <iostream>
#include <vector>
#include <algorithm>

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
    
    // assign heap
    int heapID = false;
    for (int i = 0; i < 2 * n; ++i) {
        heap[numbers[i].id] = heapID;
        heapID = !heapID;
    }

    // counting
    int c1 = 1;
    int c2 = 1;
    for (int i = 2; i < 2 * n; ++i) {
        if (numbers[i].value != numbers[i-2].value) {
            // then count
            if (i % 2 == 0)
                c1++;
            else
                c2++;
        }
    }

    cout << c1 * c2 << endl;
    for (int i = 0; i < 2 * n; ++i)
        cout << (heap[i] ? 2 : 1) << " ";
    cout << endl;
}