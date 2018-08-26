#include <iostream>
#include <vector>
#include <deque>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

deque<int> q;
int maximum = -1;

void updateQueue(vector<int> * numbers, int i) {
    if (q.empty()) {
        q.push_front(i);
    }
    if (numbers->at(i) >= numbers->at(q.front())) {
        q.clear();
        q.push_front(i);
        maximum = i;
    } else {
        while (!q.empty() && (numbers->at(i) >= numbers->at(q.back())))
            q.pop_back();
        q.push_back(i);
        maximum = q.front();
    }
}

void print_k_maximums(vector<int> * numbers, int n, int k) {
    q.clear();

    // O(k)
    for (int i = 0; i < k; ++i)
        updateQueue(numbers, i);
    cout << numbers->at(maximum) << " ";

    // O(n-k)
    for (int i = k; i < n; ++i) {
        // if the max is no more in the window
        if (((i - k) + 1) > maximum)
            q.pop_front();
        updateQueue(numbers, i);
        cout << numbers->at(maximum) << " ";
    }
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, k;
        cin >> n >> k;

        vector<int> numbers = get_input_sequence<int>(n);
        
        print_k_maximums(&numbers, n, k);
    }

    return 0;
}