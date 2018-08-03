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

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << "1 0" << endl;
        return 0;
    }

    vector<int> a = get_input_sequence<int>(n);

    int i = 0;
    int j = n-1;
    
    int alice = 1;
    int bob = 1;

    while (j - i > 1) {
        if (a[i] > a[j]) {
            a[i] -= a[j--];
            bob++;
            continue;
        }

        if (a[j] > a[i]) {
            a[j] -= a[i++];
            alice++;
            continue;
        }

        i++;
        j--;

        // gentlment step
        if (i < j)
            bob++;
        alice++;
    }

    cout << alice << " " << bob << endl;

    return 0;
}