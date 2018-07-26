#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

// To compare two points
struct City {
    double distance = 0;
    uint64_t population = 0;
};

class myComparator {
public:
    int operator() (City a, City b) {
        return a.distance > b.distance;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);

    uint64_t n, s;
    cin >> n;
    cin >> s;

    // get cities
    priority_queue <City, vector<City>, myComparator> pq;
    for (auto i = 0; i < n; ++i) {
        auto data = get_input_sequence<int>(3);
        City c;
        c.distance = sqrt(pow(data[0],2) + pow(data[1],2));
        c.population = data[2];
        pq.push(c);
    }

    double radius = 0;
    while (!pq.empty() && s < 1000000) {
        City c = pq.top(); pq.pop();
        s += c.population;
        radius = c.distance;
    }

    cout.precision(8);
    if (s < 1000000) {
        cout << -1 << endl;
    } else {
        cout << radius << endl;
    }

    return 0;
}