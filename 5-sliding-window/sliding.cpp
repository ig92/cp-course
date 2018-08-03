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

void k_maximums(vector<int> numbers, int k) {
    deque <int> q;

    int max = -1;
    q.push_front(0);

    for (int i = 0; i < k; ++i) {
        if (numbers[i] >= numbers[q.front()]) {
            q.clear();
            q.push_front(i);
            max = i;
        } else {
            while (!q.empty() && (numbers[i] >= numbers[q.back()])) {
                q.pop_back();
            }
            q.push_back(i);
        }
    }
    
    cout << numbers[max] << " ";

    for (int i = k; i < numbers.size(); ++i) {
        // if the max is no more in the window
        if (((i - k) + 1) > max) {
            q.pop_front();
            max = q.front();
        }
        
        if (q.empty()) {
            q.push_back(i);
            max = i;
        } else {
            if (numbers[i] >= numbers[q.front()]) {
                q.clear();
                q.push_front(i);
                max = i;
            } else {
                while (!q.empty() && (numbers[i] >= numbers[q.back()])) {
                    q.pop_back();
                }
                q.push_back(i);
            }
        }

        cout << numbers[max] << " ";
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int c;
    cin >> c;

    // read input data
    for (int i = 0; i < c; ++i) {
        // dimension of the next array
        int n, k;
        cin >> n >> k;

        vector<int> numbers = get_input_sequence<int>(n);
        
        k_maximums(numbers, k);
        
        cout << endl;
    }

    return 0;
}