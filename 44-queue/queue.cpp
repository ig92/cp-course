#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define LEFT 0
#define RIGHT 1

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Person {
    string name;
    int infront;
    int height;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Person> people (n);
    vector<int> queue (n);
    for (int i = 0; i < n; ++i) {
        string name;
        int infront;
        cin >> name >> infront;

        people[i].name = name;
        people[i].infront = infront;
    }

    sort(people.begin(), people.end(), [](Person a, Person b) {return a.infront < b.infront;});

    for (int i = 0; i < n; ++i) {
        if (i < people[i].infront) {
            cout << "-1" << endl;
            return 0;
        }
        cout << people[i].name << endl;
    }

    return 0;
}

