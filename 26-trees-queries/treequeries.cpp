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

#define MAX 100001

int table[MAX];
int particularColor[MAX];
int counter[MAX];

struct Query {
    int id;
    int i;
    int j;
    int k;
};

struct Node {
    int id;
    int color;
    int i;
    int j;
    bool visited;
    vector<Node*> children;
};

Node nodes[MAX];
int start = 0;
int s[MAX];

void traverse(Node * root) {
    if (root->visited)
        return;

    root->visited = true;
    root->i = start++;
    s[root->i] = root->id;
    for (int i = 0; i < root->children.size(); ++i)
        traverse(root->children[i]);
    root->j = start-1;
}

void add(int i) {
    int color = nodes[s[i]].color;
    particularColor[color]++;
    counter[particularColor[color]]++;
}

void remove(int i) {
    int color = nodes[s[i]].color;
    counter[particularColor[color]]--;
    particularColor[color]--;
}

int main() {
    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    // read colors
    vector<int> colors = get_input_sequence<int>(n);
    for (int i = 0; i < n; i++) {
        nodes[i].color = colors[i];
        nodes[i].id = i;
        nodes[i].visited = false;
    }
    
    // read edges
    for (int i = 0; i < n-1; ++i) {
        int u, v;
        cin >> u >> v;
        nodes[u-1].children.push_back(&nodes[v-1]);
        nodes[v-1].children.push_back(&nodes[u-1]);
    }

    traverse(&nodes[0]);

    // read queries
    vector<Query> queries(m);
    for (int i = 0; i < m; ++i) {
        int node;
        cin >> node >> queries[i].k;
        queries[i].id = i;
        queries[i].i = nodes[node-1].i;
        queries[i].j = nodes[node-1].j;
    }

    // mo's order
    int p = sqrt(n);
    sort(queries.begin(), queries.end(), [p](Query a, Query b) {
        if (a.i / p == b.i / p) 
            return a.j < b.j;
        return a.i < b.i;
    });

    int current_i = 0;
    int current_j = 0;
    
    add(0);

    int answer[m];
    for (int i = 0; i < m; ++i) {
        Query q = queries[i];
        while (current_i < q.i) {
            remove(current_i++);
        }
        while (current_i > q.i) {
            add(--current_i);
        }
        while (current_j < q.j) {
            add(++current_j);
        }
        while (current_j > q.j) {
            remove(current_j--);
        }
        answer[q.id] = counter[q.k];
    }

    for (int i = 0; i < m; ++i)
        cout << answer[i] << endl;

    return 0;
}