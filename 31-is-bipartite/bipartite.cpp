#include <iostream>
#include <vector>
#include <algorithm>

#define NO_COLOR 0
#define WHITE 1
#define BLACK 2

using namespace std;

int color_tree(int i, int current_color, int next_color, vector<int> nodes, int g[15][15], int n) {
    nodes[i] = current_color;
    for (int j = 0; j < n; j++) {
        if (g[i][j] == 1) {
            if (nodes[j] == NO_COLOR) {
                if (!color_tree(j, next_color, current_color, nodes, g, n)) {
                    return false;
                }
            }
            if (nodes[j] == current_color) {
                return false;
            }
        }
    }

    return true;
}

int is_bipartite(int g[15][15], int n) {
    vector<int> nodes (n);

    for (int i = 0; i < n; i++) {
        if (nodes[i] == NO_COLOR) {
            if (!color_tree(i, WHITE, BLACK, nodes, g, n)) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int t;
    cin >> t;

    while (0 < t--) {
        int n;
        cin >> n;

        int g[15][15];
        memset(g,0,sizeof(g));

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> g[i][j];

        cout << is_bipartite(g, n) << endl;
    }

    return 0;
}