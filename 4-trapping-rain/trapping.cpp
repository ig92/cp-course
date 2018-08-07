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

int counter(vector<int> numbers) {
    int to_count = 0;

    int i = 0;
    int j = 1;

    int n = numbers.size();

    if (n < 3) {
        return 0;
    }

    while (i < n && j < n) {
        int to_cut = 0;
        while (j < n && numbers[i] > numbers[j]) {
            to_cut += numbers[j++];
        }

        if (j == n) {
            vector<int> tmp (n-i);
            for (int k = tmp.size()-1; k > -1; --k)
                tmp[k] = numbers[n-k-1];
            to_count += counter(tmp);
            return to_count;
        }

        to_count += (j-i-1) * numbers[i] - to_cut;
        i = j++;
    }

    return to_count;
}

int main() {
    int t;
    cin >> t;

    while (t-- > 0) {
        int n;
        cin >> n;

        vector<int> numbers = get_input_sequence<int>(n);

        cout << counter(numbers) << endl;
    }

    return 0;
}