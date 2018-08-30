#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define WHITE 0
#define BLACK 1

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

int G[100][100];

void dfs(int i, vector<int> * nodes) {
    if (nodes->at(i) == BLACK)
        return;
    
    nodes->at(i) = BLACK;

    for (int j = 0; j < nodes->size(); j++)
        if (G[i][j] == 1)
            dfs(j, nodes);
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<int> langs (m, -1);

    for (int i = 0; i < n; i++) {
        int nIthLangs;
        cin >> nIthLangs;

        vector<int> ithLangs = get_input_sequence<int>(nIthLangs);

        for (int j = 0; j < nIthLangs; j++) {
            // if i is the first one in order to speak this language
            if (langs[ithLangs[j]-1] == -1) {
                langs[ithLangs[j]-1] = i;
            } else {
                int k = langs[ithLangs[j]-1]; // who talks this language
                G[i][k] = G[k][i] = 1;
            }
        }
    }

    // special case when no one speak a language
    // langs is initialized with -1, that's why -m
    int sum = 0;
    for (int i = 0; i < m; i++)
        sum += langs[i];
    if (sum == -m) {
        cout << n << endl;
        return 0;
    }

    vector<int> vertices (n, WHITE);
    int counter = 0;
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i] == WHITE) {
            counter++;
            dfs(i, &vertices);
        }
    }

    cout << counter-1 << endl;
    return 0;
}