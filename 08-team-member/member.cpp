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

void member(vector<int> numbers) {
    vector<int> height (1001);

    for (int i = 0; i < numbers.size(); ++i) {
        height[numbers[i]]++;
    }
 
 
    int maxHeight = 0;
    int counter = 0;
    for (int i = 0; i < 1001; ++i) {
        if (height[i] > maxHeight) {
            maxHeight = height[i];
        }

        if (height[i] > 0) {
            counter++;
        }
    }

    cout << maxHeight << " " << counter << endl;
}

struct Pair {
    int strength;
    int i;
    int j;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Pair> pairs;

    for (int i = 2; i <= 2*n; ++i) {
        vector<int> numbers = get_input_sequence<int>(i-1);
        for (int j = 1; j <= i-1; ++j) {
            Pair p;
            p.i = i;
            p.j = j;
            p.strength = numbers[j-1];
            pairs.push_back(p);
        }
    }
    
    sort(pairs.begin(), pairs.end(), [](Pair a, Pair b) {return a.strength > b.strength;});

    vector<int> members;
    for (int i = 0; i < 2 * n; ++i) {
        members.push_back(0);
    }

    vector<Pair> teams;

    for (int i = 0; i < pairs.size(); ++i) {
        Pair p = pairs[i];
        if (members[p.i-1] == 0 && members[p.j-1] == 0) {
            members[p.i-1] = p.j;
            members[p.j-1] = p.i;
            teams.push_back(p);
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        cout << members[i] << " ";
    }
    cout << endl;

    return 0;
}