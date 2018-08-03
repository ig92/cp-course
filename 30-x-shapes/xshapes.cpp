#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define WHITE 0
#define BLACK 2

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Node {
    int i;
    int j;
    int color;
};

void dfs(int i, vector<Node> * nodes, int m, int n) {
    nodes->at(i).color = BLACK;

    vector<int> neighbors;
    if (i - m > 0)
        neighbors.push_back(i-m);
    if (i + m < m * n)
        neighbors.push_back(i+m);
    if (i % m > 0)
        neighbors.push_back(i-1);
    if (i % m < m-1)
        neighbors.push_back(i+1);
    
    for (int j = 0; j < neighbors.size(); j++) {
        int k = neighbors[j];
        if (nodes->at(k).color == WHITE) {
            dfs(k, nodes, m, n);
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0) {
        int n, m;
        cin >> n >> m;

        vector<Node> nodes(m * n);
        for (int i = 0; i < n; i++) {
            vector<char> line = get_input_sequence<char>(m);
            for (int j = 0; j < m; j++) {
                nodes[i*m+j].i = i;
                nodes[i*m+j].j = j;
                nodes[i*m+j].color = (line[j] == 'O') ? BLACK : WHITE;
            }
        }

        int counter = 0;

        for (int i = 0; i < n * m; i++) {
            if (nodes[i].color == WHITE) {
                dfs(i, &nodes, m, n);
                counter++;
            }
        }

        cout << counter << endl;
    }

    return 0;
}