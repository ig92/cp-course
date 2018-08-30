#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    int infront;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<Person> people (n);
    for (int i = 0; i < n; ++i)
        cin >> people[i].name >> people[i].infront;

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

