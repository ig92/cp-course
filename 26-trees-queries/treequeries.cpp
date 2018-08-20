#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define WHITE 1
#define BLACK 2

using namespace std;

template<typename T>
vector<T> get_input_sequence(size_t n) {
    vector<T> sequence(n);

    for(size_t i = 0; i < n; ++i) 
        cin >> sequence[i];
    return sequence;
}

struct Node {
    int id;
    int color;
    unordered_map<int,int> u;
    int size;
    int dfs;
    vector<Node*> children;
};

// costs O(nlogn)
void init_maps(Node * root) {
    root->dfs = BLACK;
    if (root->children.size() == 0) {
        root->u[root->color] = 1;
        root->size = 1;
        return;
    }

    root->u[root->color] = 1;
    for (Node * child : root->children) {
        if (child->dfs == WHITE) {
            init_maps(child);
            for (auto & pair : child->u) {
                if (root->u.find(pair.first) == root->u.end()) {
                    root->u[pair.first] = pair.second;
                } else {
                    root->u[pair.first] += pair.second;
                }
            }
            root->size += child->size;
        }
    }

    root->size += 1;
}

int at_least(int k, Node * root) {
    uint64_t counter = 0;
    for (auto & pair : root->u) {
        if (pair.second >= k)
            counter++;
    }
    return counter;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    // read colors
    vector<Node> nodes (n);
    vector<int> colors = get_input_sequence<int>(n);
    for (int i = 0; i < n; i++) {
        nodes[i].color = colors[i];
        nodes[i].id = i+1;
        nodes[i].dfs = WHITE;
    }
    
    // read edges
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        nodes[u-1].children.push_back(&nodes[v-1]);
        nodes[v-1].children.push_back(&nodes[u-1]);
    }

    // compute maps
    init_maps(&nodes[0]);

    for (int i = 0; i < m; ++i) {
        int v,k;
        cin >> v >> k;

        cout << at_least(k, &nodes[v-1]) << endl;
    }

    return 0;
}