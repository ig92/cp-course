#include <iostream>
#include <vector>
#include <algorithm>

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
    int i;
    int j;
    bool visited;
    vector<Node*> children;
};

Node nodes[100000];
int n;
int start = 0;

void traverse(Node * root) {
    if (root->visited)
        return;

    root->visited = true;
    root->i = start++;
    for (int i = 0; i < root->children.size(); ++i)
        traverse(root->children[i]);
    root->j = start-1;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int m;
    cin >> n >> m;

    // read colors
    vector<int> colors = get_input_sequence<int>(n);
    for (int i = 0; i < n; i++) {
        nodes[i].color = colors[i];
        nodes[i].id = i+1;
        nodes[i].visited = false;
    }
    
    // read edges
    for (int i = 0; i < n-1; ++i) {
        int u,v;
        cin >> u >> v;
        nodes[u-1].children.push_back(&nodes[v-1]);
        nodes[v-1].children.push_back(&nodes[u-1]);
    }

    traverse(&nodes[0]);

    sort(nodes, nodes+n, [](Node a, Node b) {return a.i < ;});

    return 0;
}