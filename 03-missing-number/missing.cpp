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

        vector<int> vect = get_input_sequence<int>(n-1);

        int gauss = (n * n + n) >> 1;

        for (int i = 0; i < n-1; ++i)
            gauss -= vect.at(i);
        
        cout << gauss << endl;
    }

    return 0;
}