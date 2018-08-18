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
 
int isPreorder(vector<int> numbers, int n) {
    stack<int> s;
    int root = 0;
 
    for (int i = 0; i < n; ++i) {
        if (numbers[i] < root)
            return 0;
 
        while (!s.empty() && s.top() < numbers[i]) {
            root = s.top();
            s.pop();
        }

        s.push(numbers[i]);
    }

    return 1;
}
 
int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);

        cout << isPreorder(numbers, n) << endl;
    }
    return 0;
}