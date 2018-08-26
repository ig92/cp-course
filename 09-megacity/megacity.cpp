#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct City {
    double distance = 0;
    int population = 0;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, s;
    cin >> n;
    cin >> s;

    // get cities
    vector<City> cities (n);
    for (int i = 0; i < n; ++i) {
        vector<int> data = get_input_sequence<int>(3);
        cities[i].distance = sqrt(pow(data[0],2) + pow(data[1],2));
        cities[i].population = data[2];
    }

    sort(cities.begin(), cities.end(), [](City a, City b) {return a.distance <= b.distance;});

    double radius = 0;
    for (int i = 0; i < n; ++i) {
        if (s >= 1000000)
            break;
        radius = cities[i].distance;
        s += cities[i].population;
    }

    cout.precision(8);
    if (s < 1000000) {
        cout << -1 << endl;
    } else {
        cout << radius << endl;
    }

    return 0;
}