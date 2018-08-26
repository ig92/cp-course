#include <iostream>
#include <vector>
#include <stack>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

void print_next_larger(vector<int> * numbers, int n) {
    stack<int> stack;
    stack.push(numbers->at(n-1));
    numbers->at(n-1) = -1;
    for (int i = n - 2; i >= 0; --i) {
        while (!stack.empty() && numbers->at(i) >= stack.top())
            stack.pop();
        
        int elem = numbers->at(i);
        numbers->at(i) = stack.empty() ? -1 : stack.top();
        stack.push(elem);
    }

    for (int i = 0; i < n; ++i)
        cout << numbers->at(i) << " ";
    cout << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);
        
        print_next_larger(&numbers, n);
    }

    return 0;
}