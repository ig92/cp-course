#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int infront;
    int height;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    // read input data
    int n;
    cin >> n;
    vector<Person> people (n);
    for (int i = 0; i < n; ++i)
        cin >> people[i].name >> people[i].infront;
        
    // sort
    sort(people.begin(), people.end(), [](Person a, Person b) {return a.infront < b.infront;});

    // check if impossible
    for (int i = 0; i < n; ++i) {
        if (i < people[i].infront) {
            cout << "-1" << endl;
            return 0;
        }
    }

    // restore the original order
    vector<int> h (n);
    for (int i = 0; i < n; ++i)
        h.insert(h.begin() + i - people[i].infront, i);

    // assign heights
    for (int i = 0; i < n; ++i)
        people[h[i]].height = i + 1; // height must be > 0

    // print
    for (int i = 0; i < n; ++i)
        cout << people[i].name << " " << people[i].height << endl;

    return 0;
}

