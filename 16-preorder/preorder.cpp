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
 
int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);

        stack<int> s;
        int root = 0;
    
        int i = 0;
        for (; i < n; ++i) {
            if (numbers[i] < root)
                break;
    
            while (!s.empty() && s.top() < numbers[i]) {
                root = s.top();
                s.pop();
            }

            s.push(numbers[i]);
        }

        cout << ((i == n) ? 1 : 0) << endl;
    }
    
    return 0;
}