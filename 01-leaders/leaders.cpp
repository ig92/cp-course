#include <iostream>
#include <vector>

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

        vector<int> vect = get_input_sequence<int>(n);

        int max = n-1;
        string leaders = to_string(vect[n-1]);
        for (int i = n-2; i >= 0; --i) {
            if (vect[i] > vect[max] == 1) {
                leaders = to_string(vect[i]) + " " + leaders;
                max = i;
            }
        }
        cout << leaders << endl;
    }

    return 0;
}