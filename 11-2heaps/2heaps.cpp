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

struct cube {
    int id;
    int heap;
    int value;
};

int main() {
    std::ios_base::sync_with_stdio(false);

    uint64_t n;
    cin >> n;

    auto cargos = get_input_sequence<int>(2 * n);
    vector<cube> cubes (2 * n);
    for (int i = 0; i < 2 * n; ++i) {
        cube cube;
        cube.value = cargos[i];
        cube.id = i;
        cubes[i] = cube;
    }

    // sort according to cubes values
    sort(cubes.begin(), cubes.end(), [](cube a, cube b) {return a.value < b.value;});

    // assign heap
    int heap = 1;
    int i = 0;
    while (i < 2 * n) {
        cubes[i].heap = heap;
        heap = heap % 2 + 1;
        i++;
    }

    // count
    int c = 2 * n;
    i = 1;
    while (i < 2 * n) {
        i++;
        while (i < 2 * n && cubes[i].value == cubes[i-2].value) {
            c--;
            i++;
        }
    }

    cout << (c/2) * (c-c/2) << endl; 

    sort(cubes.begin(), cubes.end(), [](cube a, cube b) {return a.id < b.id;});

    for (int i = 0; i < 2 * n; ++i) {
        cout << cubes[i].heap << " ";
    }
    cout << endl;

    return 0;
}