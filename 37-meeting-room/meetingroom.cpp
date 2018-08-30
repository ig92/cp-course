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

struct Meeting {
    int s;
    int f;
    int index;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while(t-- > 0) {
        int n;
        cin >> n;

        vector<Meeting> meetings (n);
        vector<int> s = get_input_sequence<int>(n);
        vector<int> f = get_input_sequence<int>(n);

        for (int i = 0; i < n; i++) {
            meetings[i].s = s[i];
            meetings[i].f = f[i];
            meetings[i].index = i+1;
        }

        sort(meetings.begin(), meetings.end(), [](Meeting a, Meeting b) {return a.f < b.f;});

        cout << meetings[0].index << " ";

        for (int i = 1, last = 0; i < n; ++i) {
            if (meetings[last].f < meetings[i].s) {
                cout << meetings[i].index <<  " ";
                last = i;
            }
        }

        cout << endl;
    }

    return 0;
}