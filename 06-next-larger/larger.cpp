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

void next_larger(vector<int> numbers) {
    string out = "-1";
    stack<int> stack;
    stack.push(numbers[numbers.size()-1]);
    for (int i = numbers.size()-2; i > -1; --i) {
        while (!stack.empty() && numbers[i] >= stack.top())
            stack.pop();
        
        if (stack.empty()) {
            out = to_string(-1) + " " + out;
        } else {
            out = to_string(stack.top()) + " " + out;
        }

        stack.push(numbers[i]);
    }

    cout << out << endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int k;
    cin >> k;

    // read input data
    for (int i = 0; i < k; ++i) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);
        
        next_larger(numbers);
    }

    return 0;
}